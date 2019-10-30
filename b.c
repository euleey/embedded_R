#include <stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
int fd;
int*i=(int*)malloc(sizeof(int));

off_t newpos;
char buffer[5];

fd=open("ex03-04.c",O_RDWR);
newpos=lseek(fd,(off_t)0,SEEK_SET);
read(fd,buffer,5);


printf




close(fd)
