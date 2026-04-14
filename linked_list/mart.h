/*Author -> Oviawe Martins (martins-builds)*/
#ifndef MART_H
#define MART_H

typedef struct Student{
    char name[70];
    int age; 
    int grade;
    struct Student *link; 
}Student;

Student *addStudent(Student *head);

void print(Student *head);

void printAll(Student *head);

void search(Student *head, int size, char *name);

Student *delByName(Student *head, char *name);

void freeAll(Student *head);

Student *putAtEnd(Student *head, Student *newNode);

int menu(Student **head, int *size);

#endif