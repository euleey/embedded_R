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

	textlcdinit();
	lcdtextwrite(hi,hi);
	textlcdexit();
	
}
