
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXGRADE 100
#define MINGRADE 0


static FILE *m;



int certify_arg(int argc, char **argv);
void operate(FILE *d);



int main(int argc, char **argv)
{
    certify_arg(argc,argv);
    operate(m);
    fclose(m);

    return 0;
}
int certify_arg(int argc, char **argv)
{
    if (argc == 1 ||!strcmp(argv[1],"-"))
    {
        m=stdin;
    }
    else
    {
        {
            m= fopen(argv[1], "r");
        }
    }

    if (!m)
    {
        fprintf(stderr,"FILE not found: \"%s\"\n",argv[1]);
        return 1; /*failed */
    }
    return 0;

}
void operate(FILE *d)
{
   int grade,hist[MAXGRADE]={0},counter=0,median , median_grade=0;
   int retval, n_students , line_num =1;
    while (1)
    {
        retval = fscanf(d, "%d", &grade);
        if (retval == EOF)
        {
            break;
        }
        else if (retval != 1)
        {
            fprintf(stderr, "Error: not a number\n");
            exit(1);
        }
        else if (grade > MAXGRADE || grade < MINGRADE)
        {
            fprintf(stderr, "Error: illegal grade,line number is: %d \n", line_num);
            exit(1);
        }
            hist[grade]++;
            line_num++;
    }
        n_students = line_num  -1;
        median = (n_students+1)/2;
        for (int i = 0; i < MAXGRADE; ++i)
        {
            counter += hist[i];
            if (counter >= median)
            {
                median_grade = i;
                break;
            }

        }
    fprintf(stdout,"%d\t",median_grade);

}









