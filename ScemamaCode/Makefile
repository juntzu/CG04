CC=gcc
CFLAGS=
FC=ifort 
FFLAGS=-O2 -ipo
SSE2=-xSSE2
AVX=-xAVX
PIN=taskset -c 0

.PHONY: all

all: test_h2o_avx

test_h2o_avx: rdtsc.o $(wildcard *.f90) test_h2o_sse2
	@cp main/test.f90 main.f90
	$(FC) $(FFLAGS) $(AVX) *.f90 rdtsc.o -o $@
	@rm main.f90

rdtsc.o: rdtsc.c
	$(CC) $(CFLAGS) -c $^

tests: all
	@echo ==============
	@echo H2O, AVX
	@echo ==============
	$(PIN) ./test_h2o_avx

clean:
	rm -f *.o test_*
