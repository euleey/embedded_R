all : led.h led.c
	arm-linux-gnueabi-gcc -c led.c -o led.o 
	arm-linux-gnueabi-ar rc libMyLed.a led.o
	arm-linux-gnueabi-gcc -o new_ledtest -L. -l MyLed new_ledtest.c -L. -l MyLed
