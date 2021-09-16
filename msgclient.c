                                               /*** msq-clnt.c ***/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>
#include<stdlib.h>

#define MSQKEY      34856
#define MSQSIZE     32

struct mymsgbuf {
    long    mtype;
    char    mtext[MSQSIZE];
};

int main(void)
{
 key_t key;
 int n, msqid;
 struct mymsgbuf mb;

 /* Get a message queue. The server must have created it already */
 key = MSQKEY;
 msqid = msgget(key, 0666);
/*** msq-clnt.c ***/
 /* Read data from stdin and send it in messages of type 1 */
 mb.mtype = 1;
 while ((n = read(0, mb.mtext, MSQSIZE)) > 0)
         msgsnd(msqid, &mb, n, 0);

 /* Send a message of type 2 to indicate we're done. */
 mb.mtype = 2;
 memset(mb.mtext, 0, MSQSIZE);
 msgsnd(msqid, &mb, MSQSIZE, 0);

 exit(0);
}
