#ifndef _TOUCH_H_
#define _TOUCH_H_

int TouchLibInit(void);
int TouchLibExit(void);
#define MESSAGE_ID 1100

typedef struct
{
   long int messageNum;
   int Xvalue;
   int Yvalue;
}TOUCH_MSG_T;
#endif
