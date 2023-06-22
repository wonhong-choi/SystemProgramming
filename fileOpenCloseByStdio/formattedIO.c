#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int ID;
    char name[8];
    float score;
}Student;

int fileOpen(FILE** fp, char* filename, char* mode){
    *fp = fopen(filename, mode);
    if(*fp==NULL){
        perror("FILE open error\n");
        return -1;
    }
    return 0;
}

int main(){
    FILE* rfp, *wfp;

    char* filename="StudentList.txt";
    Student student;

    if(fileOpen(&wfp, filename, "a")<0){
        exit(1);
    }

    while(1){
        printf("Enter ID Name Score (Exit:-1):");
        scanf("%d", &student.ID);
        if(student.ID<0){
            break;
        }
        scanf("%s %f", &student.name, &student.score);
        fprintf(wfp, "%d %s %.1f\n", student.ID, student.name, student.score);
    }

    fclose(wfp);

    if(fileOpen(&rfp, filename, "r")<0){
        exit(1);
    }

    int nStudents=0;
    float scoreSum=0.0f;
    while(!feof(rfp)){
        fscanf(rfp, "%d %s %f\n", &student.ID, &student.name, &student.score);
        scoreSum+=student.score;
        nStudents++;
    }
    fclose(rfp);
    printf("%d students, Average = %.2f\n", nStudents, scoreSum/nStudents);
    return 0;
}