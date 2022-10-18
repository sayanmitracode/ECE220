#include<stdio.h>

int main()
{
	
	char inputFileName[20] = "ece220.csv";
	FILE * inputfile;
	FILE * outputfile;
	
	int uin;
	char lname[20];
	char fname[20];
	int numread=0;
	inputfile = fopen(inputFileName,"r");
	if (inputfile == NULL)
	{
		printf("\n File could not be opened\n");
		return -1;
	}

	outputfile = fopen("output.dat","w");
	if (outputfile == NULL)
	{
		printf("\n Output file could not be opened\n");
		return -1;
	}

	do{
		numread = fscanf(inputfile,"%d %s %s", &uin,lname,fname);
		printf("\n %d. %s", uin, lname);
		fprintf(outputfile, "%s %s %d \n", fname, lname, uin);
	}while(!feof(inputfile));

	fclose(inputfile);
	fclose(outputfile);
	return 0;

}