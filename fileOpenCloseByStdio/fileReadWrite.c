#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* rfp, *wfp;
    if((rfp=fopen("hello.txt", "r"))==NULL){
        perror("File open error");
        exit(1);
    }

    if((wfp=fopen("hello.out","w"))==NULL){
        perror("File open error");
        exit(1);
    }

    char c;
    while((c=fgetc(rfp))!=EOF){
        fputc(c, wfp);
    }

    fclose(rfp);
    fclose(wfp);

    return 0;
}