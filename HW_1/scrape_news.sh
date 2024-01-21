User
#! /bin/bash

site="https://www.ynetnews.com/category/3082"
web_data=$(wget --no-check-certificate -O- "$site" 2>/dev/null)
URLs=$(echo "$web_data" | grep -oP "https://(www.)?ynetnews.com/article/[a-zA-Z0-9]+" | sort | uniq)
wc -l <<< "$URLs"
 for url in $URLs;
  do
	article=$(wget --no-check-certificate -O- "$url" 2>/dev/null)

	N=$(grep -o "Netanyahu" <<< "$article" | wc -w)
	G=$(grep -o "Gantz" <<< "$article" | wc -w)

  if [ "$N" -eq 0 ] && [ "$G" -eq 0 ]; then
    echo "$url, -" 
	else
    echo "$url, Netanyahu, $N, Gantz, $G"
	fi
done