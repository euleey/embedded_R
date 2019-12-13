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
//char * spi_read_lm74(int file)
int temp(void){
	char *buffer;
	int file;
	

	
	__u8 mode, lsb, bits;
	__u32 speed=20000;
		if ((file = open("/dev/spidev1.0",O_RDWR)) < 0) {
			printf("Failed to open the bus."); printf ("ErrorType:%d\r\n",errno); exit(1); }
			
			//possible modes: mode |= SPI_LOOP; mode |= SPI_CPHA; mode |= SPI_CPOL; mode |= SPI_LSB_FIRST; mode |= SPI_CS_HIGH;
			//mode |= SPI_3WIRE; mode |= SPI_NO_CS; mode |= SPI_READY;
			
			mode = SPI_3WIRE ;
			if (ioctl(file, SPI_IOC_RD_MODE, &mode) < 0)
				{ perror("SPI rd_mode"); return 0; }
			if (ioctl(file, SPI_IOC_RD_LSB_FIRST, &lsb) < 0)
				{ perror("SPI rd_lsb_fist"); return 0; }
			if (ioctl(file, SPI_IOC_RD_BITS_PER_WORD, &bits) < 0)
				{perror("SPI bits_per_word"); return 0; }
	
//			buffer = (char *)spi_read_lm74(file); //already Read,

		 int len;
                memset(gbuf, 0, sizeof( gbuf));
                len = read(file, gbuf, 2); //Read two byte!
                if (len !=2)
                {
                        perror("read error");
                        return 0;
                }
                buffer = gbuf;
		int value = (buffer[0] << 8 ) | buffer[1];		//Big Endian->Little Endian
		if ( value < 0 )
	{	 
		value = (int)(value^(-1)); 
	}
	value >>= 7; //1의 자리에서 버림	
	close(file);
	return value;
}
