#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct stat buf;

void printNLinks(char * _filename) {
    printf("%s : Link Count = %d\n", _filename, (int)buf.st_nlink);
    printf("%s : INode = %d\n", _filename, (int)buf.st_ino);
}

int main(){
    FILE* fp = fopen("linux.txt", "w");
    if(fp==NULL){
        perror("fopen linux.txt\n");
        exit(1);
    }
    fclose(fp);
    symlink("linux.txt", "linux.sym");


    stat("linux.txt", &buf);
    printNLinks("linux.txt");

    stat("linux.sym", &buf);
    printNLinks("linux.txt");

    lstat("linux.sym", &buf);
    printNLinks("linux.sym");

    return 0;
}