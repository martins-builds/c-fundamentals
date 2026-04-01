/*
 * Author: Martins Oviawe
 * Github: github.com/martins-builds
 * Description: Student record system using structs, 
 * array of structs and pointer to struct, added uppercase function and countLongNames function
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Student{
    char name[70];
    int age; 
    int grade;
}Student;

void getIn(Student *stud){
    printf("Name: ");
    fgets(stud->name, sizeof(stud->name), stdin);
    stud->name[strlen(stud->name)-1] = '\0'; //make the last element a null terminator
    printf("Age: ");
    scanf("%d", &stud->age);
    while(getchar() != '\n');
    printf("Grade: ");
    scanf("%d", &stud->grade);
    while(getchar() != '\n'); //to clear buffer
}

void print(Student *stud){
    printf("%s is %d years old and in grade %d\n", stud->name, stud->age, stud->grade);
}

void search(Student *stud, int size, char *name){
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if(strcmp(stud[i].name, name) == 0){
            found++;
            print(&stud[i]);
        }
    }
    if (found == 0){
        printf("Student not found");
    }
}

void printUpperCase(Student *stud){
    char cName[70];
    strcpy(cName, stud->name);
    for (int i = 0; i < strlen(cName); i++)
    {
        if (cName[i] > 96)
            cName[i] = (cName[i] - 32); //characters are just integers in ASCII
        
    }
    printf("\nThe name in caps is: %s", cName);
}

int countLongNames(Student *stud, int size){
    int num = 0;
    for (int i = 0; i < size; i++)
    {
        if (strlen(stud[i].name) > 5)
            num++;
    }
    return num;
}

int main(){
    int size = 0;
    char name[70];
    FILE *fp;

    fp = fopen("student.bin","rb");
    if (fp == NULL){//if file doesnt exist, run the program and all functions

        printf("Program running for first time\n");
        printf("How many students do you want to input: ");
        scanf("%d", &size);
        while(getchar() != '\n');

        Student *stud = malloc(sizeof(Student) * size);
        if (stud == NULL)
        {
            printf("Couldn\'t allocate memory to array");
            return 0;
        }
        printf("Enter the details of %d student(s)\n", size);

        for (int i = 0; i < size; i++)
        {
            getIn(&stud[i]);
            printf("\n");
        }
        printf("\nThese are the information of all the students\n");
        for (int i = 0; i < size; i++)
        {
            print(&stud[i]);
        }
        printf("Enter name to search for student details: ");
        fgets(name, sizeof(name), stdin);
        name[strlen(name)-1] = '\0';
        search(stud, size, name);
        printUpperCase(&stud[0]);
        printf("\nNumber of students with name length greater than 5 are: %d", countLongNames(stud, 5));

        fp = fopen("student.bin","wb"); //save the info into the file
        if (fp == NULL)
        {
            printf("File unable to opened\n");
            return 1;
        }
        fwrite(&size, sizeof(int), 1, fp);
        fwrite(stud, sizeof(Student), size, fp);
        fclose(fp);
        free(stud);
    }
    else{ //if file already exists, just save the info into struct and print it
        fread(&size, sizeof(int), 1, fp);
        Student *stud = malloc(sizeof(Student) * size);
        if (stud == NULL)
        {
            printf("Couldn\'t allocate memory to array");
            return 0;
        }
        fread(stud, sizeof(Student), size, fp);
        fclose(fp);

        for (int i = 0; i < size; i++)
            print(&stud[i]);

        free(stud);
        return 0;
    }
    return 0;
}