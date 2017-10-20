FILES=para.h topk_distance.c init_distances.c min.c readtestcode.c readtraincode.c test_bench.c topK.c

TARGET=result
$(TARGET): $(FILES)
	gcc -g -o $@ $^ 
clean:
	@if [ -f $(TARGET) ]; then rm $(TARGET); 	fi
