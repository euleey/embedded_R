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
#include "Touch.h"
static int msgID = 0;
int Messageclean=0;

int main(int argc, char *argv[])
{
    msgID=TouchLibInit();
    int returnValue = 0;
    TOUCH_MSG_T msgRx;
  //  struct   msqid_ds msqstat;   
 //  msgctl( msgID, IPC_STAT, &msqstat);
   while(Messageclean != 1) //메세지비우기 
     {
     returnValue = msgrcv(msgID, &msgRx, sizeof(msgRx) - sizeof(long int), 0, IPC_NOWAIT); 
     if (returnValue == -1) Messageclean = 1;
      }

   while(1){
    returnValue = msgrcv(msgID, &msgRx, sizeof(msgRx) - sizeof(long int), 0, 0);

    if(msgRx.messageNum==1)
    printf("\nx :%d \n",msgRx.Xvalue);

    else if(msgRx.messageNum == 2)
    printf("\ny :%d \n",msgRx.Yvalue);
    
    else
    printf("other %d \n",msgRx.messageNum);
    usleep(10000);
     }
   // printf( "메시지 개수는 %d 입니다.\n", msqstat.msg_qnum);
   
    TouchLibExit();
    return 0;
}
