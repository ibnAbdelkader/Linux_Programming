 #include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/msg.h>
 #include<stdio.h>
 #include<string.h>
  struct msgbuf1 {
          long mtype ;
	  char mtext[24] ;
       }msg ;
int main()
  {
     int id,ret;
     id=msgget(5100,IPC_CREAT|0666);
     printf("id of PO 5000 is %d\n",id);
     msg.mtype=200;
     strcpy(msg.mtext,"hello");
     ret=msgsnd(id,&msg,24,0);
     printf("the return of msgsnd is :%d\n",ret);
     return 0;
  }
