#!/bin/bash

# Regular Expression Text Processing
# Author: Harsana Neupane
# Systems Programming

# Extract email-like patterns
egrep '[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}' datafile.txt > emails.txt

# Extract lines containing numbers
egrep '[0-9]' datafile.txt > numbers.txt

# Extract Unix-style file paths
egrep '(^|[[:space:]])(/[A-Za-z0-9._-]+)+' datafile.txt > filepaths.txt

# Extract dates with / or - separators
egrep '((0[1-9]|1[0-2])/(0[1-9]|[12][0-9]|3[01])/([0-9]{2}|[0-9]{4})|(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])-([0-9]{2}|[0-9]{4}))' datafile.txt > dates.txt
