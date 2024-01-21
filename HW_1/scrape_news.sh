#!/bin/bash

# Step 1: Fetch the main page
site="https://www.ynetnews.com/category/3082"
wget -O 3082 --no-check-certificate "$site" 2>/dev/null

# Step 2: Extract article URLs
URLs=$(grep -oP "https://(www\.)?ynetnews.com/article/[a-zA-Z0-9]+" 3082 | sort | uniq)

# Step 3: Count unique URLs
echo $(wc -l <<< "$URLs") >>results.csv

# Step 4: Loop through each URL and process
for url in $URLs; do
    # Step 5: Fetch article content
    article=$(wget --no-check-certificate -O- "$url" 2>/dev/null)

    # Step 6: Count occurrences of names
    N=$(grep -o "Netanyahu" <<< "$article" | wc -w)
    G=$(grep -o "Gantz" <<< "$article" | wc -w)

    # Step 7: Print results
    if [ "$N" -eq 0 ] && [ "$G" -eq 0 ]; then
        echo "$url, -" >> results.csv
    else
        echo "$url, Netanyahu, $N, Gantz, $G" >>results.csv
    fi
done
