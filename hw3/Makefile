hw3_provided: hw3_provided.h hw3_provided.o hw3_provided.c
	clang -c -Wall -o hw3_provided.o hw3_provided.c

hw1: hw1.h hw1.c
	clang -c -Wall -o hw1.o hw1.c

warmup3: hw3_provided.o hw3_provided.h warmup3.c warmup3_main.c hw1.h hw1.c
	clang -Wall -lpng -o warmup3 hw3_provided.o hw1.c warmup3.c warmup3_main.c -lm

hw3: hw3.h hw3.c hw3_main.c hw3_provided.o hw3_provided.h 
	clang -Wall -lpng -o hw3 hw3.c hw3_main.c hw3_provided.o
