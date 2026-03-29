/*
 * Author: Martins Oviawe
 * Github: github.com/martins-builds
 * Description: Student record system using structs, 
 * array of structs and pointer to struct, added uppercase function and countLongNames function
*/

#include<stdio.h>
#include<string.h>

typedef struct Student{
    char name[70];
    int age; 
    int grade;
}Student;

void getIn(Student *stud){
    printf("Name: ");
    fgets(stud->name, sizeof(stud->name), stdin);
    stud->name[strlen(stud->name)-1] = '\0';
    printf("Age: ");
    scanf("%d", &stud->age);
    while(getchar() != '\n');
    printf("Grade: ");
    scanf("%d", &stud->grade);
    while(getchar() != '\n');
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
            cName[i] = (cName[i] - 32);
        
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
    Student stud[5];
    char name[70];
    printf("Enter the details of all 5 students\n");

    for (int i = 0; i < 5; i++)
    {
        getIn(&stud[i]);
        printf("\n");
    }
    printf("\nThese are the information of all the students\n");
    for (int i = 0; i < 5; i++)
    {
        print(&stud[i]);
    }
    printf("Enter name to search for student details: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name)-1] = '\0';
    search(stud, 5, name);
    printUpperCase(&stud[0]);
    printf("\nNumber of students with name length greater than 5 are: %d", countLongNames(stud, 5));
    return 0;
}