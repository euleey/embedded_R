#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <string.h>
#include "colorled.h"

int main (int argc , char **argv)
{
    Colorledinit();

    Colorledwrite(100,0,0); //Red
    sleep(3);
    Colorledwrite(0,100,0); //Green
    sleep(4);
    Colorledwrite(0,0,100); //Blue
    sleep(5);
    ColorledExit();
}


