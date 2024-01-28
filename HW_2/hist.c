
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/**
 * @brief Application's main entry point
 * @param argc Number of arguments
 * @param argv Pointer to arguments
 * @return Non-zero value in case of an error
 */
 static FILE *f;
 static int nbins = 10;
#define MAX_GRADE 100



void certify_arg(int argc, char **argv);
void fill(int *bins);



int main(int argc, char **argv)
{
    certify_arg(argc,argv);
    if (!f)
    {
        fprintf(stderr,"FILE not found: \"%s\"\n",argv[1]);
        return 1;
    }
    int *bins = (int *) calloc(nbins,sizeof (int));
    fill(bins);
    fclose(f);
    free(bins);
    return 0;
}
void certify_arg(int argc, char **argv)
{
    f = stdin;
    for (int i = 1; i <argc ; ++i)
    {
        if (!strcmp(argv[i],"-"))
        {
            f=stdin;
        }
        else
        {
            if (!strcmp(argv[i],"-nbins"))
            {
                nbins= (i<(argc-1)) ? atoi(argv[i+1]): nbins ;
                i++;
            }
            else
            {
                f= fopen(argv[i], "r");
            }

        }

    }
}
void fill(int *bins)
{
    int grade,retval;
    double distance = MAX_GRADE/nbins;
    while(1)
    {
        retval = fscanf(f,"%d",&grade);
        if (retval == EOF)
        {
            break;
        }
        else
        {
            if (retval != 1)
            {
                fprintf(stderr, "Error: not a number\n");
                exit(1);
            }

        }

       int place = (int) grade / distance;
        if (grade != MAX_GRADE)
        {
            bins[place]++;
        }
        else
        {
            bins[place-1]++;
        }

    }


    distance = MAX_GRADE/nbins;
    for (int i = 0; i < nbins; ++i)
    {
        double left_edge = i * distance;
        double right_edge = (i<(nbins-1)) ? ((i+1)*distance -1) : MAX_GRADE;
        printf("%.f-%.f\t%d\n",left_edge,right_edge,bins[i]);
    }
}






