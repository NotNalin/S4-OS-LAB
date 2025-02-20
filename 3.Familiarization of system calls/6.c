#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
void main(){
    struct stat buf;
    stat("./5.c",&buf);
    printf("Size of file is %ld\n",buf.st_size);
    printf("Type of file is %d\n",buf.st_mode);
}

