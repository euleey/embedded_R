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
#define EVENT_CODE_X    ABS_X
#define EVENT_CODE_Y    ABS_Y
#define  INPUT_DEVICE_LIST   "/dev/input/event"  //실제 디바이스 드라이버 노드파일: 뒤에 숫자가 붙음., ex)/dev/input/event5
#define PROBE_FILE   "/proc/bus/input/devices" //PPT에 제시된 "이 파일을 까보면 event? 의 숫자를 알수 있다"는 바로 그 파일
static void* TouchThFunc();
static pthread_t TouchTh_id;
static int fd = 0;
static void* TouchThFunc();
static int msgID = 0;
char inputDevPath[200]={0,};
/*=====================================================================================================*/
int probetouchPath(char *newPath)
{
   int returnValue = 0;   //button에 해당하는 event#을 찾았나?
   int number = 0;            //찾았다면 여기에 집어넣자
   FILE *fp = fopen(PROBE_FILE,"rt");   //파일을 열고

   #define HAVE_TO_FIND_1    "N: Name=\"WaveShare WaveShare Touchscreen\"\n"
   #define HAVE_TO_FIND_2      "H: Handlers=mouse0 event"
   while(!feof(fp))   //파일 끝까지 읽어들인다.
   {
      char tmpStr[200];   //200자를 읽을 수 있게 버퍼
      fgets(tmpStr,200,fp);   //최대 200자를 읽어봄
      //printf ("%s",tmpStr);
      if (strcmp(tmpStr,HAVE_TO_FIND_1) == 0)
      {
         printf("YES! I found!: %s\r\n", tmpStr);
         returnValue = 1;   //찾음
      }
      if (
            (returnValue == 1) &&    //찾은 상태에서
            (strncasecmp(tmpStr, HAVE_TO_FIND_2, strlen(HAVE_TO_FIND_2)) == 0))
      {
         printf ("-->%s",tmpStr);
         printf("\t%c\r\n",tmpStr[strlen(tmpStr)-3]);
         number = tmpStr[strlen(tmpStr)-3] - '0';   //Ascii character '0'-'9' (0x30-0x39) to interger(0)
         break;
      }
   }
    //이 상황에서 number에는 event? 중 ? 에 해당하는 숫자가 들어가 있다.
   fclose(fp);

   if (returnValue == 1)
      sprintf (newPath,"%s%d",INPUT_DEVICE_LIST,number);
    //인자로 들어온 newPath 포인터에 /dev/input/event? 의 스트링을 채움
   return returnValue;
}

int TouchLibInit(void)
{
     if ( probetouchPath(inputDevPath) == 0)
   {
      printf ("ERROR! File Not Found!\r\n");
      return 0;
   }
     
	fd = open(inputDevPath, O_RDONLY);
    msgID = msgget (MESSAGE_ID, IPC_CREAT|0666);
    pthread_create(&TouchTh_id, NULL, &TouchThFunc, NULL);
        return msgID;
}
int TouchLibExit(void)
{
    pthread_cancel(TouchTh_id);
    close(fd);
}
static void* TouchThFunc()
{
    TOUCH_MSG_T msgTx;
    struct input_event stEvent;
    msgTx.messageNum=1;
    while (1)
    {

        read(fd, &stEvent, sizeof (stEvent));
        if ( ( stEvent.type == EV_ABS))
           {
		if(stEvent.code == EVENT_CODE_X)   	msgTx.xy = 1;
		else if(stEvent.code == EVENT_CODE_X)	msgTx.xy = 2;
           msgTx.value = stEvent.code;
           msgsnd(msgID, &msgTx, sizeof(int), 0);
           msgctl( msgID, IPC_RMID, 0);
	   }
        }
}
