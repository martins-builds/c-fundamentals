#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacts.h"

int main(){
    printf("\n");
    contact *head = NULL;
    FILE *fp;
    int size = 0;

    fp = fopen("contacts.bin","rb");
    if (fp == NULL)
    {
        printf("Program Running for first time\n");
    }
    else
    {
        fread(&size, sizeof(int), 1, fp);
        for (int i = 0; i < size; i++)
        {
            contact *new = (contact *)malloc(sizeof(contact));
            fread(new, sizeof(contact), 1, fp);
            new->link = NULL;
            head = putAtEnd(head, new);
            new = NULL;
        }
    }
    fclose(fp);
    menu(&head, &size);
    return 0;
}