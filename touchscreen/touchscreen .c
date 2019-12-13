#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#define EVENT_DEVICE "/dev/input/event4"
#define EVENT_TYPE EV_ABS
#define EVENT_CODE_X ABS_X
#define EVENT_CODE_Y ABS_Y

#define HAVE_TO_FIND_1     "N: Name=\"ecube-touchscreen\"\n"
#define HAVE_TO_FIND_2    "H: Handlers=kbd event"
#define      INPUT_DEVICE_LIST    "/dev/input/event"        
#define     PROBE_FILE    "/proc/bus/input/devices"    
int probeTouchscreenPath(char *newPath)
{
    int returnValue = 0;    //button에 해당하는 event#을 찾았나?
    int number = 0;            //찾았다면 여기에 집어넣자
    FILE *fp = fopen(PROBE_FILE,"rt");    //파일을 열고
    
    while(!feof(fp))    //파일 끝까지 읽어들인다.
    {
        char tmpStr[200];  //200자를 읽을 수 있게 버퍼
        fgets(tmpStr,200,fp);    //최대 200자를 읽어봄
        //printf ("%s",tmpStr);
        if (strcmp(tmpStr,HAVE_TO_FIND_1) == 0)
        {
            printf("YES! I found!: %s\r\n", tmpStr);
            returnValue = 1;    //찾음
        }
        if ( (returnValue == 1) &&     //찾은 상태에서
        (strncasecmp(tmpStr, HAVE_TO_FIND_2, strlen(HAVE_TO_FIND_2)) == 0) ) //Event??을 찾았으면
        {    
            printf ("-->%s",tmpStr);            
            printf("\t%c\r\n",tmpStr[strlen(tmpStr)-3]);
            number = tmpStr[strlen(tmpStr)-3] - '0';    //Ascii character '0'-'9' (0x30-0x39) to interger(0)
        break; //while 문 탈출
        }
    }
    //이 상황에서 number에는 event? 중 ? 에 해당하는 숫자가 들어가 있다.
    fclose(fp);    
    if (returnValue == 1)
    sprintf (newPath,"%s%d",INPUT_DEVICE_LIST,number);
    //인자로 들어온 newPath 포인터에 
    //  /dev/input/event? 의 스트링을 채움
    return returnValue;
}
int main(int argc,char *argv[]){
    
    struct input_event ev;
    int fd;
    char name[256]="Unknown";
    
    if((getuid())!=0){
        
        fprintf(stderr,"You are not root!Thiss may not work.../n");
        return EXIT_SUCCESS;
        
    }
    fd=open(EVENT_DEVICE,O_RDONLY);
    if(fd==-1){
        fprintf(stderr,"%s is not a vaild device\n", EVENT_DEVICE);
        return EXIT_FAILURE;
    }
    ioctl(fd,EVIOCGNAME(sizeof(name)),name);
    printf("Reading from:\n");
    printf("device file=%s\n",EVENT_DEVICE);
    printf("device name=%s\n",name);
    
    for(;;){
        
        const size_t ev_size=sizeof(struct input_event);
        ssize_t size;
        size=read(fd,&ev,ev_size);
        if(size<ev_size){
            
            fprintf(stderr,"Error size when reading\n");
            //goto err;
        }
        if((ev.type==EVENT_TYPE)&&(ev.code==EVENT_CODE_X||ev.code==EVENT_CODE_Y)){
            
            printf("%s=%d\n",ev.code==EVENT_CODE_X ? "X" : "Y",ev.value);
        }
        
    }
    return EXIT_SUCCESS;
    //err;
    close(fd);
    return EXIT_FAILURE;
    
}
