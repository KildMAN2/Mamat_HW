#! /bin/bash

wget https://www.ynetnews.com/category/3082
URLS=$(grep -oP "https://www.ynetnews.com/article/[a-zA-Z0-9]+" 3082 |
	   sort |
	   uniq)

echo "$URLS" | wc -w > results.csv
for url in $URLS ;
  do
  wqet -q "$url" -o article.html
	article_name=$(echo "$url" | grep -o "https://www.ynetnews.com/article/\K[a-zA-Z0-9]+")

	N=$(grep -o 'Netanyahu' article.html | wc -l)
	G=$(grep -o 'Gantz' article.html | wc -l)
  total_count=$((N + G))

  if (( total_count == 0 )); then
		  echo "$url, $article_name, -" >> results.csv
	else
	    echo "$url, $article_name, Netanyahu, $N, Gantz, $G" >> results.csv
	fi
done

