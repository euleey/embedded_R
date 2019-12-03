#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <dirent.h>
#include "buzzer.h"

#define MAX_SCALE_STEP		8


int main(int argc , char **argv) 
{ 

if (buzzerInit() == 0)
	{
		printf ("Buzzer init Failed!\r\n");
		return 0;
    }

    buzzerPlaySong(0);
    usleep(200000);
    buzzerStopSong();
    usleep(500000);
    buzzerPlaySong(0);
    usleep(200000);
    buzzerStopSong();    
    usleep(333333);
    buzzerPlaySong(0);
    usleep(200000);
    buzzerStopSong();
    usleep(333333);
    buzzerPlaySong(0);
    usleep(200000);
    buzzerStopSong();
    usleep(500000);
    buzzerPlaySong(0);
    usleep(200000);
    buzzerStopSong();
    usleep(700000);

    buzzerPlaySong(2);
    usleep(200000);
    buzzerStopSong();
    usleep(700000);
    buzzerPlaySong(4);
    usleep(200000);
    buzzerStopSong();
    usleep(500000);
    buzzerPlaySong(4);
    usleep(200000);
    buzzerStopSong();
    usleep(500000);
    buzzerPlaySong(2);
    usleep(200000);
    buzzerStopSong();
    usleep(700000);
    buzzerPlaySong(0);
    usleep(200000);
    buzzerStopSong();
    usleep(700000);

    buzzerPlaySong(4);
    usleep(200000);
    buzzerStopSong();
    usleep(500000);
    buzzerPlaySong(4);
    usleep(200000);
    buzzerStopSong();
    usleep(500000);
    buzzerPlaySong(2);
    usleep(200000);
    buzzerStopSong();
    usleep(700000);

    buzzerPlaySong(4);
    usleep(200000);
    buzzerStopSong();
    usleep(500000);
    buzzerPlaySong(4);
    usleep(200000);
    buzzerStopSong();
    usleep(500000);
    buzzerPlaySong(2);
    usleep(200000);
    buzzerStopSong();
    usleep(700000);

    buzzerPlaySong(0);
    usleep(200000);
    buzzerStopSong();
    usleep(700000);
    buzzerPlaySong(0);
    usleep(200000);
    buzzerStopSong();
    usleep(700000);
    buzzerPlaySong(0);
    usleep(200000);
    buzzerStopSong();
    usleep(700000);		

	buzzerExit();

	return 1;


}

