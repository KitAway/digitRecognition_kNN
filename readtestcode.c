#include "readtestcode.h"
//#include "para.h"
//char testdigit[N_TEST];
void readtestcode(bool a[IMAGE_SIZE], char testdigit[N_TEST])
{
	// int counter = 0;
	/*  for(int x = 0; x<10;x++)
			{
			for(int y = 0; y<M_TEST;y++)
			{
			sprintf(testdigit,"/home/guo/Desktop/example/DIGIT_RECOGNITION/testDigits/%d_%d.txt",x,y);
			*/
	FILE *fp = fopen(testdigit,"r");

	for(int i=0;i<IMAGE_EDGE;i++)     //i means the number of rows in the text file
	{
		for(int j=0;j<IMAGE_EDGE;j++)  //j means the number of colums in the text file
		{
			char temp;	
			int charvaluel = fscanf(fp,"%c",&temp);
			a[i*IMAGE_EDGE+j]=temp-'0'; //put the character(eg 0,1)to an array, from 0 to IMAGE_EDGE,33 to 64,...IMAGE_SIZE,so the total length of array is IMAGE_SIZE 
			//   printf("%d",a[k][i*IMAGE_EDGE+j]);
			//printf("\n");
		}
		char temp;
		int skip = fscanf(fp,"%[^\n]%*c",&temp);
	}



	fclose(fp);
	//    counter++;
	//}
	// }
}


