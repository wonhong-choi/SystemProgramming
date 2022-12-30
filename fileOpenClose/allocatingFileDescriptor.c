#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int openHellotxt(){
    int fd= open("hello.txt", O_RDWR);
    if(fd==-1){
        perror("File Open");
        exit(1);
    }
}

int main(){
    int fd;

    fd=openHellotxt();
    printf("fd : %d\n", fd);
    close(fd);

    close(1);   // close stdout

    fd=openHellotxt();
    printf("fd : %d\n", fd);
    close(fd);

    return 0;
}