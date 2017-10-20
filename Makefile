FILES=topk_distance.c init_distances.c min.c readtestcode.c readtraincode.c test_bench.c topK.c
result: $(FILES)
	gcc -O3 -g -o $@ $^ 
	./result

