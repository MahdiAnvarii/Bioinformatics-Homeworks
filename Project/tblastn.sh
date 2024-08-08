#!/bin/bash

# Create database
makeblastdb -in y5.final.contigs.fa -dbtype nucl -out xylanase_db

# Run tblastn
tblastn -query GH10_AA.fasta -db new_xylanase -out GH10_result.out -evalue 1e-5 -num_threads 7
