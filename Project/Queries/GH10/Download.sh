#!/bin/bash

input_file="genbank_ids.txt"
if [ ! -f "$input_file" ]; then
    echo "File $input_file not found!"
    exit 1
fi

# Read each line (gene ID) from the input file
while IFS= read -r gene_id; do
    url="https://www.ncbi.nlm.nih.gov/sviewer/viewer.fcgi?id=${gene_id}&db=protein&report=fasta&retmode=text"
    output_file="${gene_id}.fasta"
    wget -q -O "$output_file" "$url"
    if [ $? -eq 0 ]; then
        echo "Saved ${output_file}"
    else
        echo "Error fetching ${gene_id}"
    fi
done < "$input_file"

