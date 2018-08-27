cat /etc/passwd | grep -v "#" | cut -d ":" -f 1 | sed -n 'n;p' | rev | sort -r | sed "s/$/,/g" | tr "\n" " " | cut -d " " -f $FT_LINE1-$FT_LINE2 | rev | cut -c2- | rev | sed "s/$/./g" | tr -d "\n"
