#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
#include <pthread.h>
#include <linux/input.h>
#include <unistd.h> // for open/close
#include <fcntl.h> // for O_RDWR
#include <sys/ioctl.h> // for ioctl
#include "fnd.h"
#define MODE_STATIC_DIS 0
#define MODE_TIME_DIS 1
#define MODE_COUNT_DIS 2

int main(int argc , char **argv)
{
	  int number;
		number = atoi("171866");//fnd에 넣고싶은 숫자를 써서 출력하면 됨.
    fndDisp(number,0);
}
	
	



