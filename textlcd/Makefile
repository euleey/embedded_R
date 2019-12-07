all : textlcd.h textlcd.c
	arm-linux-gnueabi-gcc -c textlcd.c -o textlcd.o 
	arm-linux-gnueabi-ar rc libMytextlcd.a textlcd.o
	arm-linux-gnueabi-gcc -o new_textlcdtest -L. -l Mytextlcd new_textlcdtest.c -L. -l Mytextlcd
