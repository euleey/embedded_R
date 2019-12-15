#
#ED Piano
CC=arm-linux-gnueabi-gcc
AR=arm-linux-gnueabi-ar

all: libMyLib.a main.elf 

main.elf: main.c libMyLib.a 
	$(CC) main.c -o main.elf -lMyLib -L. -lpthread

libMyLib.a: button.o buzzer.o led.o fnd.o textlcd.o libBitmap.o Accel.o temp.o colorled.o Touch.o
	$(AR) rc libMyLib.a button.o buzzer.o led.o fnd.o textlcd.o libBitmap.o Accel.o temp.o colorled.o Touch.o

libBitmap.o: libBitmap.h libBitmap.c bitmapFileHeader.h
button.o: button.c button.h
buzzer.o: buzzer.c buzzer.h
led.o: led.c led.h
fnd.o: fnd.c fnd.h
textlcd.o : textlcd.c textlcd.h
Accel.o: Accel.c Accel.h
temp.o: temp.c temp.h
colorled.o : colorled.c colorled.h	
Touch.o : Touch.c Touch.h
#위 세개의 o 파일은 암묵적 makefile 규칙에 의해 자동 생성됨

clean:
	rm -f *.elf *.o *.a
