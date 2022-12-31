#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int fd,n;
    off_t start, cur;
    char buf[256]={0};

    // echo "Linux System Programming" > linux.txt
    fd=open("linux.txt", O_RDONLY);
    if(fd==-1){
        perror("Open linux.txt");
        exit(1);
    }

    start = lseek(fd, 0, SEEK_CUR);
    n=read(fd, buf, 255);
    buf[n-1]='\0';

    printf("%s\n", buf);

    printf("Offset start=%d, Read Str=%s, n=%d\n", (int)start, buf, n);
    cur=lseek(fd, 0 ,SEEK_CUR);
    printf("Offset cur = %d\n", (int)cur);

    start=lseek(fd, 6, SEEK_SET);
    n=read(fd, buf, 255);
    buf[n-1]='\0';
    printf("Offset start=%d, Read Str=%s\n", (int)start, buf);

    close(fd);
    return 0;
}