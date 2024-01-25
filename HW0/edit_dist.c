#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 100

int edit_dist(char word1[], char word2[]);
int smallest (int a ,int b , int c);

int main() {
    char word1[MAX_WORD_LEN], word2[MAX_WORD_LEN];

    fgets(word1, MAX_WORD_LEN, stdin);
    word1[strlen(word1) - 1] = '\0';
    fgets(word2, MAX_WORD_LEN, stdin);
    word2[strlen(word2) - 1] = '\0';

    printf("%d\n", edit_dist(word1, word2));

    return (0);
}

int edit_dist(char word1[], char word2[]) {
    /* YOUR CODE HERE */
    int w1_length = strlen(word1) + 1;
    int w2_length = strlen(word2) + 1;

    int distance [w1_length][w2_length];
    for (int i = 0; i < w1_length; ++i)
    {
        for (int j = 0; j < w2_length; ++j)
        {
            distance[i][j] =0;
        }
    }
    for (int i = 0; i < w1_length; ++i)
    {
        distance[i][0] =i;
    }
    for (int i = 0; i < w2_length; ++i)
    {
        distance[0][i] = i;
    }
    for (int i = 1; i < w1_length; ++i)
    {
        for (int j = 1; j < w2_length; ++j)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                distance[i][j] = distance[i - 1][j - 1];
            }
            else
            {
                distance[i][j] = 1 + smallest(distance[i - 1][j], distance[i][j - 1], distance[i - 1][j - 1] );
            }

        }
    }
    return distance[w1_length-1][w2_length-1];
}
int smallest (int a ,int b ,int c)
{
    int min =a ;
    if(min > b)
        min = b;
    if(min > c)
        min =c ;
    return min ;
}
