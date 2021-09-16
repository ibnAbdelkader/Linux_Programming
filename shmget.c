#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
int main ()
{
   int id;
   id=shmget(4000,1024,IPC_CREAT|0666);
   printf("the id of shm 4000 is %d \n",id);
}

