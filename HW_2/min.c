
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void min(FILE *f) {
	int grade;
	int retVal;
	int min_num = 100;
	int line_num = 1;

	while(1) {
		retVal = fscanf(f, "%d" , &grade);
		if (retVal == EOF) {
			break;
		}
		else if (retVal != 1 || grade > 100 || grade < 0) {
            fprintf(stderr, "Error at line %d: grade %d invalid \n", line_num,grade);
			exit(1);
		}
		else if (grade < min_num) {
			min_num = grade;
		}
		line_num++;
	}
	fprintf(stdout,"%d\t", min_num );



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

	min(f);
    if (f != stdin) {
        fclose(f);
    }
}














