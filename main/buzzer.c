#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_SCALE_STEP		8
#define BUZZER_BASE_SYS_PATH	"/sys/bus/platform/devices/"
#define BUZZER_FILENAME  "peribuzzer"
#define BUZZER_ENABLE_NAME		"enable"
#define BUZZER_FREQUENCY_NAME	"frequency"
char gBuzzerBaseSysDir[128];

const int musicScale[MAX_SCALE_STEP] =
{
	262, // do
	294,
	330,
	349,
	392,
	440,
	494,  // si
	523
};

int findBuzzerSysPath()
{
	DIR * dir_info = opendir(BUZZER_BASE_SYS_PATH);
	int ifFound = 0;
	if (dir_info != NULL)
	{
		while (1)
		{	
			struct dirent  *dir_entry;
			dir_entry = readdir (dir_info);
			if (dir_entry == NULL)	break;
			if (strncasecmp(BUZZER_FILENAME, dir_entry->d_name, strlen(BUZZER_FILENAME)) == 0)
			{
				ifFound = 1;
				sprintf(gBuzzerBaseSysDir,"%s%s/",BUZZER_BASE_SYS_PATH,dir_entry->d_name);
			}
		}
	}
	printf("--->find %s\n",gBuzzerBaseSysDir);

	return ifFound; 
}
static int fdEnable;
static int fdFreq;
int buzzerInit(void)
{
	if ( findBuzzerSysPath()==0 )	return 0;

	char path[200];
	sprintf(path,"%s%s",gBuzzerBaseSysDir,BUZZER_ENABLE_NAME);
	fdEnable=open(path,O_WRONLY);

	sprintf(path,"%s%s",gBuzzerBaseSysDir,BUZZER_FREQUENCY_NAME);
	fdFreq=open(path,O_WRONLY);

	return 1;
}
void buzzerEnable(int bEnable)
{
	if ( bEnable)	write(fdEnable, &"1", 1);
	else 			write(fdEnable, &"0", 1);
}
// 1 ~ 1000  Hz
void setFrequency(int frequency) 
{
	dprintf(fdFreq, "%d", frequency);
}
int buzzerExit(void)
{
	buzzerEnable(0);
	close(fdEnable);
	close(fdFreq);
	return 0;
}
int buzzerPlaySong(int scale)
{
	setFrequency(musicScale[scale]);
	buzzerEnable(1);
	return 0;
}
int buzzerStopSong(void)
{
	buzzerEnable(0);
	return 0;
}
int Beep(void)
{
    setFrequency(500);
  buzzerEnable(1);
    usleep(100000);
	buzzerEnable(0);
	return 0;
}
