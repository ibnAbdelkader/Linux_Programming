#include<unistd.h>
#include<stdio.h>
int main() {
int ret;
ret=link("99","testlink");
printf("ret = %d",ret);

return 0;
}
