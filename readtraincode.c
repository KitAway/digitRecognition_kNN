
#include "readtraincode.h"
char traindigit[N_TRAIN];


void readtraincode(bool b[N_TRAIN][1024])
{
    
    int counter = 0;
    for(int x = 0; x<10;x++)
    {
        for(int y = 0; y<M_TRAIN;y++)
        {
	    sprintf(traindigit,"/home/guo/Desktop/example/2017-10-20/DIGIT_RECOGNITION/trainingDigits/%d_%d.txt",x,y);
	    FILE *fp = fopen(traindigit,"r");
		if(fp==NULL)
                {
			printf("OPEN FAILD\n");
		}
	        for(int i=0;i<32;i++)     //i means the number of rows in the text file
		{
			for(int j=0;j<32;j++)  //j means the number of colums in the text file
			{
				char temp;	
				int charvalue = fscanf(fp,"%c",&temp);
				b[counter][i*32+j]=temp-'0'; //put the character(eg 0,1)to an array, from 0 to 32,33 to 64,...1024,so the total length of array is 1024    
                        }
			char temp;
		        int skip = fscanf(fp,"%[^\n]%*c",&temp);
		}

        //   printf("%d",b[0][x*32+0]);       
	    fclose(fp);
	    counter++;
        }
        
     }
}


