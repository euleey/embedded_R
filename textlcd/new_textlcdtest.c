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
#define LINE_NUM 2
#define COLUMN_NUM 16
#define LINE_BUFF_NUM 20//fordummy
#define CMD_WRITE_STRING 0x20

int main(int argc,char**argv)
{
	unsigned int linenum=0;
	stTextLCD stlcd;	//stTextLCD구조체를가지고드라이버와인터페이스
	int fd;
	int len;
	memset(&stlcd,0,sizeof(stTextLCD));		//구조체초기화
	
	linenum = strtol(argv[1],NULL,10);
	len=strlen(argv[2]);
	
	lineselect(linenum);
	if(len>COLUMN_NUM)
		memcpy(stlcd.TextData[stlcd.cmdData-1],argv[2],COLUMN_NUM);
	else
		memcpy(stlcd.TextData[stlcd.cmdData-1],argv[2],len);
	memorycopy();
	textlcdinit();
	stlcd.cmd=CMD_WRITE_STRING;
	textlcdinit();
	lcdtextwrite();
	textlcdexit();
	
	return 0;
}
