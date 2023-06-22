#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

int main(){
    struct stat statBuf;

    stat("FileTypeChecking.c", &statBuf);

    printf("Mode =%o, (Hexa : %x)\n", (unsigned int)statBuf.st_mode, (unsigned int)statBuf.st_mode);

    int kind=statBuf.st_mode & S_IFMT;
    printf("Kind = %x\n", kind);

    switch (kind)
    {
    case S_IFREG:
        printf("Regular file\n");
        break;
    case S_IFDIR:
        printf("Directory file\n");
        break;
    
    case S_IFIFO:
        printf("FIFO\n");
        break;
    default:
        break;
    }

    if(S_ISFIFO(statBuf.st_mode)){
        printf("FIFO\n");
    }
    else if(S_ISREG(statBuf.st_mode)){
        printf("Regular file\n");
    }
    else if(S_ISDIR(statBuf.st_mode)){
        printf("Directory file\n");
    }
    return 0;
}