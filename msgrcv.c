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
     printf("id of PO 5100 is %d\n",id);
     ret=msgrcv(id,&msg,24,200,0);
     printf("the return of msgrcv is :%d\n",ret);
     printf("the value of text send is : %s \n",msg.mtext);
     return 0;
  }
