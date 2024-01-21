#! /bin/bash

site=https://www.ynetnews.com/category/3082
web_data=$(wget --no-check-certificate -o- "$site" 2>/dev/null)
URLs=$(echo "$web_data" |\ grep -oP "https://(www.)?ynetnews.com/article/[a-zA-Z0-9]+"
	   sort |
	   uniq)

wc -l <<< "$URLs" >> results.csv
 for url in $URLs;
  do
	echo -n "$url" >> results.csv
	article=$(wget --no-check-certificate -o- "$url" 2>/dev/null)

	N=$(grep -o "Netanyahu" <<< "$article" | wc -w)
	G=$(grep -o "Gantz" <<< "$article" | wc -w)

  if [ "$N" -eq 0 ] && [ "$G" -eq 0 ]; then
		  echo ", -" >> results.csv
	else
	    echo ", Netanyahu,"" $N"", Gantz,"" $G" >> results.csv
	fi
done

