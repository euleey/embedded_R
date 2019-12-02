#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
#include <pthread.h>
#include <linux/input.h>
#include <unistd.h> // for open/close
#include <fcntl.h> // for O_RDWR
#include <sys/ioctl.h> // for ioctl
#include "button.h"
static int msgID = 0;
int main(int argc, char *argv[])
{
    msgID=buttonLibInit();
    int returnValue = 0;
    BUTTON_MSG_T msgRx;
    printf("====================================================\n");
    returnValue = msgrcv(msgID, &msgRx, sizeof(int), 0, 0);
        if(returnValue<0) printf("fail_receive KEY\n");
     switch(msgRx.keyInput)
         {
            case KEY_VOLUMEUP:      printf("Volume up key):");      break;
            case KEY_HOME:            printf("Home key):");            break;
            case KEY_SEARCH:         printf("Search key):");         break;
            case KEY_BACK:            printf("Back key):");            break;
            case KEY_MENU:            printf("Menu key):");            break;
            case KEY_VOLUMEDOWN:   printf("Volume down key):");   break;
         }
 	printf("\n\n"); 
    buttonLibExit();
    return 0;
        

}
