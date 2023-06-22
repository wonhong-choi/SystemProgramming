#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int fd,fd1;

    fd=open("temp.aaa", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if(fd==-1){
        perror("Open temp.aaa");
        exit(1);
    }

    close(1);   // close stdout

    fd1=dup(fd);

    printf("Duplicated: %d\n", fd1);
    printf("stdout redirection\n");

    close(fd1);

    return 0;
}