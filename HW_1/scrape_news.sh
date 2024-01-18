#! /bin/bash

wget https://www.ynetnews.com/category/3082
URLS=$(grep -oP "https://www.ynetnews.com/article/[a-zA-Z0-9]+" 3082 |
	   sort |
	   uniq)

echo "$URLS" | wc -w > results.csv

for url in $URLS ;
  do
    wqet -q "$url" -O article.html
	article_name=$(echo "$url" | awk -F/ '{print $NF}')

	N=$(grep -o 'Netanyahu' article.html | wc -l)
	G=$(grep -o 'Gantz' article.html | wc -l)
  total_count=$((N + G))

  if (( total_count == 0 )); then
		  echo "$url, -" >> results.csv
	else
	    echo "$url, Netanyahu, $N, Gantz, $G" >> results.csv
	fi
done

