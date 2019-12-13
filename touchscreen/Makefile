Touchtest.elf : Touch.c Touch.h Touchtest.c
	arm-linux-gnueabi-gcc -c Touch.c -o Touch.o 
	arm-linux-gnueabi-ar rc libMyTouch.a Touch.o
	arm-linux-gnueabi-gcc -o Touchtest.elf -L. -l MyTouch -lpthread  Touchtest.c -L. -l MyTouch -lpthread                                
