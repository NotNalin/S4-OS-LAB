#include<stdio.h>
#include<unistd.h>
void main(){
	int c = fork();
	if (c==0) {
		for(int i=1;i<=10;i++)
			printf("%d ",i);
	} else if (c>0) {
		wait(NULL);
		for(int i=11;i<=20;i++)
			printf("%d ",i);
	}
}

