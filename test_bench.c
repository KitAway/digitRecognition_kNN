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
	bool train_code[N_TRAIN][1024];
	bool test_code[1024];
//step2:define the distance_long array
	int distances[N_DIST];

	char testdigit[N_TEST];
	
//step3:read the train files and test files
         readtraincode(train_code);


//step4:calculate the distance between the train files and each test file
     /*   for(int i=0; i<N_TEST;i++)
        {*/
    for(int x = 0; x<10;x++)
    {
        for(int y = 0; y<M_TEST;y++)
        {
	    sprintf(testdigit,"/home/guo/Desktop/example/2017-10-20/DIGIT_RECOGNITION/testDigits/%d_%d.txt",x,y);

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

          int label[K],order[K];
				int count[10]={0,0,0,0,0,0,0,0,0,0};
				for(int i=0;i<K;i++)
				{  
					int j=-1;
					label[i] = (r_index[i])/20;
					order[i] = (r_index[i])%20;
				//	printf("r_dist[topK_%d]=%d,r_index[topK_%d]=%d,label_order=%d_%d\n",i,r_dist[i],i,r_index[i],label[i],order[i]);
					count[label[i]]++;
                                 //       printf("--------------------\n");
				//	printf("count[label[topk%d]=%d]=%d\n",i,label[i],count[label[i]]);
				}
				int max = count[0];
				int index1 =0;
				for(int i=0; i<10;i++)
				{   //    printf("count[i=%d]=%d\n",i,count[i]);
					if(max < count[i])
					{	max = count[i];
					        index1 = i;
                                        }
                                        
                                        
					//  printf("index1=%d,max=%d\n",index,max);
				}
				printf("x=%d,y=%d,index1=%d,appearance=%d,recognition percentage=%.0f%%\n",x,y,index1,max,100*max*1.0/K);
                        //        printf("x=%d,index=%d\n",x,index1);

                                if(x==index1)
                                {
                                  
                                printf("x=%d=index1=%d,success\n",x,index1);
                                 success_count ++;
                                }
       }
                                
    }           
                                 printf("success_count2=%d\n",success_count);
                                 printf("success rate=%.0f%%\n",100*success_count/N_TEST);
	return 0;
}

