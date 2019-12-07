#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <linux/input.h>

#include "led.h"
#include "buzzer.h"
#include "button.h"
#include "fnd.h"
#include "textlcd.h"
#include "libBitmap.h"
#include "bitmapFileHeader.h"

static int msgID = 0;

int main(void)
{
	printf ("suhyun's piano ^^...!\r\n");
	if (ledLibInit()== 0)
	{
		printf ("LED Fail...^^\r\n");
		return 0;
	}
	if (buzzerInit() == 0)
	{
		printf ("Buzzer Fail...^^\r\n");
		return 0;
	}
	if (textlcdinit() == 0)
	{
		printf ("TextLCD Fail...^^\r\n");
		return 0;
	}
	if (buttonLibInit() == 0)
	{
		printf ("Button Fail...^^\r\n");
		return 0;
	}
   int msgID = msgget (MESSAGE_ID, IPC_CREAT|0666);
	BUTTON_MSG_T msgRx;
   
	while (1)
	{
		msgrcv(msgID, &msgRx, sizeof(int), 0,0);

		printf ("ReceivedMessage:%d",msgRx.keyInput);

		int scale = 0;
		switch(msgRx.keyInput)
		{
			case KEY_HOME:
              lcdtextwrite("1","hi"); 
				printf("Volume up key):");
              print_bmp("flower.bmp");
				scale = 0;
              fndDisp(1,1); 
			break;
			case KEY_BACK:
              lcdtextwrite("2","zzz"); 
				printf("Home key):"); 
				scale = 1;
              fndDisp(2,1);
			break;
			case KEY_SEARCH:
              lcdtextwrite("1","zzz");  
				printf("Search key):"); 
				scale = 2;
              fndDisp(3,1);
			break;
			case KEY_MENU:
              lcdtextwrite("2","zzzzz");  
				printf("Back key):");
				scale = 3;
              fndDisp(4,1);
			break;
			case KEY_VOLUMEUP:
              lcdtextwrite("1","zzzzzz");  
				printf("Menu key):"); 
				scale = 4;
              fndDisp(5,1);
			break;
			case KEY_VOLUMEDOWN:
              lcdtextwrite("2","zzzzzzzz"); 
				printf("Volume down key):");
				scale = 5;
              fndDisp(6,1);
			break;
		}

		if (msgRx.keyInput != 0)
		{
			ledOnOff(scale, 1);
			buzzerPlaySong(scale);
		}
		else
		{
			ledOnOff(scale, 0);
			buzzerStopSong();			
		}
		
	}

	ledLibExit();
	buzzerExit();
	buttonLibExit();
	textlcdExit();
	return 1;
}
