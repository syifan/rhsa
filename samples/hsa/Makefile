all: vector_add.hsaco vector_add

vector_add.hsaco:vector_add.cl
	clang-ocl -mcpu=fiji -o $@ $^

vector_add.o:vector_add.c
	g++ $^ -c -o $@ -I/opt/rocm/hsa/include

vector_add: vector_add.o
	g++ $^ -o $@ -L/opt/rocm/lib -lhsa-runtime64

