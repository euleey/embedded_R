all : button.h button.c
	arm-linux-gnueabi-gcc -c button.c -o button.o 
	arm-linux-gnueabi-ar rc libMyButton.a button.o
	arm-linux-gnueabi-gcc -o new_buttentest -L. -l MyButton -lpthread  new_buttontest.c -L. -l MyButton -lpthread 
