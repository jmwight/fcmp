#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MXLINELEN	1024

int main(int argc, char **argv)
{
	/* error if not 3 arguments */
	if(argc != 3)
	{
		fprintf(stderr, "Error: needs to be two file names given, only %d given\n",
				argc - 1);
		exit(1);
	}

	FILE *fp1, *fp2;
	fp1 = fopen(*++argv, "r");
	fp2 = fopen(argv[1], "r");

	/* error if can't open one of files */
	if(fp1 == NULL)
		fprintf(stderr, "Error: cannot open %s\n", argv);
	else if(fp2 == NULL)
		fprintf(stderr, "Error: cannot open %s\n", argv[1]);

	if(fp1 == NULL || fp2 == NULL)
		exit(1);

	/* what looks like an infinte loop at first glance but the least messy way I think to write
	 * this */
	char s1[MXLINELEN], s2[MXLINELEN];
	int lnum;
	for(lnum = 0; ; lnum++)
	{
		fgets(s1, MXLINELEN, fp1);
		fgets(s2, MXLINELEN, fp2);
		if(strlen(s1) == 0 || strlen(s2) == 0)
		{
			fprintf(stdout, "No difference between files\n");
			break;
		}
		else if(strcmp(s1, s2) != 0)
		{
			fprintf(stdout, "Difference on line %d!\n", lnum);
			fprintf(stdout, "File 1: %s\n", s1);
			fprintf(stdout, "File 2: %s\n", s2);
			break;
		}
	}

	/* close two files */
	fclose(fp1);
	fclose(fp2);
}
