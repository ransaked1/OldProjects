cat /etc/passwd | sed '/^#/d' | sed -n 'n;p' | sed 's/:\(.*\)//g' | rev | sort -r | awk 'NR >= ENVIRON["FT_LINE1"] && NR <= ENVIRON["FT_LINE2"]' | tr '\n' ' ' | sed 's/ /, /g' | sed 's/\(.*\), /\1./'| tr -d '\n'