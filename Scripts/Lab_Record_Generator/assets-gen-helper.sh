#!/usr/bin/env bash

# This script is used to generate assets for lab record files in multiple directories.
# Each directory is expected to contain the code for the particular lab,
# and the script will execute $cmd and wait user interaction to paste them into the file $filename.

# Default values
filename=""
parent_directory=""
cmd="files-to-prompt . | wl-copy"
paste_cmd="wl-paste"
depth=2
interactive=true
overwrite=false

# Print help message
print_usage() {
  echo "Usage: $0 [options]"
  echo "Options:"
  echo "  -f, --file FILE        Filename to create in each directory"
  echo "  -d, --dir DIRECTORY    Parent directory to search"
  echo "  -c, --cmd COMMAND      Command to execute (default: 'files-to-prompt . | wl-copy')"
  echo "  -p, --paste COMMAND    Command to paste content (default: 'wl-paste')"
  echo "  -m, --min-depth DEPTH  Directory depth level to search (default: 2)"
  echo "  -n, --no-interaction   Skip user interaction (don't wait for ENTER key)"
  echo "  -o, --overwrite        Overwrite existing files if they exist"
  echo "  -h, --help             Display this help message"
  exit 1
}

# Parse command line arguments
while [[ $# -gt 0 ]]; do
  case "$1" in
  -f | --file)
    filename="$2"
    shift 2
    ;;
  -d | --dir)
    parent_directory="$2"
    shift 2
    ;;
  -c | --cmd)
    cmd="$2"
    shift 2
    ;;
  -m | --min-depth)
    depth="$2"
    shift 2
    ;;
  -p | --paste)
    paste_cmd="$2"
    shift 2
    ;;
  -n | --no-interaction)
    interactive=false
    shift
    ;;
  -o | --overwrite)
    overwrite=true
    shift
    ;;
  -h | --help)
    print_usage
    ;;
  *)
    echo "Unknown option: $1"
    print_usage
    ;;
  esac
done

# Validate required arguments
if [[ -z "$filename" || -z "$parent_directory" ]]; then
  echo "Error: Both filename and directory are required."
  print_usage
fi

IFS=$'\n'

for folder in $(fd . "$parent_directory" -t d --min-depth "$depth" --max-depth "$depth" --exclude=Common --exclude=Lab_Record); do
  (
    cd "$folder" || (
      echo "Couldn't cd into $folder"
      exit 1
    )

    if [[ -f "$filename" ]]; then
      if $overwrite; then
        echo "Overwriting existing $filename in $(basename "$folder")"
      else
        echo "$filename file already exists in $(basename "$folder")"
        exit 0
      fi
    fi

    eval "$cmd"

    if $interactive; then
      read -r -p "Press [ENTER] to paste for $(basename "$folder") into $filename: "
    else
      echo "Pasting for $(basename "$folder") into $filename"
    fi

    if [[ "$paste_cmd" == "-" ]]; then
      # Read from stdin and redirect to the file
      read -r -p "Enter data for $filename: " line
      echo "$line" >"$filename"
    elif [[ "$paste_cmd" == ":" ]]; then
      :
    else
      $paste_cmd >"$filename"
    fi
  )
done
