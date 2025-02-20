#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
void main(){
    int fd,s,r,f;
    char buff[100]="hello";
    char ans[100];
    f=creat("File1.txt",S_IRWXU);
    fd=open("File1.txt",O_RDWR);
    s=write(fd,buff,strlen(buff));
    lseek(fd,SEEK_SET,0);
    r=read(fd,ans,strlen(buff));
    printf("Contents of the file\n");
    for(int i=0;i<strlen(buff);i++)
        printf("%c",ans[i]);
    printf("\n");
    close(fd);
}

