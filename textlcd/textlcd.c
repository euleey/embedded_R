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
#include "textlcddrv.h"
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>


stTextLCD stlcd;
static int fd;
static int len;
static int COLUMN_NUM;

int textlcdinit(void)
{
	fd=open(TEXTLCD_DRIVER_NAME,O_RDWR);//opendriver
    if(fd<0)
    {
    perror("driver (//dev//peritextled) open error/\n");
    return 1;
    }
    memset(&stlcd,0,sizeof(stTextLCD)); //구조체 초기화
}

int lcdtextwrite(char *str1, char *str2)
{
    len = strlen(str1);
    
    if(str1!=NULL,str2=NULL){
       stlcd.cmdData=CMD_DATA_WRITE_LINE_1;
       
    } 
    else if (str1=NULL,str2!=NULL){
       stlcd.cmdData=CMD_DATA_WRITE_LINE_2;
    }
    else if (str1=NULL,str2=NULL){
    
    }
    else
	{
		printf("linenum wrong.range(1~2)\n");
		return 1;
	}
    if(len > COLUMN_NUM)
    {
        memcpy(stlcd.TextData[stlcd.cmdData - 1], len, COLUMN_NUM);
    }
    else
        memcpy(stlcd.TextData[stlcd.cmdData - 1], len, len);
	write(fd,&stlcd,sizeof(stTextLCD));
}

int textlcdexit(void)
{
	close(fd);
   return 0;
}
	


