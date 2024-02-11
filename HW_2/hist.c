
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
    int *bins = (int *) calloc(nbins, sizeof (int));
    fill(bins);
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
                nbins= (i < (argc - 1)) ? atoi(argv[i + 1]) : nbins ;
                i++;
            }
            else
            {
                f= fopen(argv[i], "r");
                ///below that i did this if (if the code didnt work delete it please ///
                if (!f)
                {
                    fprintf(stderr,"FILE not found: \"%s\"\n",argv[1]);
                    exit(1) ;
                }
            }

        }

    }
}
void fill(int *bins)
{
    int grade,retval;
    double distance;
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
            else if (grade > 100 || grade < 0 ) {
                fprintf(stderr, "grade %d invalid \n",grade);
                exit(1);
            }

        }
        
       int place = grade / (100 / nbins);;
        if (grade != 100) 
        {
            bins[place]++;
        }
        else
        {
            bins[place-1]++;
        }

    }


    distance = 100.0 / nbins;
    for (int i = 0; i < nbins; ++i)
    {
        double left_edge = i * distance;
        double right_edge = (i<(nbins - 1)) ? ((i + 1) * distance - 1) : 100;
        printf("%.f-%.f\t%d\n",left_edge,right_edge,bins[i]);
    }
}






