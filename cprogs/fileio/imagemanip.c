#include <stdio.h>
#define W 1178
#define H 786

int readImage(char inputIm[20], int image[H][W]);

int writeImage(char inputIm[20], int image[H][W]);

int Filter(int image[H][W]);

int main()
{
	int image[H][W];	
	readImage("alma.pgm",image);
	Filter(image);
	writeImage("alma3.pgm",image);
	return 0;
}

int readImage(char inputIm[20], int image[H][W])
{

	FILE *inputFIle;
	inputFIle = fopen(inputIm,"r");
	char imtype[10];
	int w,h,maxVal;
	if (inputFIle == NULL)
	{
		printf("\n %s file could not be opened", inputIm);
		return -1;
	}

	fscanf(inputFIle,"%s %d %d %d", imtype, &w, &h, &maxVal);
	printf("\n Reading %d %d %d", w,h, maxVal);
	// loop for reading characters
	for(int i=0;i<H; i++)
		for(int j=0; j< W; j++)
			fscanf(inputFIle,"%d", &image[i][j]);
	
	fclose(inputFIle);		
	return 0;
}

int writeImage(char outputIm[20], int im[H][W])
{
	// creates a new HxW image with the data in the im array

	FILE *outputFIle;
	outputFIle = fopen(outputIm,"w");
	// char imtype[10];
	// int w,h,maxVal;
	if (outputFIle == NULL)
	{
		printf("\n %s file could not be opened for writing", outputIm);
		return -1;
	}

	fprintf(outputFIle,"%s \n %d %d \n %d", "P2", W, H, 255);
	// loop for reading characters
	for(int i=0;i<H; i++)
		for(int j=0; j< W; j++)
			fprintf(outputFIle," %d ", im[i][j]);
	
	fclose(outputFIle);		
	return 0;
}

int Filter(int image[H][W])
{
	for(int i=0;i<H; i++)
		for(int j=0; j< W; j++)
			image[i][j] = 255- image[i][j];
	return 0;
}

