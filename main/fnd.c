#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
#include <linux/input.h>
#include <unistd.h> // for open/close
#include <pthread.h>
#include <fcntl.h> // for O_RDWR
#include <sys/ioctl.h> // for ioctl
#include "fnd.h"
//=============fnddrv.h 과 동일 내용================
#ifndef __FND_DRV_H__
#define __FND_DRV_H__
#define MAX_FND_NUM 6
#define FND_DATA_BUFF_LEN (MAX_FND_NUM + 2)
#define FND_DRIVER_NAME "/dev/perifnd"
#define MODE_STATIC_DIS 0
#define MODE_TIME_DIS 1
#define MODE_COUNT_DIS 2
int fndDisp(int num,int dotflag);
typedef struct FNDWriteDataForm_tag
{
	char DataNumeric[FND_DATA_BUFF_LEN];//숫자0-9
	char DataDot[FND_DATA_BUFF_LEN];//숫자0or1
	char DataValid[FND_DATA_BUFF_LEN];//숫자0or1
}stFndWriteForm,*pStFndWriteForm;		//*p는 포인터(?)

#endif// __FND_DRV_H__
//=============fnddrv.h 과 동일 내용================
//=============fndDisp 함수 본체===================
int fndDisp(int num,int dotflag)			//0-999999숫자,비트로인코딩된doton/off
{
	int fd;
	int temp,i;
	stFndWriteForm stWriteData;
	for(i=0;i<MAX_FND_NUM;i++)
	{
		stWriteData.DataDot[i] = (dotflag&(0x1<<i))?1:0;
		stWriteData.DataValid[i]=1;
	}
			//if6fnd
	temp=num%1000000;stWriteData.DataNumeric[0]=temp/100000;
	temp=num%100000;stWriteData.DataNumeric[1]=temp/10000;
	temp=num%10000;stWriteData.DataNumeric[2]=temp/1000;
	temp=num%1000;stWriteData.DataNumeric[3]=temp/100;
	temp=num%100;stWriteData.DataNumeric[4]=temp/10;
	stWriteData.DataNumeric[5]=num%10;

	fd=open(FND_DRIVER_NAME,O_RDWR);
	if(fd<0)
	{
		perror("driveropenerror.\n");
		return 0;
	}
	write(fd, &stWriteData, sizeof(stFndWriteForm));
	close(fd);
	
	return 1;
}
//=============fndDisp 함수 본체===============

