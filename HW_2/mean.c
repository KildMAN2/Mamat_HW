
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int certify_arg(int argc, char **argv);
void mean(FILE *f);

static FILE *f;

int main(int argc, char **argv) {


    certify_arg(argc,argv);
	mean(f);
    fclose(f);

}
int certify_arg(int argc, char **argv)
{
    if (argc == 1 ||!strcmp(argv[1],"-"))
    {
        f=stdin;
    }
    else
    {
        {
            f= fopen(argv[1], "r");
        }
    }

    if (!f)
    {
        fprintf(stderr,"FILE not found: \"%s\"\n",argv[1]);
        perror("fopen");
        return 1; /*failed */
    }
    return 0;

}
void mean(FILE *f) {
    int grade;
    int retVal;
    double sum = 0;
    int lineNum = 0;

    while(1) {
        retVal = fscanf(f, "%d" , &grade);
        if (retVal == EOF) {
            break;
        }
        else if (retVal != 1) {
            fprintf(stderr, "line %d: Not a number \n" , lineNum);
            exit(1);
        }
        else if (grade > 100 || grade < 0 ) {
            fprintf(stderr, "line %d : Not a legal number\n", lineNum);
            exit(1);
        }
        else {
            sum += grade;
            lineNum ++;
        }
    }
    if (lineNum != 0)
        fprintf(stdout,"%.2f\t", sum/lineNum );
}















