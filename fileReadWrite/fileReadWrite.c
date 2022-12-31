#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

    int rfd, wfd, n;
    char buf[10]={0};
    
    rfd=open("hello.txt", O_RDONLY);
    if(rfd==-1){
        perror("Open hello.txt");
        exit(1);
    }

    wfd=open("hello.bak", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if(wfd==-1){
        perror("Open hello.bak");
        exit(1);
    }

    while((n=read(rfd, (void*)buf, 6))>0){
        if(write(wfd, (void*)buf, n)!=n){
            perror("Write");
        }
    }
    if(n==-1){
        perror("Read");
    }
    
    close(rfd);
    close(wfd);

    return 0;
}
