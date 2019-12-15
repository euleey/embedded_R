#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <linux/input.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/kd.h> //touchscreen
#include <sys/ioctl.h> //touchscreen


static pthread_t aplayTh_id[17];

static void* aplayThFunc1();
static void* aplayThFunc2();
static void* aplayThFunc3();
static void* aplayThFunc4();
static void* aplayThFunc5();
static void* aplayThFunc6();
static void* aplayThFunc7();
static void* aplayThFunc8();
static void* aplayThFunc9();
static void* aplayThFunc10();
static void* aplayThFunc11();
static void* aplayThFunc12();
static void* aplayThFunc13();
static void* aplayThFunc14();
static void* aplayThFunc15();
static void* aplayThFunc16();
static void* aplayThFunc17();


void aplay(int num)
{
  switch (num){
    case 1 :  {pthread_create(&aplayTh_id[0], NULL, &aplayThFunc1, NULL);
               pthread_detach(aplayTh_id[0]);}
    case 2 :  {pthread_create(&aplayTh_id[1], NULL, &aplayThFunc2, NULL);
               pthread_detach(aplayTh_id[1]);}        
    case 3 :  {pthread_create(&aplayTh_id[2], NULL, &aplayThFunc3, NULL);
               pthread_detach(aplayTh_id[2]);}
    case 4 :  {pthread_create(&aplayTh_id[3], NULL, &aplayThFunc4, NULL);
               pthread_detach(aplayTh_id[3]);}
    case 5 :  {pthread_create(&aplayTh_id[4], NULL, &aplayThFunc5, NULL);
               pthread_detach(aplayTh_id[4]);}
    case 6 :  {pthread_create(&aplayTh_id[5], NULL, &aplayThFunc6, NULL);
               pthread_detach(aplayTh_id[5]);}
    case 7 :  {pthread_create(&aplayTh_id[6], NULL, &aplayThFunc7, NULL);
               pthread_detach(aplayTh_id[6]);}
    case 8 :  {pthread_create(&aplayTh_id[7], NULL, &aplayThFunc8, NULL);
               pthread_detach(aplayTh_id[7]);}
    case 9 :  {pthread_create(&aplayTh_id[8], NULL, &aplayThFunc9, NULL);
               pthread_detach(aplayTh_id[8]);}
    case 10 : {pthread_create(&aplayTh_id[9], NULL, &aplayThFunc10, NULL);
               pthread_detach(aplayTh_id[9]);}
    case 11 :  {pthread_create(&aplayTh_id[10], NULL, &aplayThFunc11, NULL);
               pthread_detach(aplayTh_id[10]);}
    case 12 :  {pthread_create(&aplayTh_id[11], NULL, &aplayThFunc12, NULL);
               pthread_detach(aplayTh_id[11]);}
    case 13 :  {pthread_create(&aplayTh_id[12], NULL, &aplayThFunc13, NULL);
               pthread_detach(aplayTh_id[12]);}
    case 14 :  {pthread_create(&aplayTh_id[13], NULL, &aplayThFunc14, NULL);
               pthread_detach(aplayTh_id[13]);}
    case 15 :  {pthread_create(&aplayTh_id[14], NULL, &aplayThFunc15, NULL);
               pthread_detach(aplayTh_id[14]);}
    case 16 :  {pthread_create(&aplayTh_id[15], NULL, &aplayThFunc16, NULL);
               pthread_detach(aplayTh_id[15]);}
    case 17 :  {pthread_create(&aplayTh_id[16], NULL, &aplayThFunc17, NULL);
               pthread_detach(aplayTh_id[16]);}

}
}

static void* aplayThFunc1()
{
   system("aplay ./wav/piano/25c.wav");
   printf("play piano1");

}

static void* aplayThFunc2()
{
   system("aplay ./wav/piano/27d.wav");
   printf("play piano2");

}

static void* aplayThFunc3()
{
   system("aplay ./wav/piano/29e.wav");
   printf("play piano3");
usleep(10);
}

static void* aplayThFunc4()
{
   system("aplay ./wav/piano/30f.wav");
   printf("play piano4");

}

static void* aplayThFunc5()
{
   system("aplay ./wav/piano/32g.wav");
   printf("play piano5");

}

static void* aplayThFunc6()
{
   system("aplay ./wav/piano/34a.wav");
   printf("play piano6");
}

static void* aplayThFunc7()
{
   system("aplay ./wav/piano/36b.wav");
   printf("play piano7");

}

static void* aplayThFunc8()
{
   system("aplay ./wav/piano/37c.wav");
   printf("play piano8");

}

static void* aplayThFunc9()
{
   system("aplay ./wav/piano/39d.wav");
   printf("play piano9");

}

static void* aplayThFunc10()
{
   system("aplay ./wav/piano/41e.wav");
   printf("play piano10");
usleep(10);
}

static void* aplayThFunc11()
{
   system("aplay ./wav/piano/26_d.wav");
   printf("play piano11");

}

static void* aplayThFunc12()
{
   system("aplay ./wav/piano/28_e.wav");
   printf("play piano12");

}

static void* aplayThFunc13()
{
   system("aplay ./wav/piano/31_g.wav");
   printf("play piano13");

}

static void* aplayThFunc14()
{
   system("aplay ./wav/piano/33_a.wav");
   printf("play piano14");

}

static void* aplayThFunc15()
{
   system("aplay ./wav/piano/35_b.wav");
   printf("play piano15");

}

static void* aplayThFunc16()
{
   system("aplay ./wav/piano/38_d.wav");
   printf("play piano16");

}

static void* aplayThFunc17()
{
   system("aplay ./wav/piano/40_e.wav");
   printf("play piano17");

}
