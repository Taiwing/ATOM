echo "ibase=5; $FT_NBR1+$FT_NBR2" | sed 's/m/0/g' | sed 's/r/1/g' | sed 's/d/2/g' | sed 's/o/3/g' | sed 's/c/4/g' | sed "s/'/0/g" | sed 's/\\/1/g' | sed 's/\"/2/g' | sed 's/\?/3/g'| sed 's/\!/4/g' | bc | sed 's/^/ibase=10;obase=13; /' | bc | tr "0123456789ABC" "gtaio luSnemf"
