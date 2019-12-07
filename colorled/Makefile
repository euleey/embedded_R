#LED Piano
CC=arm-linux-gnueabi-gcc
AR=arm-linux-gnueabi-ar

all: libMycolorledLib.a colorled1.elf

colorled1.elf: colorledtest.o libMycolorledLib.a colorled.h
	$(CC) colorledtest.o -o colorled1.elf -lMycolorledLib -L. -l MycolorledLib

libMycolorledLib.a: colorled.o
	$(AR) rc libMycolorledLib.a colorled.o

colorled.o: colorled.c colorled.h

#위 세개의 o 파일은 암묵적 makefile 규칙에 의해 자동 생성됨

clean:
	rm -f *.elf *.o *.a
