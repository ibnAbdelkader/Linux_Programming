#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <stdio.h>

int main( int argc, char **argv, char **envp ) {

 int semid, semkey, semnum, semval;

 semkey = atoi( argv[1] );
 semnum = atoi( argv[2] );

 semid=semget( semkey, 0, 0 );

 semval = semctl( semid, semnum, GETVAL, NULL ); 
 printf( "%d\n", semval );

}
