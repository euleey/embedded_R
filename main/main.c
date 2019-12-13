#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <linux/input.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include "led.h"
#include "buzzer.h"
#include "button.h"
#include "fnd.h"
#include "textlcd.h"
#include "libBitmap.h"
#include "bitmapFileHeader.h"
#include "Accel.h"
#include "temp.h"
static pthread_t buttonThread_ID;
static pthread_t AccelThread_ID;
static int msgID = 0;
static int ledvalue;
void *buttonTheadFunc();
void *AccelThreadFunc();
void set();
void piano();
void guitar();
void drum();
int x,y;
int main(void)
{
   set();
   /*============init=====================*/
   textlcdinit();
   msgID=buttonLibInit();
   buzzerInit();
   ledLibInit();
    for(ledvalue=0;ledvalue<=3;ledvalue++)
        ledOnOff(ledvalue,1);//처음 볼륨은 4 초기화
   /*============init=====================*/
   pthread_create(&buttonThread_ID, NULL, &buttonTheadFunc, NULL); //버튼 계속확인
   pthread_create(&AccelThread_ID,NULL,&AccelThreadFunc,NULL);
    while(1){
		x=50;y=50;usleep(200000);
		x=150;y=50;usleep(200000);
		x=250;y=50;usleep(200000);
		x=350;y=50;usleep(200000);
		x=450;y=50;usleep(200000);
		x=550;y=50;usleep(200000);
		};


    buttonLibExit();
     ledLibExit();
   buzzerExit();
   textlcdexit();
   return 1;
}
void piano()
{
   lcdtextwrite("1","====PIANO====     ");
   print_bmp("./bmp/piano.bmp");
   while(1)
   {
		if((x>0)&&(x<100)&&(y>0)&&(y<200))
		{system("aplay ./wav/piano/25c.wav");}
		else if((x>100)&&(x<200)&&(y>0)&&(y<200))
		{system("aplay ./wav/piano/27d.wav");}
		else if((x>200)&&(x<300)&&(y>0)&&(y<200))
		{system("aplay ./wav/piano/29e.wav");}
		else if((x>300)&&(x<400)&&(y>0)&&(y<200))
		{system("aplay ./wav/piano/30f.wav");}
		else if((x>400)&&(x<500)&&(y>0)&&(y<200))
		{system("aplay ./wav/piano/32g.wav");}
		else if((x>500)&&(x<600)&&(y>0)&&(y<200))
		{system("aplay ./wav/piano/34a.wav");}
		else if((x>600)&&(x<700)&&(y>0)&&(y<200))
		{system("aplay ./wav/piano/36b.wav");}
		else if((x>700)&&(x<800)&&(y>0)&&(y<200))
		{system("aplay ./wav/piano/37c.wav");}
		else if((x>800)&&(x<900)&&(y>0)&&(y<200))
		{system("aplay ./wav/piano/39d.wav");}
		else if((x>900)&&(x<1000)&&(y>0)&&(y<200))
		{system("aplay ./wav/piano/41e.wav");}		
		else if((x>60)&&(x<126)&&(y>200)&&(y<600))
		{system("aplay ./wav/piano/26_d.wav");}		
		else if((x>180)&&(x<245)&&(y>200)&&(y<600))
		{system("aplay ./wav/piano/28_e.wav");}		
		else if((x>370)&&(x<435)&&(y>200)&&(y<600))
		{system("aplay ./wav/piano/31_g.wav");}		
		else if((x>490)&&(x<545)&&(y>200)&&(y<600))
		{system("aplay ./wav/piano/33_a.wav");}		
		else if((x>600)&&(x<655)&&(y>200)&&(y<600))
		{system("aplay ./wav/piano/35_b.wav");}		
		else if((x>770)&&(x<825)&&(y>200)&&(y<600))
		{system("aplay ./wav/piano/38_d.wav");}		
		else if((x>890)&&(x<950)&&(y>200)&&(y<600))
		{system("aplay ./wav/piano/40_e.wav");}		
	 }
}
void guitar()
{
   lcdtextwrite("1","====GUITAR====   ");
       print_bmp("./bmp/guitar.bmp"); 
       while(1)
   {
		if((x>0)&&(x<1024)&&(y>0)&&(y<100))
		{system("aplay ./wav/guitar/low1.wav");}
		else if((x>0)&&(x<1024)&&(y>100)&&(y<180))
		{system("aplay ./wav/guitar/low2.wav");}
		else if((x>0)&&(x<1024)&&(y>180)&&(y<260))
		{system("aplay ./wav/guitar/low3.wav");}
      	else if((x>0)&&(x<1024)&&(y>260)&&(y<340))
		{system("aplay ./wav/guitar/low4.wav");}	
		else if((x>0)&&(x<1024)&&(y>340)&&(y<420))
		{system("aplay ./wav/guitar/low5.wav");}	
		else if((x>0)&&(x<1024)&&(y>420)&&(y<520))
		{system("aplay ./wav/guitar/lowbass.wav");}	
       }
}
void drum()
{

   lcdtextwrite("1","====DRUM====    ");
   print_bmp("./bmp/drum.bmp");
    while(1)
   {
	   if((x>0)&&(x<250)&&(y>330)&&(y<600))
		{system("aplay ./wav/drum/ride_cymbal.wav");}
		else if((x>250)&&(x<659)&&(y>330)&&(y<600))
		{system("aplay ./wav/drum/tom_tom.wav");}
		else if((x>659)&&(x<1024)&&(y>425)&&(y<600))
		{system("aplay ./wav/drum/crash_cymbal.wav");}
	   else if((x>659)&&(x<1024)&&(y>261)&&(y<425))
		{system("aplay ./wav/drum/hi_hat.wav");}
	    else if((x>659)&&(x<1024)&&(y>0)&&(y<261))
		{system("aplay ./wav/drum/snare.wav");}
	    else if((x>370)&&(x<659)&&(y>0)&&(y<261))
		{system("aplay ./wav/drum/base.wav");}
	       else if((x>0)&&(x<370)&&(y>0)&&(y<261))
		{system("aplay ./wav/drum/floor_tom.wav");}
	}
}
void set()
{
   lcdtextwrite("1","Welcome MINIBand");
       lcdtextwrite("2","select button");
   print_bmp("./bmp/main.bmp");
}
void *buttonTheadFunc()
{
    int returnValue = 0;
    BUTTON_MSG_T msgRx;
   printf("\n<-----------------inter_ButtonThread------------------->\n");
    while(1){    
    returnValue = msgrcv(msgID, &msgRx, sizeof(int), 0, 0);
    printf("\n");
        if(returnValue<0) printf("fail_receive KEY\n");
     switch(msgRx.keyInput)
         {
            case KEY_VOLUMEUP:Beep();
            printf("\nVolume up key):\n");
            //if(ledvalue<=7) { ledOnOff(ledvalue,1); ledvalue++;  }
            break;

            case KEY_HOME:Beep();
            printf("\nHome key):\n");  
            set();          
            break;

            case KEY_BACK:Beep();      
            printf("\nPIANO):\n"); 
            piano();
            break;

            case KEY_SEARCH:Beep();    
            printf("\nGUITAR):\n"); 
            guitar()   ;  
            break;

          
            case KEY_MENU:Beep();      
            printf("\nDRUM):\n");     
            drum();
            break;

            case KEY_VOLUMEDOWN:Beep();  
            printf("\nVolume down key):\n");   
            //if(ledvalue>0) {  ledvalue--;  ledOnOff(ledvalue,0); }
            break;
         }
    }
}
void *AccelThreadFunc()
{ printf("\n<-----------------inter_AccelThread------------------->\n");
   while(1)
   {
      int a;//오른쪽으로 기울이면 +++ 왼쪽은 ---출력
      a=AMG(0);
      usleep(500000);
          if(a<0)
             {
         printf("\n---\n");
         if(ledvalue<=7) { ledOnOff(ledvalue,1); ledvalue++;  }
      }
      else if(a>0)
             {
         printf("\n+++\n");
         if(ledvalue>0) {  ledvalue--;  ledOnOff(ledvalue,0); }
      }
   switch(ledvalue){
case 0:   system("sudo amixer sset 'Speaker' 0%"); printf("volume: 0\n");break;
case 1:   system("sudo amixer sset 'Speaker' 10%"); printf("volume: 10\n");break;
case 2:   system("sudo amixer sset 'Speaker' 20%"); printf("volume: 20\n");break;
case 3:      system("sudo amixer sset 'Speaker' 30%"); printf("volume: 30\n");break;
case 4:      system("sudo amixer sset 'Speaker' 40%"); printf("volume: 40\n");break;
case 5:      system("sudo amixer sset 'Speaker' 50%"); printf("volume: 50\n");break;
case 6:      system("sudo amixer sset 'Speaker' 60%"); printf("volume: 60\n");break;
case 7:      system("sudo amixer sset 'Speaker' 70%"); printf("volume: 70\n");break;
case 8:      system("sudo amixer sset 'Speaker' 80%"); printf("volume: 80\n");break;
         default: break;
      }
   }
   return 0;
}
