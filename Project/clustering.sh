#!/bin/bash

# Clustering protein sequences
cd-hit -i filtered_output.fasta -o clustered_sequences.fasta -c 0.97 -n 5
