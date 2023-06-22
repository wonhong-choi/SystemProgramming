#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

#define PRINT_ERR_MSG(_msg) {perror(_msg); exit(1);}

int main(){
    DIR* dp=NULL;
    struct dirent* dentp=NULL;

    if((dp=opendir("."))==NULL){
        PRINT_ERR_MSG("opendir");
    }

    printf("Start Offset : %ld\n", telldir(dp));
    while(dentp=readdir(dp)){
        printf("Read : %s\n", dentp->d_name);
        printf("Cur Offset : %ld\n", telldir(dp));
    }

    printf("Rewind\n");
    rewinddir(dp);
    printf("Cur Offset : %ld\n", telldir(dp));
    
    printf("Move 2 Forward\n");
    seekdir(dp, 2);
    printf("Read : %s\n", readdir(dp)->d_name);
    printf("Cur Offset : %ld\n", telldir(dp));

    closedir(dp);
    return 0;
}