// 123456789
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



#define MAX_LENGTH 1001 // because  at the end string there this /n
#define  N_FREQUEUNCY 10
int main()
{
    char s [MAX_LENGTH];
    int frequency[N_FREQUEUNCY] ={0};
    scanf("%s",s);

    for (int i = 0;  s[i] != '\0' ; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            frequency[s[i] - '0'] ++;
        }
    }
    for (int i = 0; i < N_FREQUEUNCY; ++i)
    {
        if (i == N_FREQUEUNCY-1)
        {
            printf("%d\n",frequency[i]);
        }
        else
        {
            printf("%d ", frequency[i]);
        }

    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
