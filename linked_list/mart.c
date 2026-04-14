/*Author -> Oviawe Martins (martins-builds)*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Student{
    char name[70];
    int age; 
    int grade;
    struct Student *link; 
}Student;

Student *addStudent(Student *head){
    Student *newNode = (Student *)malloc(sizeof(Student));;
    if (newNode == NULL)
    {
        printf("Memory error\n");
        return head;
    }
    printf("Enter name: ");
    fgets(newNode->name, sizeof(newNode->name), stdin);
    newNode->name[strlen(newNode->name)-1] = '\0';
    printf("Enter age: ");
    scanf("%d", &newNode->age);
    while(getchar() != '\n');
    printf("Enter grade: ");
    scanf("%d", &newNode->grade);
    while(getchar() != '\n');
    newNode->link = NULL;

    if (head == NULL)
        return newNode;
    
    Student *ptr = head;
    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = newNode;

    return head;
}

void print(Student *head){
    printf("%s is %d years old and in grade %d\n", head->name, head->age, head->grade);
}

void printAll(Student *head){
    while (head != NULL)
    {
        printf("%s is %d years old and in grade %d\n", head->name, head->age, head->grade);
        head = head->link;
    }
    
}

void search(Student *head, int size, char *name){
    int found = 0;
    while (head != NULL)
    {
        if(strcmp(head->name, name) == 0){
            found++;
            print(head);
        }
        head = head->link;
    }
    if (found == 0){
        printf("Student not found...\n");
    }
}

Student *delByName(Student *head, char *name){
    if (head == NULL)
    {
        printf("No Student to delete\n");
        return NULL;
    }
    Student *ptr = head;
    Student *ptr2 = head;
    if(strcmp(head->name, name) == 0)
    {
        ptr = head->link;
        free(head);
        printf("Successfully Deleted...\n");
        return ptr;
    }
    
    while (ptr != NULL)
    {
        if(strcmp(ptr->name, name) == 0)
        {
            ptr2->link = ptr->link;
            free(ptr);
            printf("Successfully Deleted...\n");
            ptr = ptr2->link;
        }
        else{
            ptr2 = ptr;
            ptr = ptr->link;
        }
        
    }
    return head;
}

void freeAll(Student *head){
    Student *ptr;
    while (head != NULL)
    {
        ptr = head->link;
        free(head);
        head = ptr;
    }
}

Student *putAtEnd(Student *head, Student *newNode){
    Student *ptr = newNode, *ptr2 = head;
    if (head == NULL)
    {
        head = newNode;
        head->link = NULL;
        return head;
    }
    
    while (ptr2->link != NULL)
        ptr2 = ptr2->link;
    ptr2->link = ptr;

    return head;
}

int menu(Student **head, int *size){
    int opt;
    char name[50];
    FILE *fp;
    printf("STUDENT RECORD SYSTEM\n");
    while (1)
    {
        printf("1. ADD STUDENT\n");
        printf("2. SEARCH\n");
        printf("3. PRINT ALL\n");
        printf("4. DELETE\n");
        printf("5. EXIT\n");
        scanf("%d", &opt);
        while(getchar() != '\n');

        if (opt == 1)
        {
            *head = addStudent(*head);
            (*size)++;
        }
        else if (opt == 2)
        {
            if (*head == NULL)
            {
                printf("No Student to print\n");
            }
            else{
                printf("Enter name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strlen(name)-1] = '\0';
                search(*head, *size, name);
            }
        }
        else if (opt == 3)
        {
            if (*head == NULL)
            {
                printf("No Student to print\n");
            }
            else
                printAll(*head);
        }
        else if(opt == 4)
        {
            if (*head == NULL)
            {
                printf("No Student to delete\n");
            }
            else{             
                printf("Enter name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strlen(name)-1] = '\0';
                *head = delByName(*head, name);
                (*size)--;
            }
        }
        else if (opt == 5)
        {
            fp = fopen("student.bin", "wb");
            if (fp == NULL)
            {
                printf("File unable to opened\n");
                return 1;
            }
            Student *ptr = *head;
            fwrite(size, sizeof(int), 1, fp);
            while (ptr != NULL)
            {
                fwrite(ptr, sizeof(Student), 1, fp);
                ptr = ptr->link;
            }
            fclose(fp);
            freeAll(*head);
            return 0;
        }
        else
            printf("INVALID INPUT\n");
    }   
}
