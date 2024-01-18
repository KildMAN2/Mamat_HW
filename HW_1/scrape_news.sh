#! /bin/bash
site="https://ynetnews.com/category/3082"

website_data=$(wget --no-check-certificate -O - "$site" 2>/dev/null) #website_data contains all the content


articles=$(echo "$website_data" | \
			grep -oP "https://(www.)?ynetnews.com/article/[0-9a-zA-Z]+" | sort | uniq) #remove dupilcates

# shellcheck disable=SC2046
# shellcheck disable=SC2005
echo $(echo "$articles" | wc -l) >> results.csv #prints the number of articles

for article in $articles; do
	echo -n "$article" >> results.csv #prints each url

	temp=$(wget --no-check-certificate -O - "$article" 2>/dev/null)
	#in every article it counts how many times a name had appeared
	N=$(echo "$temp" | grep -o "Netanyahu" | wc -w)
	G=$(echo "$temp" | grep -o "Gantz" | wc -w)

  if ((N==0)) && ((G==0)); then
		  echo ",-" >> results.csv
	else
	echo -n ", Netanyahu, $N" >> results.csv
	echo -n ", Gantz, $G" >> results.csv
	echo >> results.csv
	fi
done

