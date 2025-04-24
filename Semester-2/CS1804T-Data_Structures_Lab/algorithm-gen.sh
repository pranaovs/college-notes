#!/usr/bin/env bash

for folder in $(fd -t d --min-depth 2 --exclude=Common --exclude=Lab_Record); do
  (
    cd "$folder" || (
      echo "Couldn't cd into $folder"
      exit 1
    )

    if test -f "algorithm.json"; then
      echo "Algorithm file already exists in $(basename "$folder")"
      exit 0
    fi

    files-to-prompt . | wl-copy

    read -r -p "Press [ENTER] to paste algorithm for $(basename "$folder"): "

    wl-paste >algorithm.json

  )

done
