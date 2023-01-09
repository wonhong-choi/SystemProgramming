#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fp=fopen("./hello.txt", "w");
    if(fp==NULL){
        perror("file open fail");
        exit(1);
    }

    fclose(fp);

    return 0;
}