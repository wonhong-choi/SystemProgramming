#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    struct stat buf;

    stat("linux.txt", &buf);

    printf("nlink of linux.txt : %d\n", (int)buf.st_nlink);

    printf("hard link!\n");
    link("linux.txt", "linx.ln");
    stat("linux.txt", &buf);
    printf("nlink of linux.txt : %d\n", (int)buf.st_nlink);

    symlink("linux.txt","softlinux.ln");
    stat("linux.txt", &buf);
    printf("nlink of linux.txt : %d\n", (int)buf.st_nlink);
    if(stat("softlinux.ln", &buf)==-1){
        perror("stat : softlinux.ln");
        exit(1);
    }
    printf("nlink of softlinux.ln : %d\n", (int)buf.st_nlink);

    return 0;
}