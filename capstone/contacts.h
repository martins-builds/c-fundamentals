/*Author -> Oviawe Martins (martins-bbuilds)*/
#ifndef CONTACTS_H
#define CONTACTS_H
    typedef struct contact
    {
        char name[50];
        char email[250];
        long int number;
        struct contact *link;
    }contact;

    contact *putAtEnd(contact *head, contact *new);

    contact *addContact(contact *head);

    void print(contact *head);

    void search(contact *head);

    void printAll(contact *head);

    contact *delByNAme(contact *head);

    void freeAll(contact *head);

    int menu(contact **head, int *size);
    
#endif