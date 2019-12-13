all : temp.c
	arm-linux-gnueabi-gcc -c temp.c -o temp.o 
	arm-linux-gnueabi-ar rc libMyTemp.a temp.o
	arm-linux-gnueabi-gcc -o new_temptest -L. -l MyTemp -lpthread  new_temptest.c -L. -l MyTemp -lpthread
