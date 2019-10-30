#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>



int main()
{
int fd;
off_t newpos;
char buffer[1024];


fd=open("input.txt",O_RDWR);

newpos =lseek(fd,4,SEEK_SET);
read(fd,buffer,1024);
printf("%c\n,",buffer[0]);

newpos =lseek(fd,9,SEEK_SET);
read(fd,buffer,1024);
printf("%c\n,",buffer[0]);
close(fd);   


fd=open("input.txt",O_RDWR);
newpos=lseek(fd,-5,SEEK_END);
read(fd,buffer,1024);
printf("%c\n,",buffer[0]);

newpos=lseek(fd,-10,SEEK_END);
read(fd,buffer,1024);
printf("%c\n,",buffer[0]);

close(fd);   


return 0;
}
