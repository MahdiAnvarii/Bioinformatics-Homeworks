#!/bin/bash

# Create database
makeblastdb -in y5.final.contigs.fa -dbtype nucl -out xylanase_db

# Run tblastn
tblastn -query GH11_AA.fasta -db new_xylanase -out GH11_result.out -evalue 1e-5 -num_threads 7