#include "topK.h"
#include "para.h"
void topK(int *g_distances, int * g_dist, int *g_index){
#pragma HLS INTERFACE s_axilite port=g_distances bundle=control
#pragma HLS INTERFACE s_axilite port=g_dist bundle=control
#pragma HLS INTERFACE s_axilite port=g_index bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control
#pragma HLS INTERFACE m_axi depth=65536 port=g_distances bundle=gmem
#pragma HLS INTERFACE m_axi depth=16 port=g_dist bundle=gmem
#pragma HLS INTERFACE m_axi depth=16 port=g_index bundle=gmem0

	int l_dist[K];
#pragma HLS ARRAY_PARTITION variable=l_dist complete dim=1
	int l_index[K];
//1.assign the value and address to the local array l_dist[],l_index[]
	loop_init:for(int i = 0;i<K;i++){
#pragma HLS PIPELINE
		l_dist[i] = g_distances[i];
		l_index[i] = i;
	}
//2.find the topK values
	loop_pipe:for(int i = K;i<N_DIST;i++){
#pragma HLS PIPELINE
		int d = g_distances[i];
		int maxD = d;
		int maxI = -1;

		loop_unroll:for(int j=0;j<K;j++){
			if(l_dist[j] > maxD){
				maxD = l_dist[j];
				maxI = j;
			}
		}
		if(maxI != -1){
			l_dist[maxI] = d;
			l_index[maxI] = i;
		}
	}
	loop_assign:for(int i = 0;i<K;i++){
#pragma HLS PIPELINE
		g_dist[i] = l_dist[i];
		g_index[i] = l_index[i];
	}

}
