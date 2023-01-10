#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

int main(){
    struct stat statBuf;

    stat("QueryingFileInfo.c", &statBuf);

    printf("Inode : %d\n", (int)statBuf.st_ino);
    printf("Mode = %o\n", (unsigned int)statBuf.st_mode);
    printf("nLink = %d\n", (int)statBuf.st_nlink);
    printf("UID = %d\n", (int)statBuf.st_uid);
    printf("GID = %d\n", (int)statBuf.st_gid);
    printf("Size =%d\n", (int)statBuf.st_size);
    printf("Atime = %d\n", statBuf.st_atim);
    printf("Ctime = %d\n", statBuf.st_ctim);
    printf("Mtime = %d\n", statBuf.st_mtim);
    printf("BlkSize = %d\n", (int)statBuf.st_blksize);
    printf("nBlocks = %d\n", (int)statBuf.st_blocks);

    return 0;
}