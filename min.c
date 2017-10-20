#include "min.h"

//in the array distance_long[],put the minimum value to the first position
int min(int distance_long[N_TRAIN])   /*look for the position of min distance*/
{
	int temp=0;

	for(int i=0;i<N_TRAIN;i++)
	{
		if(distance_long[temp]>distance_long[i])
		{
			temp=i;
		}
	}
	return temp;


}
