CC=arm-linux-gnueabi-gcc
AR=arm-linux-gnueabi-ar

all: bitmaptest.elf
	cp *.elf ~/
clean:
	rm -f *.elf *.o *.a
	
libMyLib.a: libBitmap.o 
	$(AR) rc libMyLib.a libBitmap.o 

libBitmap.o: libBitmap.h libBitmap.c bitmapFileHeader.h
	$(CC) -O3 -o libBitmap.o -c libBitmap.c

bitmaptest.elf: libMyLib.a bitmaptest.c
	$(CC) -O3 bitmaptest.c -L. -l MyLib -o bitmaptest.elf 
