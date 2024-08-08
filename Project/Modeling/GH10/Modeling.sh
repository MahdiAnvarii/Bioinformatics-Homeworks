#!/bin/bash

# Downloading known GH10 sequences from UniProt and concatenate them
cat Sequences/* > GH10_sequences.fasta
cat GH10_sequences.fasta | less

# MSA
mafft --auto GH10_sequences.fasta > MSA_GH10_xylanases.fasta
cat MSA_GH10_xylanases.fasta

# Modeling with HMM
hmmbuild GH10_xylanase.hmm MSA_GH10_xylanases.fasta
hmmsearch --tblout GH10_results.txt GH10_xylanase.hmm clustered_sequences.fasta
cat GH10_results.txt
