#include <string.h>
#include "topk_distance.h"
#include "min.h"
#include "readtraincode.h"
#include "readtestcode.h"
#include "init_distances.h"
#include "topK.h"
int main()
{
	int success_count =0;
	int dist[K],r_dist[K];
	int index[K],r_index[K];
	//step1:define two bool(0 or 1) type two-dimensional-array
	bool train_code[N_TRAIN][IMAGE_SIZE];
	bool test_code[IMAGE_SIZE];
	//step2:define the distance_long array
	int distances[N_DIST];

	char testdigit[]="testDigits/10_2000.txt";

	//step3:read the train files and test files
	readtraincode(train_code);


	//step4:calculate the distance between the train files and each test file
	for(int digit = 0; digit<NUM_CLASS;digit++)
	{
		for(int _order = 0; _order<M_TEST;_order++)
		{
			sprintf(testdigit,"testDigits/%d_%d.txt",digit,_order);

			readtestcode(test_code, testdigit);

			init_distances(test_code,train_code,distances);

			//step5:sort the first TOPK value in distance based on the init_distances array
			for(int i=0; i<K; i++)
			{
				dist[i] = 0;
				index[i] = 0;
			}            
			topk_distance(distances,r_dist,r_index);  

			//step6:sort the topK value in the topK based on the distance array
			topK(distances, dist, index);       

			//step7.assign the topK values to the local array
			for(int i=0;i<K;i++)
			{
				//            printf("r_dist[%d]=%d\n",i,r_dist[i]);
			}

			for(int i=0;i<K;i++)
			{
				//              printf("dist[%d]=%d\n",i,dist[i]);

			}

			int label,order;
			int count[NUM_CLASS]={0,0,0,0,0,0,0,0,0,0};
			for(int i=0;i<K;i++)
			{  
				int j=-1;
				label = (r_index[i])/M_TRAIN;
				order = (r_index[i])%M_TRAIN;
				//	printf("r_dist[topK_%d]=%d,r_index[topK_%d]=%d,label_order=%d_%d\n",i,r_dist[i],i,r_index[i],label[i],order[i]);
				count[label]++;
				//       printf("--------------------\n");
				//	printf("count[label[topk%d]=%d]=%d\n",i,label[i],count[label[i]]);
			}
			int max = count[0];
			int index1 =0;
			for(int i=0; i<NUM_CLASS;i++)
			{   //    printf("count[i=%d]=%d\n",i,count[i]);
				if(max < count[i])
				{	
					max = count[i];
					index1 = i;
				}


				//  printf("index1=%d,max=%d\n",index,max);
			}
//			 printf("digit=%d,_order=%d,index1=%d,appearance=%d,recognition percentage=%.0f%%\n",digit,_order,index1,max,100*max*1.0/K);
			//        printf("digit=%d,index=%d\n",digit,index1);

			if(digit==index1)
			{
//				printf("file:%d_%d.txt,\tlabel=%d, guess digit=%d, success.\n",digit,_order,digit,index1);
				success_count ++;
			}
			else 
			{
	//			printf("file:%d_%d.txt,\tlabel=%d, guess digit=%d, failed.\n",digit,_order,digit,index1);
			}
		}

	}           
	printf("success rate=%.0f%%\n",100*success_count/(N_TEST*1.0));
	return 0;
}
