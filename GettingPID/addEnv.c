#include <stdlib.h>
#include <stdio.h>

int main(){
    char *val;
    val=getenv("SHELL");
    if(val==NULL){
        printf("SHELL is not defined\n");
    }
    else{
        printf("SHELL = %s\n", val);
    }

    putenv("SHELL=/usr/bin/csh");
    val=getenv("SHELL");
    printf("SHELL = %s\n", val);

    return 0;
}