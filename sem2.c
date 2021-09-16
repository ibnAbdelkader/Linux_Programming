#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

int main( int argc, char **argv, char **envp ) {

 int semid, sem0, sem1, sem2, retval;
 ushort_t semval[3];
 union semun {
       int             val;
       struct semid_ds *buf;
       ushort_t        *array;
 } arg ;

 struct sembuf sop;

 semid=semget( 100, 3, 0666|IPC_CREAT);
 printf( "semid: %d\n", semid );

 sop.sem_num=0;
 sop.sem_op=0;
 sop.sem_flg=0;

 retval = semop( semid, &sop, 1 );

 printf( "Finished semop\n");
}
