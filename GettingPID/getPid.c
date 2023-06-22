#include <sys/types.h>
#include <stdio.h>

int main(){
    printf("%d\n", (int)getpid());
    printf("%d\n", (int)getppid());

    return 0;
}