#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "Accel.h"
#define ACCELPATH "/sys/class/misc/FreescaleAccelerometer/"
#define MAGNEPATH "/sys/class/misc/FreescaleMagnetometer/"
#define GYROPATH "/sys/class/misc/FreescaleGyroscope/"
int AMG (int a)
{
	int fd = 0;
	FILE *fp = NULL;
if(a==0){
	//Accelerometer
	fd = open (ACCELPATH "enable",O_WRONLY);
	dprintf (fd,"1");
	close(fd);
	
	fp = fopen (ACCELPATH "data", "rt");
	int i, a1=0,a2=0,a3=0;
        int accel_1[1000];
        int accel_2[1000];
        int accel_3[1000];
        for(i=0;i<1000;i++)
        {fscanf(fp,"%d, %d, %d",&accel_1[i],&accel_2[i],&accel_3[i]);
        a1+=accel_1[i];
        a2+=accel_2[i];
        a3+=accel_3[i];
        }
       // printf ("I read Accel %4d, %4d, %4d\r\n\n\n",(a1/1000)%10000,(a2/1000)%10000,(a3/1000)%10000); //왼쪽으로 기울이면 첫번째 값이 양수 오른쪽은 음수
	//위로 기울이면 -1910~-1920  아래로 기울이면 -1890~-1900
	fclose(fp);
	return (a1/1000)%10000;//나중에 쓰기위해서 중간 값을 받음

}
if(a==1){
	//Magnetometer
	fd = open (MAGNEPATH "enable",O_WRONLY);
	dprintf (fd,"1");
	close(fd);
	fp = fopen (MAGNEPATH "data", "rt");
	int magne[3];
	fscanf(fp,"%d, %d, %d",&magne[0],&magne[1],&magne[2]);
	printf ("I read Magneto %d, %d, %d\r\n",magne[0],magne[1],magne[2]);
	fclose(fp);
}
if(a==2){
	//Gyroscope
	fd = open (GYROPATH "enable",O_WRONLY);
	dprintf (fd,"1");
	close(fd);
	fp = fopen (GYROPATH "data", "rt");
	int gyro[3];
	fscanf(fp,"%d, %d, %d",&gyro[0],&gyro[1],&gyro[2]);
	printf ("I read Gyroscope %d, %d, %d\r\n",gyro[0],gyro[1],gyro[2]);
	fclose(fp);
}
	return 0;
}
