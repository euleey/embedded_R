#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <linux/input.h>
#include <pthread.h>
#include "led.h"
#include "buzzer.h"
#include "button.h"
#include "fnd.h"
#include "textlcd.h"
#include "libBitmap.h"
#include "bitmapFileHeader.h"
static pthread_t buttonThread_ID;
static int msgID = 0;
static int ledvalue;
void *buttonTheadFunc();
int main(void)
{
	print_bmp("main.bmp");
	/*============init=====================*/
	textlcdinit();
	msgID=buttonLibInit();
	buzzerInit();
	ledLibInit();
    for(ledvalue=0;ledvalue<=3;ledvalue++)
           ledOnOff(ledvalue,1);//처음 볼륨은 4 초기화
	/*============init=====================*/
	pthread_create(&buttonThread_ID, NULL, &buttonTheadFunc, NULL); //버튼 계속확인
    lcdtextwrite("1","Welcome MINIBand");
    lcdtextwrite("2","select button");
	
    while(1){};


  buttonLibExit();
  ledLibExit();
	buzzerExit();
	textlcdexit();
	return 1;
}
void piano()
{
    print_bmp("piano.bmp");
}
void guitar()
{
    print_bmp("guitar.bmp");
}
void drum()
{
    print_bmp("drum.bmp");
}
void set()
{
    print_bmp("main.bmp");
}
void *buttonTheadFunc()
{
    int returnValue = 0;
    BUTTON_MSG_T msgRx;
    printf("====================================================\n");
    while(1){    
    returnValue = msgrcv(msgID, &msgRx, sizeof(int), 0, 0);
    printf("\n");
        if(returnValue<0) printf("fail_receive KEY\n");
     switch(msgRx.keyInput)
         {
            case KEY_VOLUMEUP:Beep();
            printf("Volume up key):");
            if(ledvalue<=7) { ledOnOff(ledvalue,1); ledvalue++;  }
            break;

            case KEY_HOME:Beep();
            printf("Home key):");  
            set();          
            break;

            case KEY_BACK:Beep();      
            printf("PIANO):"); 
            piano();
            break;

            case KEY_SEARCH:Beep();    
            printf("GUITAR):"); 
            guitar()   ;  
            break;

          
            case KEY_MENU:Beep();      
            printf("DRUM):");     
            drum();
            break;

            case KEY_VOLUMEDOWN:Beep();  
            printf("Volume down key):");   
            if(ledvalue>0) {  ledvalue--;  ledOnOff(ledvalue,0); }
            break;
         }
    }
}
