#!/bin/bash

# CSV path
file_path="movie_database.csv"

# Load data from category cabinets, separate them, remove duplicates and sort them
cut -d ',' -f 3 "$file_path" | tr ',' '\n' | sed 's/^[ \t]*//;s/[ \t]*$//' | sort | uniq > categories.txt

# Display unique categories
echo "Unique movie categories:"
cat unique_categories.txt
