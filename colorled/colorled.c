#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <string.h>
#include "colorled.h"

static int fdR,fdG,fdB; //DutyCycle set
static int fdPR,fdPG,fdPB; //Active,Period set
static int fdPIR,fdPIG,fdPIB; //inactive R,G,B
static int fdER,fdEG,fdEB; //enable R,G,B

int Colorledinit(void)
{
  fdPR = open ( COLOR_LED_DEV_R_ PWM_EXPORT, O_WRONLY);
  fdPG = open ( COLOR_LED_DEV_G_ PWM_EXPORT, O_WRONLY);
  fdPB = open ( COLOR_LED_DEV_B_ PWM_EXPORT, O_WRONLY); //pwm active

  write(fdPR, &"0", 1); //pwm active 1
  write(fdPG, &"0", 1); //pwm active 1
  write(fdPB, &"0", 1); //pwm active 1

    close(fdPR);
    close(fdPG);
    close(fdPB);

  fdPR = open ( COLOR_LED_DEV_R_ PWM_PERIOD, O_WRONLY);
  fdPG = open ( COLOR_LED_DEV_G_ PWM_PERIOD, O_WRONLY);
  fdPB = open ( COLOR_LED_DEV_B_ PWM_PERIOD, O_WRONLY); //period initial

    dprintf(fdPR, "%d", 1000); //period 1000
    dprintf(fdPG, "%d", 1000); //period 1000
    dprintf(fdPB, "%d", 1000); //period 1000
    close(fdPR);
    close(fdPG);
    close(fdPB); //period 

  fdER = open ( COLOR_LED_DEV_R_ PWM_ENABLE, O_WRONLY);
  fdEG = open ( COLOR_LED_DEV_G_ PWM_ENABLE, O_WRONLY);
  fdEB = open ( COLOR_LED_DEV_B_ PWM_ENABLE, O_WRONLY); 
    if(fdER<0)
    {
    perror("Color R Enable open error/\n");
    return 1;
    }
    if(fdEG<0)
    {
    perror("Color G Enable open error/\n");
    return 1;
    }
    if(fdEB<0)
    {
    perror("Color B Enable open error/\n");
    return 1;
    }
  write(fdER, &"1", 1); //Red enable 1
  write(fdEG, &"1", 1); //Green enable 1
  write(fdEB, &"1", 1); //Blue enable 1
  
    fdR = open ( COLOR_LED_DEV_R_ PWM_DUTY, O_WRONLY);
  if(fdR<0)
    {
    perror("Color Red open error/\n");
    }
  fdG = open ( COLOR_LED_DEV_G_ PWM_DUTY, O_WRONLY);
  if(fdG<0)
    {
    perror("Color Green open error/\n");
    }
  fdB = open ( COLOR_LED_DEV_B_ PWM_DUTY, O_WRONLY); //duty cycle initial
    if(fdB<0)
    {
    perror("Color Blue open error/\n");
    }
}

void Colorledwrite (int R ,int G, int B)
{

	int duty1,duty2,duty3; 
     duty1 = (1000- (R*10));
     duty2 = (1000- (G*10));
     duty3 = (1000- (B*10));

	   dprintf(fdR, "%d", duty1);
	   dprintf(fdG, "%d", duty2);
	  dprintf(fdB, "%d", duty3);


}

int ColorledExit(void)
{ 
  write(fdER, &"0", 1);
  write(fdEG, &"0", 1);
  write(fdEB, &"0", 1);


    close(fdR);
    close(fdG);
    close(fdB); //duty

  fdPIR = open ( COLOR_LED_DEV_R_ PWM_UNEXPORT, O_WRONLY);    
  fdPIG = open ( COLOR_LED_DEV_G_ PWM_UNEXPORT, O_WRONLY);
  fdPIB = open ( COLOR_LED_DEV_B_ PWM_UNEXPORT, O_WRONLY); //pwm inactive
  write(fdPIR, &"0", 1);
  write(fdPIG, &"0", 1);
  write(fdPIB, &"0", 1);

  close(fdPIR);
  close(fdPIG);
  close(fdPIB);
}





