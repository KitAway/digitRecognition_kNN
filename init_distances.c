#include "topk_distance.h"

//bool a[][1024] stands for test file, bool b[][1024] stands for train files
void init_distances(bool a[1024],bool b[N_TRAIN][1024],int distance[N_TRAIN])
{       printf("\n");
	//printf("--------------------\n");
	
	     for(int j=0;j<N_TRAIN;j++)
	     {
                 int temp=0;
		 for(int k=0;k<1024;k++)
		 {
			temp+=(a[k]-b[j][k])*(a[k]-b[j][k]);
		 }
//put the distances between each train file and the test file to distance[] array
		 distance[j]=temp;
	     }
	
}
