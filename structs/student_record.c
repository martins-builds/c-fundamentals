/*
 * Author: Martins Oviawe
 * Github: github.com/martins-builds
 * Description: Student record system using structs, 
 * array of structs and pointer to struct
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
    scanf("%s", stud->name);
    printf("Age: ");
    scanf("%d", &stud->age);
    printf("Grade: ");
    scanf("%d", &stud->grade);
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
    scanf("%s", name);
    search(stud, 5, name);
    return 0;
}