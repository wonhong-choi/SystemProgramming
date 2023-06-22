#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

int main(){
    DIR* dirp;
    struct dirent* direntp;

    if((dirp=opendir("SystemProgramming"))==NULL){
        perror("opendir : SystemProgramming\n");
        exit(1);
    }

    while(direntp=readdir(dirp)){
        printf("Name : %s\n", direntp->d_name);
        printf("INode : %d\n", direntp->d_ino);
    }
    
    closedir(dirp);
    return 0;
}