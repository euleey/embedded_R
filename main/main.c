#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <linux/input.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/kd.h> //touchscreen
#include <sys/ioctl.h> //touchscreen
#include "Touch.h"
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
static pthread_t state_ID;
static pthread_t test_ID;
static pthread_t playid[4];
static int msgID = 0;
static int msgIDTouch = 0;
int Messageclean=0;
static int ledvalue;
void *buttonTheadFunc();
void *playthFunc();
void *AccelThreadFunc();
void *testthFunc();
void *statethFunc();
void *set();
void *piano();
void *guitar();
void *drum();
int play;
int x,y;
int state;
int check;


int main(void)
{   
        set();
    /*===========터치스크린 깨짐방지=====================*/
    int conFD = open ("/dev/tty0", O_RDWR);
    ioctl(conFD, KDSETMODE, KD_GRAPHICS);
    close (conFD);
   /*============init=====================*/
   textlcdinit();
   msgID=buttonLibInit();
   buzzerInit();
   ledLibInit();
    msgIDTouch=TouchLibInit();
   
    for(ledvalue=0;ledvalue<=3;ledvalue++)
        ledOnOff(ledvalue,1);//처음 볼륨은 4 초기화
   /*============init=====================*/
    pthread_create(&buttonThread_ID, NULL, &buttonTheadFunc, NULL); //버튼 계속확인
    pthread_create(&AccelThread_ID,NULL,&AccelThreadFunc,NULL);
    pthread_create(&test_ID,NULL,&testthFunc,NULL);
    pthread_create(&state_ID,NULL,&statethFunc,NULL);
    while(1){}
    pthread_join (state_ID, NULL);
    pthread_join (buttonThread_ID, NULL);
    pthread_join (AccelThread_ID, NULL);
    pthread_join (test_ID, NULL);
    TouchLibExit();
    buttonLibExit();
    ledLibExit();
    buzzerExit();
    textlcdexit();
   return 1;
}
void *piano()
{
   lcdtextwrite("1","====PIANO====     ");
   lcdtextwrite("2","====Try Tip!====  ");
   print_bmp("./bmp/piano.bmp");

    while(check==1){
      if((x>0)&&(x<100)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/17e.wav");}
      else if((x>100)&&(x<200)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/15d.wav");}
      else if((x>200)&&(x<300)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/13c.wav");}
      else if((x>300)&&(x<400)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/12b.wav");}
      else if((x>400)&&(x<500)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/10a.wav");}
      else if((x>500)&&(x<600)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/8g.wav");}
      else if((x>600)&&(x<700)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/6f.wav");}
      else if((x>700)&&(x<800)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/5e.wav");}
      else if((x>800)&&(x<900)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/3d.wav");}
      else if((x>900)&&(x<1000)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/1c.wav");}      
      else if((x>60)&&(x<126)&&(y>200)&&(y<600))
      {system("aplay -d 1  ./wav/piano/16_d.wav");}      
      else if((x>180)&&(x<245)&&(y>200)&&(y<600))
      {system("aplay -d 1  ./wav/piano/14_c.wav");}      
      else if((x>370)&&(x<435)&&(y>200)&&(y<600))
      {system("aplay  -d 1 ./wav/piano/11_a.wav");}      
      else if((x>490)&&(x<545)&&(y>200)&&(y<600))
      {system("aplay -d 1  ./wav/piano/9_g.wav");}      
      else if((x>600)&&(x<655)&&(y>200)&&(y<600))
      {system("aplay -d 1  ./wav/piano/7_f.wav");}      
      else if((x>770)&&(x<825)&&(y>200)&&(y<600))
      {system("aplay  -d 1 ./wav/piano/4_d.wav");}      
      else if((x>890)&&(x<950)&&(y>200)&&(y<600))
      {system("aplay -d 1  ./wav/piano/2_c.wav");}      
}
       printf("피아노 종료 성공\n");  pthread_exit(NULL); 

}
void *guitar()
{
    lcdtextwrite("1","====GUITAR====   ");
    lcdtextwrite("2","Check temperature!");
    print_bmp("./bmp/guitar.bmp"); 
    while(check==2){
      if((x>0)&&(x<1024)&&(y>0)&&(y<100))
      {system("aplay  -d 1 ./wav/guitar/g1.wav");}
      else if((x>0)&&(x<1024)&&(y>100)&&(y<180))
      {system("aplay -d 1  ./wav/guitar/g2.wav");}
      else if((x>0)&&(x<1024)&&(y>180)&&(y<260))
      {system("aplay  -d 1 ./wav/guitar/g3.wav");}
    else if((x>0)&&(x<1024)&&(y>260)&&(y<340))
      {system("aplay -d 1  ./wav/guitar/g4.wav");}   
      else if((x>0)&&(x<1024)&&(y>340)&&(y<420))
      {system("aplay -d 1  ./wav/guitar/g5.wav");}   
      else if((x>0)&&(x<1024)&&(y>420)&&(y<520))
      {system("aplay -d 1  ./wav/guitar/g6.wav");}   
        }
    printf("기타 종료 성공\n");  pthread_exit(NULL); 
}
void *drum()
{
    lcdtextwrite("1","====DRUM====    ");
    lcdtextwrite("2","====Hit!====    ");
    print_bmp("./bmp/drum.bmp");
    while(check==3){
     if((x>0)&&(x<250)&&(y>330)&&(y<600))
      {system("aplay -d 1 ./wav/drum/ride_cymbal.wav");}
      else if((x>250)&&(x<659)&&(y>330)&&(y<600))
      {system("aplay -d 1 ./wav/drum/tom_tom.wav");}
      else if((x>659)&&(x<1024)&&(y>425)&&(y<600))
      {system("aplay -d 1  ./wav/drum/crash_cymbal.wav");}
      else if((x>659)&&(x<1024)&&(y>261)&&(y<425))
      {system("aplay -d 1  ./wav/drum/hi_hat.wav");}
     else if((x>659)&&(x<1024)&&(y>0)&&(y<261))
      {system("aplay -d 1  ./wav/drum/snare.wav");}
     else if((x>370)&&(x<659)&&(y>0)&&(y<261))
      {system("aplay -d 1  ./wav/drum/base.wav");}
     else if((x>0)&&(x<371)&&(y>0)&&(y<261))
      {system("aplay -d 1  ./wav/drum/floor_tom.wav");}
        }
    printf("드림 종료 성공\n");  pthread_exit(NULL); 
}
void *set()
{
   lcdtextwrite("1","Welcome MINIBand");
   lcdtextwrite("2","select button");
   print_bmp("./bmp/main.bmp");
}
void *buttonTheadFunc()
{
    int returnValue = 0;
    int temperature;
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
           temperature = temp(); 
            printf("\n온도 : %d\n",temperature);
            fndDisp(temperature,0);
            break;

            case KEY_HOME:Beep();
            printf("\nHome key):\n"); 
                   pthread_create(&playid[0],NULL,&set,NULL);  check=0; play=pthread_detach(playid[0]);    if(play==0) printf("분리완료\n");  
            break;

            case KEY_BACK:Beep();      
            printf("\nPIANO):\n"); 
             pthread_create(&playid[1],NULL,&piano,NULL); check=1;  pthread_detach(playid[1]); if(play==0) printf("분리완료\n");  
            break;

            case KEY_SEARCH:Beep();    
            printf("\nGUITAR):\n");           
             pthread_create(&playid[2],NULL,&guitar,NULL);  check=2;  pthread_detach(playid[2]); if(play==0) printf("분리완료\n");  
            break;

            case KEY_MENU:Beep();      
            printf("\nDRUM):\n");     
            pthread_create(&playid[3],NULL,&drum,NULL); check=3;     pthread_detach(playid[3]); if(play==0) printf("분리완료\n");  
            break;

            case KEY_VOLUMEDOWN:Beep();  
            printf("\nVolume down key):\n");   
            
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
        // printf("\n---\n");
         if(ledvalue<=7) { ledOnOff(ledvalue,1); ledvalue++;  }
      }
      else if(a>0)
             {
         //printf("\n+++\n");
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
      usleep(10000);
   }
   return 0;
}
void *statethFunc()
{
    while(1)//터치가 현재 눌려있는 상태인지 확인하는 코드
        {if(state==0){x=0;y=0;}
              //printf("state : %d, x = %d y = %d\n",state,x,y);
                usleep(10000);
       }
}
void *testthFunc()
{
    int returnValue = 0;
    TOUCH_MSG_T msgRx;
  
   while(Messageclean != 1) //메세지비우기 
     {
    
     returnValue = msgrcv(msgIDTouch, &msgRx, sizeof(msgRx) - sizeof(long int), 0, IPC_NOWAIT); 
     if (returnValue == -1) Messageclean = 1;
      }

   while(1){
                usleep(1000);
        returnValue = msgrcv(msgIDTouch, &msgRx, sizeof(msgRx) - sizeof(long int), 0, 0);
        if(msgRx.messageNum==1)
        { printf("\nx :%d \n",msgRx.Xvalue);
                x=msgRx.Xvalue; state=1;}
        else if(msgRx.messageNum == 2)
        { printf("\ny :%d \n",msgRx.Yvalue);
                 y=msgRx.Yvalue;state=1;}
        else printf("other");
        state=0;   
     }
}
