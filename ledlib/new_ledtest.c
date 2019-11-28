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
#define LED_DRIVER_NAME		"/dev/periled"

int main(int argc , char **argv)
{
	int num = 0;int onoff=0;	
	ledLibInit();
	for(int i=0;i<8;i++)
    {
        onoff=1;
        ledOnOff(i,onoff);  
        ledStatus();
        for(int j=0;j<10000000;j++);
    }
for(int i=0;i<8;i++)
    {
        onoff=0;
        ledOnOff(i,onoff);  
        ledStatus();
        for(int j=0;j<10000000;j++);
    }
	
	ledLibExit();
	return 0;
}
