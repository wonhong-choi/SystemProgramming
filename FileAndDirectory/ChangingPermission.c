#include <sys/stat.h>
#include <stdio.h>

int main(){
    struct stat buf;

    chmod("linux.txt", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH);
    stat("linux.txt", &buf);
    printf("Permission : %o\n", (unsigned int)buf.st_mode);

    buf.st_mode |=S_IWGRP;
    buf.st_mode &=~(S_IROTH);
    chmod("linux.txt", buf.st_mode);
    stat("linux.txt", &buf);
    printf("Permission : %o\n", (unsigned int)buf.st_mode);

    return 0;
}