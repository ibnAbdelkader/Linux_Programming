 #include <sys/stat.h>
 #include<stdio.h>
int main()
  {
    printf("ret=%d",chmod("123",0666));
    return 0;
  }
