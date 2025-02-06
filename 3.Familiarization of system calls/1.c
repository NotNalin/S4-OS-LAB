#include<stdio.h>
#include<unistd.h>
void main() {
	printf("I am A\n");
	printf("My id is %d\n",getpid());
	printf("My parent id is %d\n", getppid());
	int b = fork();
	if(b==0) {
		printf("I am B\n");
		printf("My id is %d\n",getpid());
		printf("My parent id is %d\n", getppid());
		int c = fork();
		if(c==0) {
			printf("I am C\n");
			printf("My id is %d\n",getpid());
			printf("My parent id is %d\n", getppid());
		}
	}
}

