#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int cnt;

    cnt = unlink("linux.txt");
    if(cnt ==-1){
        perror("unlink error\n");
        exit(1);
    }

    printf("Unlink Success!\n");
    return 0;
    
}