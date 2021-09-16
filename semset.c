#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv, char **envp ) {

 int semkey, semnum, semval, semid;

 semkey=atoi( argv[1] );
 semnum=atoi( argv[2] );
 semval=atoi( argv[3] );

 semid = semget( semkey,0 , 0 );


 semctl( semid, semnum, SETVAL, semval );

}
