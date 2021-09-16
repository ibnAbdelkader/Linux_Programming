#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSQKEY      3480
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

    /* Create a new message queue.  We use IPC_CREAT to create it,
     * and IPC_EXCL to make sure it does not exist already.  If
     * the same key - change MSQKEY to something else. */
    key = MSQKEY;
    msqid = msgget(key, IPC_CREAT | IPC_EXCL | 0666);
/* Receive messages.  Messages of type 1 are to be printed
  * on the stdout; a message of type 2 indicates that we're done. */

 while ((n = msgrcv(msqid, &mb, MSQSIZE, 0, 0)) > 0)
       {
        switch (mb.mtype)
               {
                case 1:
                        write(1, mb.mtext, n);
                        break;
                case 2:
                     /* Remove the message queue from the system. */
                     msgctl(msqid, IPC_RMID, (struct msqid_ds *) 0);
               }
       }
  return 0;
}
