#!/bin/bash
sed 's/^-/R/' datafile4.txt > sedfile.txt
sed -n '15,25p' sedfile.txt
sed -i '1d' sedfile.txt
sed -i '/media/a Found the Pattern' sedfile.txt
sed -n '1,10p' sedfile.txt
