#include <stdio.h>
/* Image dimension are hardcoded. Will work only for Alma Mater :) */
#define W 1178 
#define H 786

int readImage(char * inputfile, int image[H][W]);
void Filter(int im[H][W]);

int writeImage(char *outputfile, int im[H][W]);

int main(){
	int image[H][W];	
	readImage("alma.pgm",image);
	Filter(image);
	Filter(image);
	Filter(image);
	writeImage("alma2.pgm", image);
	return 0;
}

int readImage(char * inputFileName, int image[H][W]){
	FILE * inputfile; 
	char fileType[5];
	int w,h,maxVal;

	inputfile = fopen(inputFileName, "r");
	if (inputfile == NULL){
		printf("\n Unable to open input file\n");
		return -1;
	}
	fscanf(inputfile,"%s",fileType);
	fscanf(inputfile,"%d %d %d",&w,&h,&maxVal);

	printf("\n File type:%s",fileType);
	printf("\n Width = %d Height = %d Max = %d",w,h,maxVal);

	for (int i=0;i<H;i++)
		for (int j=0;j<W;j++)
		{
			fscanf(inputfile,"%d",&image[i][j]);
			printf(" %d ", image[i][j]);
		}

	fclose(inputfile);
	return 0;
}

int writeImage(char *outputFileName, int im[H][W])
{
	FILE * outputfile;
	outputfile = fopen(outputFileName, "w");
	if (outputfile == NULL){
		printf("\n Unable to open output file\n");
		return -1;
	}
	fprintf(outputfile,"%s","P2");
	fprintf(outputfile,"\n %d %d %d",W,H,255);

	for (int i=0;i<H;i++)
		for (int j=0;j<W;j++)
		{
			fprintf(outputfile," %d ",im[i][j]);
		}
	fclose(outputfile);
	return 0;
}


void Filter(int im[H][W])
{
	int imold[H][W];
	for (int i=0;i<H;i++)
		for (int j=0;j<W;j++)
			imold[i][j] = im[i][j];
	for (int i=0;i<H;i++)
		for (int j=0;j<W;j++)
		{
			if (j>1 && j < W-1)
//				im[i][j] = (3*imold[i][j-2]+2*imold[i][j-1])-(2*imold[i][j+1] + 3*imold[i][j+2]);
				im[i][j] = ((imold[i-1][j-1]+imold[i][j-1])+(imold[i+1][j+1] + imold[i][j+1]))/4;

		}
	return;
}

