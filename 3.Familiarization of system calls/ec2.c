#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[]) {
    printf("We are in ec2.c\n");
    printf("PID of ec2.c is %d\n",getpid());
    return 0;
}
