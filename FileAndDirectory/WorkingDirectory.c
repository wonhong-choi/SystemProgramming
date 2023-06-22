#include <unistd.h>
#include <stdio.h>

int main(){
    char * cwd;
    char wd[BUFSIZ];

    cwd=getcwd(NULL, BUFSIZ);
    printf("Current Working Directory : %s\n", cwd);

    if(chdir("SystemProgramming")==-1){
        printf("Failed chdir\n");
    }
    cwd=getcwd(wd, BUFSIZ);
    printf("Current Working Directory1 : %s\n", cwd);
    printf("Current Working Directory2 : %s\n", wd);

    return 0;
}