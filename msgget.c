 #include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/msg.h>
 #include<stdio.h>
int main()
  {
     int id;
     id=msgget(5100,IPC_CREAT);
     printf("id of PO 5000 is %d\n",id);
  }
