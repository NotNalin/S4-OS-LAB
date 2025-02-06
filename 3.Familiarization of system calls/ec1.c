#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[]) {
	printf("PID of ec1.c is %d\n",getpid());
	char *args[]={"Hello","Need",NULL};
	execv("./f",args);
	return 0;
}
