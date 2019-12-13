#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <string.h>
#include "colorled.h"

int main (int argc , char **argv)
{
    Colorledinit();

    Colorledwrite(0,10); //Red
    sleep(3);
    Colorledwrite(1,30); //Green
    sleep(4);
    Colorledwrite(2,50); //Blue
    sleep(5);
    ColorledExit();
}


