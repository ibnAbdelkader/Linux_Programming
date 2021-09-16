#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include<stdio.h>
#include<string.h>
int main ()
{
   int id;
   char * ptr ;
   id=shmget(4000,1000,IPC_CREAT|0666);
   printf("the id of shm 4000 is %d \n",id);
   ptr=shmat(id,NULL,0);
   strcpy(ptr,"hellooooo there");
   shmdt(ptr);

}

