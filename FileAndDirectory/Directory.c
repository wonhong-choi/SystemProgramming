#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define PRINT_ERR_MSG(_msg) {perror(_msg); exit(1);}

int main(){
    if(mkdir("System", 0755)==-1){
        PRINT_ERR_MSG("System");
    }
    if(mkdir("Programming", 0755)==-1){
        PRINT_ERR_MSG("Programming");
    }
    if(rename("System","SystemProgramming")==-1){
        PRINT_ERR_MSG("SystemProgramming");
    }
    if(rmdir("Programming")==-1){
        PRINT_ERR_MSG("Programming");
    }
    return 0;
}