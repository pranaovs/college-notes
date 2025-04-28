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
# Subdirectories should contain the question name, and have main.cpp, algorithm.json, output.txt and any optional .cpp/.h codes.

MAIN_CODE_FILENAME="main.cpp"
DATE_FILENAME="date.txt"
QUESTION_FILENAME="question.txt"
ALGORITHM_FILENAME="algorithm.json"
OUTPUT_FILENAME="output.txt"

IFS=$'\n'

if [[ $# -ne 2 ]]; then
  echo "Usage: $0 <output_file> <parent_directory>"
  exit 1
fi

output_file="$1"
parent_directory="$2"

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

write_file() {
  echo "$1" >>"$output_file"
  if ! [[ "$#" -gt 1 ]]; then
    echo >>"$output_file"
  fi
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
    write_file "$(printf "%s%d. %s\n" "$indent" "$i" "$step_text")" "placehold"

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
    write_file "#### Algorithm $algorithm_count - $(echo "$algorithm" | jq -r '.algorithm') {.unnumbered}"

    write_file "##### Input {.unnumbered}"
    local input_count=0
    for input in $(echo "$algorithm" | jq -r -c '.input[]'); do
      input_count=$((input_count + 1))
      write_file "$input_count. $input"
    done

    write_file "##### Output {.unnumbered}"
    for output in $(echo "$algorithm" | jq -r -c '.output[]'); do
      write_file "- $output"
    done

    write_file "##### Steps {.unnumbered}"
    process_steps "$(echo "$algorithm" | jq -r -c '.steps')"
    write_file ""

  done
}

main() {

  for week in $(fd . "$parent_directory" -t d --exclude=Common --exclude=Lab_Record --max-depth=1); do
    (
      write_file "# $(format_name "$week")"
    )
    echo "Processing $(basename "$week")"

    for question in $(fd . "$week" -t d --max-depth=1 --exclude=Common); do
      (
        write_file "## $(format_name "$question")"
      )

      echo "Question $(basename "$question")"

      if [[ -f "$DATE_FILENAME" ]]; then
        write_file "__Date: $(cat $DATE_FILENAME)__"
      fi

      if [[ -f "$question/$QUESTION_FILENAME" ]]; then
        write_file "### Question"
        write_file "$(cat "$question/$QUESTION_FILENAME")"
      else
        echo "Question file question.txt not found in $question" >&2
      fi

      if [[ -f "$question/$ALGORITHM_FILENAME" ]]; then
        write_file "### Algorithm"
        parse_algorithm "$question/$ALGORITHM_FILENAME"
      else
        echo "Algorithm file $ALGORITHM_FILENAME not found in $question" >&2
      fi

      write_file "### Code"
      write_file "__${MAIN_CODE_FILENAME}__"
      write_file "\`\`\`${MAIN_CODE_FILENAME##*.}"
      cat "$question/$MAIN_CODE_FILENAME" >>"$output_file"
      write_file '```'

      for extra_code in $(fd . "$week/$question" -e "cpp" -e "h" --max-depth=1 --exclude=$MAIN_CODE_FILENAME); do
        write_file "__$(basename "$extra_code")__"
        write_file "\`\`\`${extra_code##*.}"
        cat "$extra_code" >>"$output_file"
        write_file ""
        write_file '```'
      done

      if [[ -f "$question/$OUTPUT_FILENAME" ]]; then
        write_file "### Execution"
        write_file '```sh'
        cat "$question/$OUTPUT_FILENAME" >>"$output_file"
        write_file '```'
      else
        echo "Output file $OUTPUT_FILENAME not found in $question" >&2
      fi

    done
  done

}

main
