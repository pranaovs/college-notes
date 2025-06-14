#!/usr/bin/env bash

# Script to easily generate lab record from raw code, algorithm.json and output.txt in respective subdirectories.

# Copyright (C) 2025 Pranaov S <pranaov@hotmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, version 3.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

# Nesting level required: 2
# Parent directory should contain all the topic.
# Subdirectories should contain the question name, and have $MAIN_CODE_FILENAME, algorithm.json, output.txt and any optional $CODE_EXTENSIONS codes.

DATE_FILENAME="date.txt"
QUESTION_FILENAME="question.txt"
ALGORITHM_FILENAME="algorithm.json"
AIM_FILENAME="aim.txt"
OUTPUT_FILENAME="output.txt"

output_file="$1"
parent_directory="$2"

# Required tools
REQUIRED_TOOLS=("jq" "fd" "sed" "tr" "basename" "dirname")

IFS=$'\n'

check_requirements() {

  local IFS=" "

  if [[ -z "$parent_directory" || -z "$output_file" ]]; then
    echo "Usage: $0 <parent_directory> <output_file>" >&2
    exit 1
  fi

  if [[ -z $MAIN_CODE_FILENAME ]]; then
    echo "ERROR: MAIN_CODE_FILENAME is not set. Please set it before running the script." >&2
    exit 1
  fi

  if [[ -z $EXCLUDED_PATTERNS ]]; then
    EXCLUDED_PATTERNS=()
  else
    readarray -t EXCLUDED_PATTERNS <<<"${EXCLUDED_PATTERNS}" #$EXCLUDED_PATTERNS is a string, so we need to convert it to an array
  fi

  excl_patterns=()
  for pattern in "${EXCLUDED_PATTERNS[@]}"; do
    excl_patterns+=("--exclude" "$pattern")
  done

  if [[ -z $CODE_EXTENSIONS ]]; then
    CODE_EXTENSIONS=()
  else
    readarray -t CODE_EXTENSIONS <<<"${CODE_EXTENSIONS}" #$CODE_EXTENSIONS is a string, so we need to convert it to an array
  fi

  code_exts=()
  for ext in "${CODE_EXTENSIONS[@]}"; do
    code_exts+=("--extension" "$ext")
  done

  local missing_tools=()
  for tool in "${REQUIRED_TOOLS[@]}"; do
    if ! command -v "$tool" &>/dev/null; then
      missing_tools+=("$tool")
    fi
  done

  if [ ${#missing_tools[@]} -ne 0 ]; then
    echo "ERROR: Required tools not found: ${missing_tools[*]}"
    echo "Install the missing tools and try again."
    if [[ " ${missing_tools[*]} " == *" fd "* ]]; then
      echo "fd installation steps: https://github.com/sharkdp/fd#installation"
    fi
    exit 1
  fi
}

if [[ -f "$output_file" ]]; then
  echo "$output_file file exists. Terminating"
  exit 1
fi

format_name() {
  # Remove directory path, leading digits/hyphen, and replace underscores
  # name=$(echo "$1" | sed "s/^[\.\/]*[0-9]*-//" | sed "s/_/ /g" | sed 's/\/$//')
  name=$(basename "$1" | sed 's/^[0-9]*-//; s/_/ /g; s/\/$//')
  echo "$name"
}

write() {
  if [[ "$#" -gt 0 ]]; then
    echo "$1" >>"$output_file"
  fi
  if [[ "$2" != "nonl" ]]; then
    echo >>"$output_file"
  fi
}

write_file() {
  tr -d '\r' <"$1" >>"$output_file"
}

# From Gemini 2.5 Pro
# Arg1: json data
# Arg2: Indentation string
process_steps() {
  local json_data="$1"
  local indent="${2:-}"
  local i=1 # Counter for the ordered list at this level
  local item step_text substeps_json next_indent

  # Check if input JSON data is empty or null before processing
  if [[ -z "$json_data" || "$json_data" == "null" || "$json_data" == "[]" ]]; then
    return 0 # Nothing to process
  fi

  # Use process substitution and while read for robust line handling,
  # especially if step text contains special characters.
  # jq -c '.[]' outputs each element of the top-level array on a new line, compactly.
  while IFS= read -r item; do
    # Extract the 'step' text. -r gives raw string output (no quotes).
    step_text=$(jq -r '.step' <<<"$item")
    # Extract the 'substeps' array. -c gives compact output.
    # ' // empty ' makes jq output nothing if 'substeps' is missing or null,
    # preventing errors in the next step.
    substeps_json=$(jq -c '.substeps // empty' <<<"$item")

    # Print the current item with proper indentation and numbering.
    write "$(printf "%s%d. %s\n" "$indent" "$i" "$step_text")" "nonl"

    # Check if 'substeps' exists and is not an empty array '[]'.
    # -n checks if the substeps_json string is non-empty.
    if [[ -n "$substeps_json" && "$substeps_json" != "[]" ]]; then
      # Calculate the indentation for the next level (add 4 spaces).
      next_indent="${indent}    "
      # Recursive call to process the substeps.
      process_steps "$substeps_json" "$next_indent"
    fi

    # Increment the list counter for the current level.
    i=$((i + 1))
  done < <(jq -c '.[]' <<<"$json_data") # Feed the JSON array elements to the loop
}

# Parse the algorithm section
parse_algorithm() {
  local file="$1"

  algorithm_count=0
  for algorithm in $(jq -c '.[]' "$file"); do
    algorithm_count=$((algorithm_count + 1))

    # Name of the algorithm
    write "#### Algorithm $algorithm_count - $(echo "$algorithm" | jq -r '.algorithm') {.unnumbered}"

    write "##### Input {.unnumbered}"
    local input_count=0
    for input in $(echo "$algorithm" | jq -r -c '.input[]'); do
      input_count=$((input_count + 1))
      write "$input_count. $input" "nonl"
    done
    write

    write "##### Output {.unnumbered}"
    for output in $(echo "$algorithm" | jq -r -c '.output[]'); do
      write "- $output" "nonl"
    done
    write

    write "##### Steps {.unnumbered}"
    process_steps "$(echo "$algorithm" | jq -r -c '.steps')"
    write
  done
}

main() {

  for week in $(fd . "$parent_directory" -t d --exclude=Common --exclude="$(basename "$(realpath "$(dirname "$0")")")" --max-depth=1 "${excl_patterns[@]}"); do
    (
      write "# $(format_name "$week")"
    )
    echo "Processing $(basename "$week")"

    if [[ -f "$week/$DATE_FILENAME" ]]; then
      write "__Date: $(cat "$week/$DATE_FILENAME")__"
    else
      echo "WARNING: Date file $DATE_FILENAME not found in $week" >&2
    fi

    for question in $(fd . "$week" -t d --max-depth=1 --exclude=Common "${excl_patterns[@]}"); do
      (
        write "## $(format_name "$question")"
      )

      echo "Question $(basename "$question")"
      local missing_question=1

      if [[ -f "$question/$AIM_FILENAME" ]]; then
        write "__$(cat "$question/$AIM_FILENAME")__"
        missing_question=0
      fi

      if [[ -f "$question/$QUESTION_FILENAME" ]]; then
        write "### Question"
        write_file "$question/$QUESTION_FILENAME"
        write
        missing_question=0
      fi

      if [[ $missing_question -eq 1 ]]; then
        echo "WARNING: Question file $QUESTION_FILENAME or Aim file $AIM_FILENAME not found in $question" >&2
      fi

      if [[ -f "$question/$ALGORITHM_FILENAME" ]]; then
        write "### Algorithm"
        parse_algorithm "$question/$ALGORITHM_FILENAME"
      else
        echo "WARNING: Algorithm file $ALGORITHM_FILENAME not found in $question" >&2
      fi

      write "### Code"

      if [[ -f "$question/.files-to-prompt" ]]; then
        write "$(files-to-prompt "$question" --markdown --ignore-gitignore "${excl_patterns[@]//--exclude/--ignore}" | sed "s|$question||g")"
        write

      else
        write "__${MAIN_CODE_FILENAME}__"
        write "\`\`\`${MAIN_CODE_FILENAME##*.}"
        write_file "$question/$MAIN_CODE_FILENAME"
        write
        write '```'

        for extra_code in $(fd . "$question" "${code_exts[@]}" --max-depth=1 --exclude="$MAIN_CODE_FILENAME" "${excl_patterns[@]}"); do
          write "__$(basename "$extra_code")__"
          write "\`\`\`${extra_code##*.}"
          write_file "$extra_code"
          write
          write '```'
        done

      fi

      if [[ -f "$question/$OUTPUT_FILENAME" ]]; then
        write "### Execution"
        write '```sh'
        write_file "$question/$OUTPUT_FILENAME"
        write
        write '```'
      else
        echo "WARNING: Output file $OUTPUT_FILENAME not found in $question" >&2
      fi

    done
    write "\\pagebreak"
  done

}

check_requirements
main
