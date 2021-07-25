#include<unistd.h>
#include<stdio.h>
int main() {
int ret;
ret=unlink("99");
printf("ret = %d",ret);

return 0;
}
