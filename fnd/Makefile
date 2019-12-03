all : fnd.h fnd.c
	arm-linux-gnueabi-gcc -c fnd.c -o fnd.o 
	arm-linux-gnueabi-ar rc libMyfnd.a fnd.o
	arm-linux-gnueabi-gcc -o new_fndtest -L. -l Myfnd -lpthread  new_fndtest.c -L. -l Myfnd -lpthread 
