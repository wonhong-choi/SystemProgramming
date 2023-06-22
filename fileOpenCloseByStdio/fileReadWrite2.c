#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * reader, *writer;

    char buf[BUFSIZ];
    printf("BUFSIZ = %d\n", BUFSIZ);

    if((reader=fopen("hello.txt","r"))==NULL){
        perror("File Open Error");
        exit(1);
    }
    if((writer=fopen("hello.out","a"))==NULL){
        perror("File Open Error");
        exit(1);
    }

    while(fgets(buf, BUFSIZ, reader)!=NULL){
        fputs(buf, writer);
    }

    fclose(reader);
    fclose(writer);

    return 0;
}