#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
	#include <stdio.h>

	int main(int argc, char ** argv)
	   {
		int check;
                 printf(" the value of argv[0]= %s\n", argv[0]);
                 printf(" the value of argv[1]= %s\n", argv[1]);
                 printf(" the value of argc= %d\n", argc);
		check = creat(argv[1],0666);
		printf("the value of check is %d \n",check);

	      return 0;
           }
