#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* reader=NULL;
    reader=fopen("binary.bin", "rb");
    if(reader==NULL){
        perror("File Open Error");
        exit(1);
    }

    int buf[5]={0};
    size_t numOfReadItems = fread(buf, sizeof(int), 5, reader);
    printf("Success to read %d object(s).\n", (int)numOfReadItems);
    
    for(int i=0; i<5; ++i){
        printf("%d\n", buf[i]);
    }


    fclose(reader);
    return 0;
}