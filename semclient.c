#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main( int argc, char **argv, char **envp ) {

 int i, semid, semkey, semnum, semval, sopval;

 struct sembuf sop;

 semkey = atoi( argv[1] );
 semnum = atoi( argv[2] );
 sopval = atoi( argv[3] );

 semid=semget( semkey, 0, 0 );

 sop.sem_num=semnum;
 sop.sem_op=sopval;
 sop.sem_flg=0;
 
 printf( "I'll check semaphore, wait if not available\n");

 semop( semid, &sop, 1 ); /* 3rd parameter always 1 */

 printf( "Finished waiting\n"); 
 for (i=0; i<10; i++) 
     { printf("working\n"); sleep( 1 ); }

}
