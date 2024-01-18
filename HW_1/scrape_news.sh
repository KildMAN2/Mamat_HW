#!/bin/bash

# שלב ראשון: הורדת עמוד החדשות הראשי
wget https://www.ynetnews.com/category/3082 -O main_page.html

# שלב שני: חיפוש ושמירת קישורים לכתבות
grep -Eo "https://www\.ynetnews\.com/article/[a-zA-Z0-9]+" main_page.html > article_links.txt

# שלב שלישי: ספירת מספר הקישורים
num_articles=$(wc -l < article_links.txt)
echo "Number of articles: $num_articles"

# שלב רביעי: לעבור על קישורים ולבדוק מספר הפעמים שמופיעים שמות משפחה
while IFS= read -r link; do
    # הורדת הכתבה
    wget "$link" -O article.html

    # ספירת מספר הופעות שמות משפחה
    netanyahu_count=$(grep -io "Netanyahu" article.html | wc -l)
    gantz_count=$(grep -io "Gantz" article.html | wc -l)

    # הדפסת התוצאה
    echo "$link, Netanyahu: $netanyahu_count, Gantz: $gantz_count"

    # מחיקת הקובץ של הכתבה
    rm article.html

done < article_links.txt
