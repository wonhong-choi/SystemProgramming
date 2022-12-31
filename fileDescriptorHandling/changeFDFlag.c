#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int fd, flags;

    fd=open("linux.txt", O_RDWR);
    if(fd==-1){
        perror("Open linux.txt");
        exit(1);
    }

    if((flags=fcntl(fd, F_GETFL)) == -1){
        perror("fcntl");
        exit(1);
    }

    flags|=O_APPEND;
    if(fcntl(fd, F_SETFL, flags)==-1){
        perror("fcntl");
        exit(1);
    }

    if(write(fd, "KOREATECH", 9)!=9){
        perror("Write");
        exit(1);
    }

    close(fd);

    return 0;
}