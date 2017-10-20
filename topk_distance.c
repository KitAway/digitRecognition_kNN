#include "topk_distance.h"
#include <limits.h>
void topk_distance(int *init_distances, int* dist, int *index){
	int leastMin = -1, d;
	for(int i=0;i<K;i++)
        {
		int min = INT_MAX;
		int l_index = 0;
		for(int j=0;j<N_DIST;j++)
                {
			d = init_distances[j];
			if(d < min && d > leastMin)
                        {
				min = d;
				l_index = j;
			}
		}
		dist[i] = min;
		index[i] = l_index;
		leastMin = min;
       	}
}

