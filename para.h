#ifndef __PARA_H_
#define __PARA_H_
#include <stdio.h>
#include <stdlib.h>
#define bool char
#define true 1
#define false 0

#define K 8

#define M_TRAIN 150
#define M_TEST 80

#define IMAGE_EDGE 32
#define IMAGE_SIZE (IMAGE_EDGE*IMAGE_EDGE)
#define NUM_CLASS 10
#define N_TRAIN (NUM_CLASS * M_TRAIN)
#define N_TEST (NUM_CLASS * M_TEST)

#define N_DIST N_TRAIN
#endif
