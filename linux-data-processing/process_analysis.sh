#!/bin/bash
ps -ef > gawkfile.txt
gawk 'NR <= 10 {print $0}' gawkfile.txt
gawk 'END {print NR-1}' gawkfile.txt
whoami
gawk -v user="$(whoami)" 'index($0,user) {print $0}' gawkfile.txt
gawk -v user="$(whoami)" '$1 == user {print $0}' gawkfile.txt
gawk 'NF > 8 {print NR, NF}' gawkfile.txt
gawk 'NF > 8 {for(i=9; i<=NF; i++) print NR, i, $i}' gawkfile.txt
gawk 'BEGIN {OFS="\t"} {print $1, $3, $2, $4, $5, $6, $7, $8}' gawkfile.txt
