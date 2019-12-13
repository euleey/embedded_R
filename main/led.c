#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "led.h"
static unsigned int ledValue ;
static int fd = 0;
int ledOnOff(int ledNum,int onoff)
{
	int i = 1;
	i=i<<ledNum;
	if (onoff == 1) ledValue |= i;
	else if(onoff == 0)ledValue = ledValue& (~i);
	else printf("wrong number\n");
	write (fd, &ledValue, 4);
}
int ledLibInit(void)
{
	fd=open("/dev/periled", O_RDWR);
	ledValue = 0;
}
int ledLibExit(void)
{
	ledValue = 0;
	ledOnOff(0,0);
	close(fd);
}
int ledStatus(void)
{
	printf("ledStatus\n");
	for(int i=0;i<8;i++)
	{
		printf("%d led on :%d\n",i,(ledValue>>i)&1);
	}
	printf("\n");
}
