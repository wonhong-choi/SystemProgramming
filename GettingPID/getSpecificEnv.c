#include <stdlib.h>
#include <stdio.h>

int main(){
    char* val;
    char* envVariable="PATH";

    val=getenv(envVariable);
    if(val==NULL){
        printf("%s not defined\n", envVariable);
    }
    else{
        printf("%s = %s\n", envVariable, val);
    }

    return 0;
}