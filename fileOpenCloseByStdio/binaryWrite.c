#include <stdio.h>
#include <stdlib.h>

int main(){
    char* filename="binary.bin";

    FILE* fp=fopen(filename, "wb");
    if(fp==NULL){
        perror("file open error\n");
        exit(1);
    }

    int buf[5]={10,20,30,40,50};

    size_t numOfWrittenItems = fwrite(buf, sizeof(int), 5, fp);
    printf("Success to write %d object(s).\n", numOfWrittenItems);
    fclose(fp);

    return 0;
}