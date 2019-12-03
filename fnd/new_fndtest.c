#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
#include <pthread.h>
#include <linux/input.h>
#include <unistd.h> // for open/close
#include <fcntl.h> // for O_RDWR
#include <sys/ioctl.h> // for ioctl
#include "fnd.h"
#define MODE_STATIC_DIS 0
#define MODE_TIME_DIS 1
#define MODE_COUNT_DIS 2

int main(int argc , char **argv)
{
	int number;
	int counter;
	int mode;
	int dotflag;
	
	if(argv[1][0] == 's')
	{
		mode==MODE_STATIC_DIS;
		number = atoi(argv[2]);
    	fndDisp(number,0);
	}
	
	else if(argv[1][0] == 't')
	{
		mode==MODE_TIME_DIS;
		struct tm *ptmcur;
		time_t tTime;
		if(-1== time(&tTime))
			return -1;
			
		ptmcur = localtime(&tTime);
		
	number = ptmcur->tm_hour*10000;
	number += ptmcur->tm_min*100;
	number += ptmcur->tm_sec;
	
	fndDisp(number,0b1010);
	}
	
	else if(argv[1][0] == 'c')
	{
		mode==MODE_COUNT_DIS;
		number = atoi(argv[2]);
		counter=0;
		while(1)
		{
			if(!fndDisp(counter,0))
			break;
			
			counter++;
			sleep(1);
			if(counter>number)
				break;
		}
	}
}
	
	



