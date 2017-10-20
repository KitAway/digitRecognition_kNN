#include "readtestcode.h"
//#include "para.h"
//char testdigit[N_TEST];
void readtestcode(bool a[1024], char testdigit[N_TEST])
{
  // int counter = 0;
  /*  for(int x = 0; x<10;x++)
    {
        for(int y = 0; y<M_TEST;y++)
        {
	    sprintf(testdigit,"/home/guo/Desktop/example/DIGIT_RECOGNITION/testDigits/%d_%d.txt",x,y);
*/
	    FILE *fp = fopen(testdigit,"r");
	    
	     for(int i=0;i<32;i++)     //i means the number of rows in the text file
		{
			for(int j=0;j<32;j++)  //j means the number of colums in the text file
			{
				char temp;	
				int charvaluel = fscanf(fp,"%c",&temp);
				a[i*32+j]=temp-'0'; //put the character(eg 0,1)to an array, from 0 to 32,33 to 64,...1024,so the total length of array is 1024 
			     //   printf("%d",a[k][i*32+j]);
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


