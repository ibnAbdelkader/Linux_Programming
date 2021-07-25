#include<unistd.h>
#include<stdio.h>
int main() {
  char buf[10];
  write(1,"Helloooo there",15);
  read(0,buf,5);
  printf("buf=%s",buf);
return 0;
}
