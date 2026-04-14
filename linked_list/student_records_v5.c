/*Author -> Oviawe Martins (martins-builds)*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"mart.h"

int main(){
    Student *head = NULL;
    int size = 0;
    FILE *fp;
    printf("\n");
    fp = fopen("student.bin", "rb");
    if (fp == NULL)
    {
        printf("Program Running for first time\n");
    }
    else{
        fread(&size, sizeof(int), 1, fp);
        for (int i = 0; i < size; i++)
        {
            Student *newNode = (Student *)malloc(sizeof(Student));
            fread(newNode, sizeof(Student), 1, fp);
            newNode->link = NULL;
            head = putAtEnd(head, newNode);
            newNode = NULL;
        }
    }
    fclose(fp);
    menu(&head, &size);
    return 0;
}