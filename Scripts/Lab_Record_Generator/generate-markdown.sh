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

# Required tools
REQUIRED_TOOLS=("jq" "fd" "sed" "tr" "basename" "dirname" "printf" "echo" "getopts")

IFS=$'\n'

info() {
  echo "INFO: $1" >&2
}

warn() {
  echo "WARNING: $1" >&2
}

# Kills the script with an error message
# Usage: die "error message"
die() {
  echo "ERROR: $1" >&2
  exit 1
}

# Check if requirements are fulfilled for running the main function
# Should run before invocation of main
# Checks variables required for the script
check_requirements() {

  local IFS=" "

  if [[ -z $MAIN_CODE_FILENAME ]]; then
    die "ERROR: MAIN_CODE_FILENAME is not set. Please set it before running the script."
  fi

  local missing_tools=()
  for tool in "${REQUIRED_TOOLS[@]}"; do
    if ! command -v "$tool" &>/dev/null; then
      missing_tools+=("$tool")
    fi
  done

  if [ ${#missing_tools[@]} -ne 0 ]; then
    warn "Required tools not found: ${missing_tools[*]}"
    warn "Install the missing tools and try again."
    if [[ " ${missing_tools[*]} " == *" fd "* ]]; then
      warn "fd installation steps: https://github.com/sharkdp/fd#installation"
    fi
    die
  fi
}

# Parses/converts variables required for the script
# Should run before invocation of main
prerequisites() {
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

}

# Remove directory path, leading digits/hyphen, and replace underscores with spaces
# To make a friendly title from directory name
# Usage:
#   $1: string to format
format_name() {
  # name=$(echo "$1" | sed "s/^[\.\/]*[0-9]*-//" | sed "s/_/ /g" | sed 's/\/$//')
  name=$(basename "$1" | sed 's/^[0-9]*-//; s/_/ /g; s/\/$//')
  echo "$name"
}

# Generates a string of '#' characters based on the nesting level
# Usage:
#   $1: nesting level (1 for h1 (#), 2 for h2 (##), etc.)
heading() {
  local level="$1"
  printf '#%.0s' $(seq 1 "$level")
}

# # Helper function to write given string to the file $output_file
# # Usage:
# #   $1: string to write to the file
# #   $2: passing "nonl" would not append the file with a newline (no newline)
# write() {
#   if [[ "$#" -gt 0 ]]; then
#     echo "$1" >>"$output_file"
#   fi
#   if [[ "$2" != "nonl" ]]; then
#     echo >>"$output_file"
#   fi
# }
#
# write_file() {
#   tr -d '\r' <"$1" >>"$output_file"
# }

# Parses the $ALGORITHM_FILENAME and converts it to markdown-based list style
# Only parses the "steps" key
# Usage:
#   $1: "steps" key value
#   $2: Indentation string. String to use for global indentation.
#   Used for recursive call for substeps
# From Gemini 2.5 Pro
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
    printf -- "%s%d. %s\n" "$indent" "$i" "$step_text"

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
# Usage:
#   $1: algorithm string
#   $2: staring markdown heading nesting count
parse_algorithm() {
  local algorithm_json="$1"
  local heading_nesting="$2"

  algorithm_count=0
  for algorithm in $(echo "$algorithm_json" | jq -c '.[]'); do
    algorithm_count=$((algorithm_count + 1))

    # Algorithm name
    printf -- "%s Algorithm %s - %s {.unnumbered}\n\n" "$(heading "$(("$heading_nesting"))")" "$algorithm_count" "$(echo "$algorithm" | jq -r '.algorithm')"

    # Inputs
    printf -- "%s Input {.unnumbered}\n\n" "$(heading "$(("$heading_nesting" + 1))")"
    local input_count=0
    for input in $(echo "$algorithm" | jq -r -c '.input[]'); do
      input_count=$((input_count + 1))
      printf -- "%s. %s\n" "$input_count" "$input"
    done
    printf -- "\n"

    # Outputs
    printf -- "%s Output {.unnumbered}\n\n" "$(heading "$(("$heading_nesting" + 1))")"
    for output in $(echo "$algorithm" | jq -r -c '.output[]'); do
      printf -- "- %s\n" "$output"
    done
    printf -- "\n"

    # Steps
    printf -- "%s Steps {.unnumbered}\n\n" "$(heading "$(("$heading_nesting" + 1))")"
    process_steps "$(echo "$algorithm" | jq -r -c '.steps')"
    printf -- "\n"
  done
}

# Question week directory processing function
# Usage:
#   $1: Parent question week directory path (containing questions)
#   $2: Heading nesting level
# Each question will be passed to process_question function
process_week() {
  local week="$1"
  local heading_nesting="$2"

  info "Processing $(basename "$week")"

  printf -- "%s %s\n\n" "$(heading $((heading_nesting)))" "$(format_name "$week")"

  # Date
  if [[ -f "$week/$DATE_FILENAME" ]]; then
    printf -- "__Date: %s__\n\n" "$(cat "$week/$DATE_FILENAME")"
  else
    warn "Date file $DATE_FILENAME not found in $week"
  fi

  for question in $(fd . "$week" -t d --max-depth=1 --exclude=Common "${excl_patterns[@]}"); do
    process_question "$question" "$((heading_nesting + 1))"

    printf -- "\\pagebreak\n\n"
  done
}

process_question() {
  local question="$1"
  local heading_nesting="$2"

  printf -- "%s %s\n\n" "$(heading $((heading_nesting)))" "$(format_name "$question")"

  info "Question $(basename "$question")"
  local missing_question=1

  if [[ -f "$question/$AIM_FILENAME" ]]; then
    printf -- "__%s__\n\n" "$(cat "$question/$AIM_FILENAME")"
    missing_question=0
  fi

  # Question text
  if [[ -f "$question/$QUESTION_FILENAME" ]]; then
    printf -- "%s %s\n\n" "$(heading $((heading_nesting + 1)))" "Question"
    cat "$question/$QUESTION_FILENAME"
    printf -- "\n"
    missing_question=0
  fi

  if [[ $missing_question -eq 1 ]]; then
    warn "Question file $QUESTION_FILENAME or Aim file $AIM_FILENAME not found in $question"
  fi

  # Algorithm
  if [[ -f "$question/$ALGORITHM_FILENAME" ]]; then
    printf -- "%s %s\n\n" "$(heading $((heading_nesting + 1)))" "Algorithm"
    parse_algorithm "$(cat "$question/$ALGORITHM_FILENAME")" "$((heading_nesting + 2))"
  else
    warn "Algorithm file $ALGORITHM_FILENAME not found in $question"
  fi

  # Code
  printf -- "%s %s\n\n" "$(heading $((heading_nesting + 1)))" "Code"

  # Use files-to-prompt tool if .files-to-prompt file is present in a question directory
  if [[ -f "$question/.files-to-prompt" ]]; then
    files-to-prompt "$question" --markdown --ignore-gitignore "${excl_patterns[@]//--exclude/--ignore}" | sed "s|$question||g"
    printf -- "\n"

  else
    printf -- "__%s__\n\n" "${MAIN_CODE_FILENAME}"
    printf -- "\`\`\`%s\n" "${MAIN_CODE_FILENAME##*.}"
    cat "$question/$MAIN_CODE_FILENAME"
    printf -- "\n"
    printf '```\n'

    # Extra dependent codes. Defined by $CODE_EXTENSIONS environment variable
    if [ ! ${#code_exts[@]} -eq 0 ]; then
      for extra_code in $(fd . "$question" "${code_exts[@]}" --exclude="$MAIN_CODE_FILENAME" "${excl_patterns[@]}"); do
        echo "${excl_patterns[@]}"
        printf -- "__%s__\n\n" "$(basename "$extra_code")"
        printf -- "\`\`\`%s\n" "${extra_code##*.}"
        cat "$extra_code"
        printf -- "\n\`\`\`\n"
      done
    fi
  fi

  # Output
  if [[ -f "$question/$OUTPUT_FILENAME" ]]; then
    printf -- "%s %s\n\n" "$(heading $((heading_nesting + 1)))" "Execution"
    printf -- "\`\`\`sh\n"
    cat "$question/$OUTPUT_FILENAME"
    printf -- "\n"
    printf -- "\`\`\`\n"
  else
    warn "Output file $OUTPUT_FILENAME not found in $question"
  fi

  printf -- "\n"
}

main() {

  heading_nesting=1

  if [ -n "$dir_flag" ] && [ -d "$dir_flag" ]; then
    parent_directory="$dir_flag"

    for week in $(fd . "$parent_directory" -t d --exclude=Common --exclude="$(basename "$(realpath "$(dirname "$0")")")" --max-depth=1 "${excl_patterns[@]}"); do
      process_week "$week" "$((heading_nesting))"
    done
  else
    for week in "${dirs[@]}"; do
      if [ -d "$week" ]; then
        process_week "$week" "$((heading_nesting))"
      else
        warn "Invalid directory: $week"
      fi
    done
  fi
}

check_requirements

# Parse command line options
dir_flag=""
dirs=()

# Parse options
while getopts ":d:" opt; do
  case "$opt" in
  d)
    dir_flag="$OPTARG"
    ;;
  \?)
    die "Unknown option: -$OPTARG"
    ;;
  :)
    die "Option -$OPTARG requires an argument."
    ;;
  esac
done

# Remove parsed options
shift $((OPTIND - 1))

# If -d not used, collect positional arguments
if [[ -z "$dir_flag" ]]; then
  if [[ $# -gt 0 ]]; then
    dirs=("$@")
  else
    die "Invalid usage. Use -d to pass a top level directory or provide arguments for each question directory"
  fi
fi

prerequisites
main
