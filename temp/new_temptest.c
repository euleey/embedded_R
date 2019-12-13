#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include "temp.h"

char gbuf[10];

int main(int argc, char **argv)
{
	char *buffer;
	int file;
	file= spi_init("/dev/spidev1.0"); //dev
	buffer = (char *)spi_read_lm74(file); //already Read,
	buffer = gbuf;
	close(file);
	
	int value = (buffer[0] << 8 ) | buffer[1];		//Big Endian->Little Endian
	if ( value < 0 )
	{	 
		value = (int)(value^(-1)); 
	}
	value >>= 7; //1의 자리에서 버림
	printf("%d \n", value);
	return 0;
}

