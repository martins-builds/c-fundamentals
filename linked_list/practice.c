#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}Node;

Node *putAtEnd(Node *head, int data){
    Node *ptr = (Node *)malloc(sizeof(Node)), *ptr2 = head;
    ptr->data = data;
    ptr->link = NULL;
    if (head->link == NULL)
    {
        head->link = ptr;
        return head;
    }
    
    while (ptr2->link != NULL)
        ptr2 = ptr2->link;
    ptr2->link = ptr;

    return head;
}

Node *putAtStart(Node *head, int data){
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->link = head;
    return ptr;
}

Node *delByVal(Node *head, int val){
    Node *ptr = head;
    Node *ptr2 = head;
    if (head->data == val)
    {
        ptr = head->link;
        free(head);
        return ptr;
    }
    
    while (ptr != NULL)
    {
        if (ptr->data == val)
        {
            ptr2->link = ptr->link;
            free(ptr);
            ptr = ptr2->link;
        }
        else{
            ptr2 = ptr;
            ptr = ptr->link;
        }
        
    }
    return head;
}

void traAndPrin(Node *head){
    Node *ptr = head;
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

void freeAll(Node *head){
    Node *ptr;
    while (head != NULL)
    {
        ptr = head->link;
        free(head);
        head = ptr;
    }
}

int main(){
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 30;
    head->link = NULL;
    head = putAtEnd(head, 20);
    head = putAtEnd(head, 30);
    head = putAtEnd(head, 40);
    traAndPrin(head);
    printf("\n");
    head = putAtStart(head, 40);
    head = putAtStart(head, 30);
    head = putAtStart(head, 20);
    traAndPrin(head);
    printf("\n");
    head = delByVal(head, 40);
    traAndPrin(head);
    printf("\n");
    freeAll(head);
    return 0;
}