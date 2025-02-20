#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
void main(){
    int shmid = shmget(65,1024,0666|IPC_CREAT);
    char *str = (char *)shmat(shmid,NULL,0);
    printf("data read from memory : %s\n",str);
    shmdt(str);
    shmctl(shmid,IPC_RMID,NULL);
}
