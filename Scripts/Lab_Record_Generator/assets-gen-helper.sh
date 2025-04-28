#!/usr/bin/env bash

# This script is used to generate assets for lab record files in multiple directories.
# Each directory is expected to contain the code for the particular lab,
# and the script will copy all the files in the directory using files-to-prompt and wait for the user to paste them into the file $filename.

IFS=$'\n'

if [[ $# -ne 2 ]]; then
  echo "Usage: $0 <filename> <parent_directory>"
  exit 1
fi

filename="$1"
parent_directory="$2"

for folder in $(fd . "$parent_directory" -t d --min-depth 2 --exclude=Common --exclude=Lab_Record); do
  (
    cd "$folder" || (
      echo "Couldn't cd into $folder"
      exit 1
    )

    if [[ -f "$filename" ]]; then
      echo "$filename file already exists in $(basename "$folder")"
      exit 0
    fi

    files-to-prompt . | wl-copy

    read -r -p "Press [ENTER] to paste algorithm for $(basename "$folder"): "

    wl-paste >"$filename"
  )

done
