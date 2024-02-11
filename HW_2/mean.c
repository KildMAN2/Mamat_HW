
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mean(FILE *f) {
	int grade;
	int retVal;
	double sum = 0;
	int line_num = 1;

	while(1) {
		retVal = fscanf(f, "%d" , &grade);
		if (retVal == EOF) {
			break;
		}
		else if (retVal != 1) {
            fprintf(stderr, "Error at line %d: grade %d invalid \n", line_num,grade);
			exit(1);
		}
		else if (grade > 100 || grade < 0 ) {
            fprintf(stderr, "Error at line %d: grade %d invalid \n", line_num,grade);
			exit(1);
		}
			else {
				sum+=grade;
				line_num ++;
			}
	}
    if ((line_num - 1) != 0)
    {
        fprintf(stdout, "%.2f\t", sum / (line_num - 1));
    }
    else
        fprintf(stdout, "%.2f\t", sum );




}


int main(int argc, char **argv) {
	FILE *f;

	if (argc == 1 || !strcmp(argv[1] , "-") )  {
		f = stdin;
	}
	else {
		f = fopen(argv[1], "r");
	}

	if (!f) {
		fprintf (stderr, "File not found: %s \n" , argv[1]);
		return 1;
	}

	mean(f);
    if(f!=stdin)
        fclose(f);
    return 0;
}














