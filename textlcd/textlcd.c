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
#ifndef __TEXTLCD_DRV_H__
#define __TEXTLCD_DRV_H__
#define LINE_NUM 2
#define COLUMN_NUM 16
#define LINE_BUFF_NUM 20//fordummy
#define MODE_CMD 0
#define MODE_DATA 1
#define CMD_DISPLAY_MODE 0x10
#define BIT_DISPLAY_MODE_CURSOR_DISP 0x01
#define BIT_DISPLAY_MODE_CURSOR_BLINK 0x02
#define BIT_DISPLAY_MODE_DISP_ENABLE 0x04
#define CMD_CURSOR_MOVE_MODE 0x11
#define CURSOR_MOVE_MODE_ENABLE 0x01
#define CURSOR_MOVE_MODE_RIGHT_DIR 0x02
#define CMD_CURSOR_MOVE_POSITION 0x12
#define CURSOR_MOVE_X_MASK 0x3F
#define CURSOR_MOVE_Y_MASK 0xC0
#define CMD_WRITE_STRING 0x20
#define CMD_DATA_WRITE_BOTH_LINE 0
#define CMD_DATA_WRITE_LINE_1 1 
#define CMD_DATA_WRITE_LINE_2 2
#define CMD_TEST_GPIO_HIGH 0x30
#define CMD_TEST_GPIO_LOW 0x31
#define TEXTLCD_DRIVER_NAME "/dev/peritextlcd"
typedef struct TextLCD_tag
{
	unsigned char cmd;//
	unsigned char cmdData;
	unsigned char reserved[2];
	
	char TextData[2][20];
}stTextLCD,*pStTextLCD;
int lineselect(int linenum);
int lcdtextwrite(void);
int lineselect(int linenum);
int memorycopy(void);
int textlcdinit(void);
int lcdtextwrite(void);
int textlcdexit(void);

#endif// __TEXTLCD_DRV_H__


//=============textlcddrv.h 과 동일 내용================
stTextLCD stlcd;
static int fd;
static int len;


int lineselect(int linenum)
{
	
	printf("linenum:%d\n",linenum);
	
	if(linenum==1)
		stlcd.cmdData=CMD_DATA_WRITE_LINE_1;
	else if(linenum==2)
		stlcd.cmdData=CMD_DATA_WRITE_LINE_2;
	else
	{
		printf("linenum:%dwrong.range(1~2)\n",linenum);
		return 1;
	}
}

int memorycopy(void)
{
	
}

int textlcdinit(void)
{
	fd=open(TEXTLCD_DRIVER_NAME,O_RDWR);//opendriver
}

int lcdtextwrite(void)
{
	write(fd,&stlcd,sizeof(stTextLCD));
}

int textlcdexit(void)
{
	close(fd);
}
	


