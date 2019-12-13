#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
#include <pthread.h>
#include <linux/input.h>
#include <unistd.h> // for open/close
#include <fcntl.h> // for O_RDWR
#include <sys/ioctl.h> // for ioctl
#include "Touch.h"
static int msgID = 0;

int main(int argc, char *argv[])
{
    msgID=TouchLibInit();
    int returnValue = 0;
    TOUCH_MSG_T msgRx;
    struct   msqid_ds msqstat;
  while(1){
    msgctl( msgID, IPC_STAT, &msqstat);
    returnValue = msgrcv(msgID, &msgRx, sizeof(int), 1, IPC_NOWAIT);
    if(msgRx.xy==1)
    printf("\nx :%d \n",msgRx.value);
    else
    printf("\ny :%d \n",msgRx.value);
    printf( "메지시 개수는 %d 입니다.\n", msqstat.msg_qnum);
}
    TouchLibExit();
    return 0;
}
