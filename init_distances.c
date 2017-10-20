#include "topk_distance.h"

//bool a[][IMAGE_SIZE] stands for test file, bool b[][IMAGE_SIZE] stands for train files
void init_distances(bool a[IMAGE_SIZE],bool b[N_TRAIN][IMAGE_SIZE],int distance[N_TRAIN])
{       
	for(int j=0;j<N_TRAIN;j++)
	{
		int temp=0;
		for(int k=0;k<IMAGE_SIZE;k++)
		{
			temp+=(a[k]-b[j][k])*(a[k]-b[j][k]);
		}
		//put the distances between each train file and the test file to distance[] array
		distance[j]=temp;
	}

}
