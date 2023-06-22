#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int fileDescriptor;
    mode_t mode;

    mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    fileDescriptor = open("hello.txt", O_CREAT|O_EXCL, mode);
    if(fileDescriptor==-1){
        perror("EXCL");
        exit(1);
    }
    close(fileDescriptor);

    return 0;

}