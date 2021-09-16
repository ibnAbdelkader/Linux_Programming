#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <stdio.h>

int main( int argc, char **argv, char **envp ) {
// atoi  convert string to integer
 int semkey, nsems, semid;

 semkey = atoi( argv[1] );
 nsems  = atoi( argv[2] );

 semid=semget( semkey, nsems, 0666|IPC_CREAT);
 printf( "SEMID: %d\n", semid );

}
