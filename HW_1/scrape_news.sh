#! /bin/bash

wget https://www.ynetnews.com/category/3082 -O main_page.html
URLs=$(grep -oP "https://www.ynetnews.com/article/[a-zA-Z0-9]+" main_page.html|
	   sort |
	   uniq)

echo "Number of articles: $(echo "$URLs" | wc -w )"> results.csv
while read -r link;
  do
  wget "$link" -O article.html
	N=$(grep -o "Netanyahu" article.html | wc -l)
	G=$(grep -o "Gantz" article.html | wc -l)

  if ((N==0)) && ((G==0)); then
		  echo "$link, -" >> results.csv
	else
	    echo "$link, Netanyahu, $N, Gantz, $G" >> results.csv
	fi
	rm article.html
done <<< "$URLs"


