#!/bin/bash

site="https://ynetnews.com/category/3082"

website_data=$(wget --no-check-certificate -O - "$site" 2>/dev/null) #website_data contains all the content


articles=$(echo "$website_data" | \
			grep -oP "https://(www.)?ynetnews.com/article/[0-9a-zA-Z]+" | sort | uniq) #remove dupilcates

echo $(echo "$articles" | wc -l)  #prints the number of articles

for article in $articles; do
	echo -n "$article"  #prints each url

	temp=$(wget --no-check-certificate -O - "$article" 2>/dev/null)
	#in every article it counts how many times a name had appeared
	count_N=$(echo "$temp" | grep -o "Netanyahu" | wc -w)
	count_G=$(echo "$temp" | grep -o "Gantz" | wc -w)

	if [ $count_N -eq 0 ] && [ $count_G -eq 0 ] ; then #if no name was in article it prints ", -"
		echo ",-" >> results.csv
	else #otherwise prints how many times each name appeared
		echo -n ", Netanyahu, $count_N"
		echo -n ", Gantz, $count_G"
		echo
	fi
done