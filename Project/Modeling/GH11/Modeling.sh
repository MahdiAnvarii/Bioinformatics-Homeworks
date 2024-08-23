#!/bin/bash

# Downloading known GH11 sequences from UniProt and concatenate them
cat Sequences/* > GH11_sequences.fasta
cat GH11_sequences.fasta | less

# MSA
mafft --auto GH11_sequences.fasta > MSA_GH11_xylanases.fasta
cat MSA_GH11_xylanases.fasta

# Modeling with HMM
hmmbuild GH11_xylanase.hmm MSA_GH11_xylanases.fasta
hmmsearch --tblout GH11_results.txt GH11_xylanase.hmm clustered_sequences.fasta
cat GH11_results.txt
