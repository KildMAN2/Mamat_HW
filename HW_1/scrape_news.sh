#! /bin/bash

wget https://www.ynetnews.com/category/3082 
URLs=$(grep -oP "https://www.ynetnews.com/article/[a-zA-Z0-9]+" 3082 | 
	   sort |
	   uniq)
	   
wget -iO - $URLs
for line in $URLs ;
  do
	article=$(echo "$line" | grep -o '[^/]\+$') 
	
	N=$(grep -o Netanyahu "$article" | wc -l)
	G=$(grep -o Gantz "$article" | wc -l)

	
    if (( (( $N==0 )) && (( $G==0 )))); then
		echo "$line"", -"
	else 
	    echo "$line"", Netanyahu,"" $N"", Gantz,"
	    " $G"", Bennett,"" $B"", Perez,""$P"
	fi
done
 