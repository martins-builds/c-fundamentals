/*Author -> Oviawe Martins (martins-bbuilds)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact
{
    char name[50];
    char email[250];
    long int number;
    struct contact *link;
}contact;

contact *putAtEnd(contact *head, contact *new){
    contact *ptr = head, *ptr2 = new;
    if (head == NULL)
    {
        head = new;
        head->link = NULL;
        return head;
    }
    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = ptr2;

    return head;
}

contact *addContact(contact *head){
    contact *new = (contact *)malloc(sizeof(contact));
    if (new == NULL)
    {
        printf("ERROR...\n");
        return head;
    }
    
    printf("Enter name: ");
    fgets(new->name, 50, stdin);
    new->name[strlen(new->name)-1] = '\0';
    printf("Enter email: ");
    fgets(new->email, 250, stdin);
    new->email[strlen(new->email)-1] = '\0';
    printf("Enter number: ");
    scanf("%ld", &new->number);
    while(getchar() != '\n');

    new->link = NULL;
    head = putAtEnd(head, new);
    return head;
}

void print(contact *head){
    printf("Contact name is %s, email is %s and phone number is %ld\n", head->name, head->email, head->number);
}

void search(contact *head){
    int found = 0;
    char name[50];
    printf("Enter name to search: ");
    fgets(name, 50, stdin);
    name[strlen(name)-1] = '\0';
    while (head != NULL)
    {
        if(strcmp(head->name, name) == 0){
            found++;
            print(head);
        }
        head = head->link;
    }
    if(found == 0)
        printf("Student Not Found...\n");
}

void printAll(contact *head){
    while (head != NULL)
    {
        print(head);
        head = head->link;
    }
}

contact *delByNAme(contact *head){
    contact *new = head, *new2 = head;
    char name[50];
    int del = 0;
    printf("Enter name to delete: ");
    fgets(name, 50, stdin);
    name[strlen(name)-1] = '\0';
    if (strcmp(head->name, name) == 0)
    {
        printf("Deleted....\n");
        del++;
        free(head);
        return new;
    }
    
    while (new != NULL)
    {
        if (strcmp(new->name, name) == 0)
        {
            new2->link = new->link;
            free(new);
            printf("Deleted....\n");
            del++;
            new = new2->link;
        }
        else{
            new2 = new;
            new = new->link;
        }
    }
    if(del == 0)
        printf("Name found in contact...\n");

    return head;
}

void freeAll(contact *head){
    contact *new = head;
    while (new != NULL)
    {
        new = new->link;
        free(head);
        head = new;
    }
}

int menu(contact **head, int *size){
    int option;
    FILE *fp;
    printf("PHONEBOOK\n");
    while (1)
    {
        printf("1. ADD NEW CONTACT\n");
        printf("2. SEARCH CONTACT BY NAME\n");
        printf("3. DELETE CONTACT BY NAME\n");
        printf("4. PRINT ALL CONTACTS\n");
        printf("5. EXIT\n");
        scanf("%d", &option);
        while(getchar() != '\n');

        if (option == 1)
        {
            *head = addContact(*head);
            (*size)++;
        }
        else if (option == 2)
        {
            if (head == NULL)
            {
                printf("No contacts saved....\n");
            }
            else
                search(*head);
        }
        else if (option == 3)
        {
            if (head == NULL)
            {
                printf("No contacts saved....\n");
            }
            else{
                *head = delByNAme(*head);
                (*size)--;
            }
        }
        else if (option == 4)
        {
            if (head == NULL)
            {
                printf("No contacts saved....\n");
            }
            else
                printAll(*head);
        }
        else if (option == 5)
        {
            contact *new = *head;
            printf("Exiting...\n");
            fp = fopen("contacts.bin", "wb");
            if (fp == NULL)
            {
                printf("Unable to open file\n");
                return 1;
            }
            
            fwrite(size, sizeof(int), 1, fp);
            for (int i = 0; i < *size; i++)
            {
                fwrite(new, sizeof(contact), 1, fp);
                new = new->link;
            }
            free(new);
            fclose(fp);
            freeAll(*head);
            printf("Exited...\n");
            return 0;
        }
        else
            printf("INVALID INPUT...\n");
    }
}