#include<unistd.h>
#include<stdio.h>
int main() {
int ret;
ret=symlink("99","softlink");
printf("ret = %d",ret);

return 0;
}
