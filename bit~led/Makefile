#LED Piano
CC=arm-linux-gnueabi-gcc
AR=arm-linux-gnueabi-ar

all: libMyLib.a piano.elf bitmaptest.elf

piano.elf: main.o libMyLib.a button.h buzzer.h led.h fnd.h textlcd.h
	$(CC) main.o -o piano.elf -lMyLib -L. -lpthread

libMyLib.a: button.o buzzer.o led.o fnd.o textlcd.o libBitmap.o
	$(AR) rc libMyLib.a button.o buzzer.o led.o fnd.o textlcd.o libBitmap.o

libBitmap.o: libBitmap.h libBitmap.c bitmapFileHeader.h
	$(CC) -O3 -o libBitmap.o -c libBitmap.c

bitmaptest.elf: libMyLib.a bitmaptest.c
	$(CC) -O3 bitmaptest.c -L. -l MyLib -o bitmaptest.elf 
	
button.o: button.c button.h
buzzer.o: buzzer.c buzzer.h
led.o: led.c led.h
fnd.o: fnd.c fnd.h
textlcd.o : textlcd.c textlcd.h
#위 세개의 o 파일은 암묵적 makefile 규칙에 의해 자동 생성됨

clean:
	rm -f *.elf *.o *.a
