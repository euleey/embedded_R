#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <string.h>
#include "colorled.h"

int main (int argc , char **argv)
{
    Colorledinit();
    Colorledwrite_1();
    Colorledwrite(0,200); //Blue
    Colorledwrite(1,200); //Green
    Colorledwrite(2,200); //Red
    ColorledExit();
   /* pwmSetPercent(atoi(argv[1]),0); 
    pwmSetPercent(atoi(argv[2]),1); 
    pwmSetPercent(atoi(argv[3]),2); */

}


