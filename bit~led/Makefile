#LED Piano
CC=arm-linux-gnueabi-gcc
AR=arm-linux-gnueabi-ar

all: libMyLib.a piano.elf 

piano.elf: main.c libMyLib.a 
	$(CC) main.c -o piano.elf -lMyLib -L. -lpthread

libMyLib.a: button.o buzzer.o led.o fnd.o textlcd.o libBitmap.o
	$(AR) rc libMyLib.a button.o buzzer.o led.o fnd.o textlcd.o libBitmap.o

libBitmap.o: libBitmap.h libBitmap.c bitmapFileHeader.h
button.o: button.c button.h
buzzer.o: buzzer.c buzzer.h
led.o: led.c led.h
fnd.o: fnd.c fnd.h
textlcd.o : textlcd.c textlcd.h
#위 세개의 o 파일은 암묵적 makefile 규칙에 의해 자동 생성됨

clean:
	rm -f *.elf *.o *.a
