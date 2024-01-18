#! /bin/bash

wget https://www.ynetnews.com/category/3082
URLS=$(grep -oP "https://www.ynetnews.com/article/[a-zA-Z0-9]+" 3082 |
	   sort |
	   uniq)

echo "$URLS" | wc -w > results.csv

for line in $URLS ;
  do
	article=$(echo "$line" | grep -o '[^/]\+$')

	N=$(grep -o Netanyahu "$article" | wc -l)
	G=$(grep -o Gantz "$article" | wc -l)
  total_count=$((N + G))

  if (( total_count == 0 )); then
		  echo "$line, -" >> results.csv
	else
	    echo "$line, Netanyahu, $N, Gantz, $G" >> results.csv
	fi
done

