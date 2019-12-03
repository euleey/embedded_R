#LED Piano
CC=arm-linux-gnueabi-gcc
AR=arm-linux-gnueabi-ar

all: libMyBuzzerLib.a buzzer123.elf

buzzer123.elf: main.o libMyBuzzerLib.a buzzer.h
	$(CC) main.o -o buzzer123.elf -lMyBuzzerLib -L. -l MyBuzzerLib

libMyBuzzerLib.a: buzzer.o
	$(AR) rc libMyBuzzerLib.a buzzer.o

buzzer.o: buzzer.c buzzer.h

#위 세개의 o 파일은 암묵적 makefile 규칙에 의해 자동 생성됨

clean:
	rm -f *.elf *.o *.a
