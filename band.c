void *piano()
{
   lcdtextwrite("1","====PIANO====     ");
   print_bmp("./bmp/piano.bmp");

    while(check==1){
      if((x>0)&&(x<100)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/17e.wav");}
      else if((x>100)&&(x<200)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/15d.wav");}
      else if((x>200)&&(x<300)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/13c.wav");}
      else if((x>300)&&(x<400)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/12b.wav");}
      else if((x>400)&&(x<500)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/10a.wav");}
      else if((x>500)&&(x<600)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/8g.wav");}
      else if((x>600)&&(x<700)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/6f.wav");}
      else if((x>700)&&(x<800)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/5e.wav");}
      else if((x>800)&&(x<900)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/3d.wav");}
      else if((x>900)&&(x<1000)&&(y>0)&&(y<200))
      {system("aplay -d 1  ./wav/piano/1c.wav");}      
      else if((x>60)&&(x<126)&&(y>200)&&(y<600))
      {system("aplay -d 1  ./wav/piano/16_d.wav");}      
      else if((x>180)&&(x<245)&&(y>200)&&(y<600))
      {system("aplay -d 1  ./wav/piano/14_c.wav");}      
      else if((x>370)&&(x<435)&&(y>200)&&(y<600))
      {system("aplay  -d 1 ./wav/piano/11_a.wav");}      
      else if((x>490)&&(x<545)&&(y>200)&&(y<600))
      {system("aplay -d 1  ./wav/piano/9_g.wav");}      
      else if((x>600)&&(x<655)&&(y>200)&&(y<600))
      {system("aplay -d 1  ./wav/piano/7_f.wav");}      
      else if((x>770)&&(x<825)&&(y>200)&&(y<600))
      {system("aplay  -d 1 ./wav/piano/4_d.wav");}      
      else if((x>890)&&(x<950)&&(y>200)&&(y<600))
      {system("aplay -d 1  ./wav/piano/2_c.wav");}      
}
       printf("피아노 종료 성공\n");  pthread_exit(NULL); 

}
void *guitar()
{
    lcdtextwrite("1","====GUITAR====   ");
    print_bmp("./bmp/guitar.bmp"); 
    while(check==2){
      if((x>0)&&(x<1024)&&(y>0)&&(y<100))
      {system("aplay  -d 1 ./wav/guitar/g1.wav");}
      else if((x>0)&&(x<1024)&&(y>100)&&(y<180))
      {system("aplay -d 1  ./wav/guitar/g2.wav");}
      else if((x>0)&&(x<1024)&&(y>180)&&(y<260))
      {system("aplay  -d 1 ./wav/guitar/g3.wav");}
    else if((x>0)&&(x<1024)&&(y>260)&&(y<340))
      {system("aplay -d 1  ./wav/guitar/g4.wav");}   
      else if((x>0)&&(x<1024)&&(y>340)&&(y<420))
      {system("aplay -d 1  ./wav/guitar/g5.wav");}   
      else if((x>0)&&(x<1024)&&(y>420)&&(y<520))
      {system("aplay -d 1  ./wav/guitar/g6.wav");}   
        }
    printf("기타 종료 성공\n");  pthread_exit(NULL); 
}
void *drum()
{
    lcdtextwrite("1","====DRUM====    ");
    print_bmp("./bmp/drum.bmp");
    while(check==3){
     if((x>0)&&(x<250)&&(y>330)&&(y<600))
      {system("aplay -d 1 ./wav/drum/ride_cymbal.wav");}
      else if((x>250)&&(x<659)&&(y>330)&&(y<600))
      {system("aplay -d 1 ./wav/drum/tom_tom.wav");}
      else if((x>659)&&(x<1024)&&(y>425)&&(y<600))
      {system("aplay -d 1  ./wav/drum/crash_cymbal.wav");}
      else if((x>659)&&(x<1024)&&(y>261)&&(y<425))
      {system("aplay -d 1  ./wav/drum/hi_hat.wav");}
     else if((x>659)&&(x<1024)&&(y>0)&&(y<261))
      {system("aplay -d 1  ./wav/drum/snare.wav");}
     else if((x>370)&&(x<659)&&(y>0)&&(y<261))
      {system("aplay -d 1  ./wav/drum/base.wav");}
     else if((x>0)&&(x<371)&&(y>0)&&(y<261))
      {system("aplay -d 1  ./wav/drum/floor_tom.wav");}
        }
    printf("드림 종료 성공\n");  pthread_exit(NULL); 
}
