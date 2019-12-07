#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <string.h>
#include "colorled.h"

static int fdR,fdG,fdB,fdPA,fdPI,fdPE,fdE;

int Colorledinit(void)
{
  fdPA = open ( COLOR_LED_DEV_R_ PWM_EXPORT, O_WRONLY);
  fdPA = open ( COLOR_LED_DEV_G_ PWM_EXPORT, O_WRONLY);
  fdPA = open ( COLOR_LED_DEV_G_ PWM_EXPORT, O_WRONLY); //pwm active
   
  fdPI = open ( COLOR_LED_DEV_R_ PWM_UNEXPORT, O_WRONLY);    
  fdPI = open ( COLOR_LED_DEV_G_ PWM_UNEXPORT, O_WRONLY);
  fdPI = open ( COLOR_LED_DEV_G_ PWM_UNEXPORT, O_WRONLY); //pwm inactive

  if(fdPA<0)
    {
    perror("pwm active open error/\n");
    return 1;
    }

  fdPE = open ( COLOR_LED_DEV_R_ PWM_PERIOD, O_WRONLY);
  fdPE = open ( COLOR_LED_DEV_G_ PWM_PERIOD, O_WRONLY);
  fdPE = open ( COLOR_LED_DEV_B_ PWM_PERIOD, O_WRONLY); //period initial

  if(fdPE<0)
    {
    perror("Period open error/\n");
    return 1;
    }
  fdR = open ( COLOR_LED_DEV_R_ PWM_DUTY, O_WRONLY);
  if(fdR<0)
    {
    perror("Color Red open error/\n");
    return 1;
    }
  fdG = open ( COLOR_LED_DEV_G_ PWM_DUTY, O_WRONLY);
  if(fdG<0)
    {
    perror("Color Green open error/\n");
    return 1;
    }
  fdB = open ( COLOR_LED_DEV_B_ PWM_DUTY, O_WRONLY); //duty cycle initial
    if(fdB<0)
    {
    perror("Color Blue open error/\n");
    return 1;
    }
  fdE = open ( COLOR_LED_DEV_R_ PWM_ENABLE, O_WRONLY);
  fdE = open ( COLOR_LED_DEV_G_ PWM_ENABLE, O_WRONLY);
  fdE = open ( COLOR_LED_DEV_B_ PWM_ENABLE, O_WRONLY); 
    if(fdE<0)
    {
    perror("Color Enable open error/\n");
    return 1;
    }

}

void pwmActive(int active)
{
    if (active) write(fdPA, &"0", 1); //pwm active
    else        write(fdPI, &"0", 1); 
}
void ColorledEnable(int bEnable)
{
	if ( bEnable)	write(fdE, &"1", 1);
	else 			write(fdE, &"0", 1);
}

int Colorledwrite_1(void)
{
    pwmActive(1);
    ColorledEnable(1);
    setPeriod(1000); //period initial
    
    return 1;
}

void Colorledwrite (int pwmindex, int dutyCycle)
{   
    if ((pwmindex < 0) || (pwmindex > 2))
    {
        printf ("Wrong range of pwmindex : %d\r\n",pwmindex);
    }

    switch (pwmindex)
    {
      case 2:
	   dprintf(fdR, "%d", dutyCycle);
      break;
      case 1:
	   dprintf(fdG, "%d", dutyCycle);
      break;
      case 0:
	  dprintf(fdB, "%d", dutyCycle);
      break;
    }
}

void setPeriod (int period)
{
     dprintf(fdPE, "%d", period);
}

int ColorledExit(void)
{
 ColorledEnable(0);
 pwmActive(0);
 close(fdPI);
 close(fdPA);
 close(fdPE);
 close(fdR);
 close(fdG);
 close(fdB);
 close(fdE);
}


/*
int pwmSetPercent(int percent, int ledColor) 
{ if ((percent <0) || (percent > 100))
{ printf ("Wrong percent: %d\r\n",percent);
return 0;
}int duty = (100- percent) * PWM_PERIOD_NS / 100;
//LED Sinking. 
Colorledwrite(duty, ledColor); 
return 0;
}
*/





