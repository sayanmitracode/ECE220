#include <stdio.h>

int main(){
	FILE * inputfile, *outputfile; 
	char inputFileName[20] = "ece220.csv";
	int uin;
	char lname[20];
	char fname[20];
	int numread =0;
	inputfile = fopen(inputFileName, "r");
	if (inputfile == NULL){
		printf("\n Unable to open input file\n");
		return -1;
	}
	outputfile = fopen("output.txt", "w");
	if (outputfile == NULL){
		printf("\n Unable to open output file\n");
		return -1;
	}

	printf("\n File %s opened both files successfully\n", inputFileName);
	do{
		numread = fscanf(inputfile,"%d %s %s",&uin,lname,fname);
		if (numread >0){
			printf("\n%d, ,%s,%s",uin,lname,fname);
			fprintf(outputfile, "\n %d. %s", uin, lname);
		}
	}while (numread>0);

	fclose(inputfile);
	fclose(outputfile);
	return 0;
}