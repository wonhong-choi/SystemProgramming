#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fileDescriptor2filePointer(){
    FILE* fp;
    int fd;
    char str[BUFSIZ];

    fd=open("hello.txt",O_RDONLY);
    if(fd==-1){
        perror("Open");
        exit(1);
    }

    fp=fdopen(fd, "r");
    fgets(str, BUFSIZ, fp);
    fclose(fp);

}

void filePointer2fileDescriptor(){
    FILE* fp;
    int fd, n;
    char str[BUFSIZ];

    fp=fopen("hello.txt","r");
    if(fp==NULL){
        perror("file open");
        exit(1);
    }

    fd = fileno(fp);
    printf("fd : %d\n", fd);
    n=read(fd, str, BUFSIZ);
    str[n]='\0';

    printf("Read : %s\n", str);

    close(fd);
}

int main(){
    fileDescriptor2filePointer();
    filePointer2fileDescriptor();
}