#ifndef _COLORLED_H__
#define _COLORLED_H_

#define COLOR_LED_DEV_R_ "/sys/class/pwm/pwmchip0/" 
#define COLOR_LED_DEV_G_ "/sys/class/pwm/pwmchip1/" 
#define COLOR_LED_DEV_B_ "/sys/class/pwm/pwmchip2/"
#define PWM_EXPORT "export" 
#define PWM_UNEXPORT "unexport" 
#define PWM_DUTY "pwm0/duty_cycle" 
#define PWM_PERIOD "pwm0/period" 
#define PWM_ENABLE "pwm0/enable"
#define PWM_COLOR_R 0 
#define PWM_COLOR_G 1 
#define PWM_COLOR_B 2
#define PWM_PERIOD_NS 1000000 //ns. = 1ms = 1khz 

int Colorledinit(void);
void pwmActive(int active);
void ColorledEnable(int bEnable);
int Colorledwrite_1(void);
void Colorledwrite (int pwmindex, int dutyCycle);
void setPeriod (int period);
int ColorledExit(void);


#endif
