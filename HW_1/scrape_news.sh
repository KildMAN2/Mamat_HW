#! /bin/bash

# Step 1: Download the main news page
wget https://www.ynetnews.com/category/3082 -O 3082.html

# Step 2: Extract article URLs
URLs=$(grep -oP "https://www.ynetnews.com/article/[a-zA-Z0-9]+" 3082.html | sort | uniq)

# Step 3: Loop through each URL and process the article
while read -r url; do
    # Download the article
    article=$(wget "$url" -O- 2>/dev/null)

    # Count occurrences of names
    N=$(grep -o "Netanyahu" <<< "$article" | wc -w)
    G=$(grep -o "Gantz" <<< "$article" | wc -w)

    # Print the result
    if [ "$N" -eq 0 ] && [ "$G" -eq 0 ]; then
        echo "$url, -"
    else
        echo "$url, Netanyahu, $N, Gantz, $G"
    fi
done <<< "$URLs"
