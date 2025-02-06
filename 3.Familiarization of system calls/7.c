#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
void main(){
	struct dirent *d;
	DIR *ds;
	ds = opendir(".");
	printf("The directory files are \n");
	while(d=readdir(ds))
		printf("%s\n",d->d_name);
}
