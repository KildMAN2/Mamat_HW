#!/bin/bash

# Step 1: Download the main page
wget -q https://www.ynetnews.com/category/3082 -O 3082.html

# Step 2: Extract article URLs
URLS=$(grep -oP "https://www.ynetnews.com/article/[a-zA-Z0-9]+" 3082.html | sort | uniq)

# Step 3: Count the number of unique URLs
num_urls=$(echo "$URLS" | wc -w)
echo "Number of unique URLs: $num_urls"

# Step 4: Iterate over each URL and count occurrences of family names
for url in $URLS; do
    # Download the article content
    wget -q "$url" -O article.html

    # Extract the last part of the URL as the article name
    article_name=$(basename "$url")

    # Count occurrences of family names
    N=$(grep -o Netanyahu article.html | wc -l)
    G=$(grep -o Gantz article.html | wc -l)

    # Print results to CSV file
    echo "$url, $article_name, Netanyahu: $N, Gantz: $G" >> results.csv

    # Optional: Sleep to avoid overloading the server
    sleep 1
done
