#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
	#include <stdio.h>
	#include <unistd.h>

	int main(int argc, char ** argv)
	   {
		int check,n;
                char buf[512];
		check = open(argv[1],O_RDONLY);
                if(check != -1)
                  {
                     n=read(check,buf,100);
                     buf[n]=0;
		     printf("%s",buf);
                     n=read(check,buf,100);
                     buf[n]=0;
		     printf("%s",buf);
                     printf("n=%d",n);
                  }
                else
                  {
                    printf("couldn't open the file \n");
		  }
	      return 0;
           }
