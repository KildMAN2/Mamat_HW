#! /bin/bash

wget  -q https://www.ynetnews.com/category/3082
URLS=$(grep -oP "https://www.ynetnews.com/article/[a-zA-Z0-9]+" 3082 |
	   sort |
	   uniq)
	   
echo "$URLS" | wc -w > results.csv

for url in $URLS ;
  do
  wget -q "$url" -O article.html
	article=$(echo "$url" | awk -F/ '{print $NF}' )
	
	N=$(grep -o Netanyahu "$article" | wc -l)
	G=$(grep -o Gantz "$article" | wc -l)
  total_count=$((N + G))

  if (( total_count == 0 )); then
		  echo "$url, -" >> results.csv
	else 
	    echo "$url, Netanyahu, $N, Gantz, $G">> results.csv
	fi
done
 
