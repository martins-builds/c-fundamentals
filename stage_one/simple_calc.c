#include<stdio.h>
int main(){
    int a, b, choice;

    printf("CHOOSE AN OPERATION\n");
    printf("1. ADDITION\n");
    printf("2. SUBTRACTION\n");
    printf("3. MULTIPLICATION\n");
    printf("4. DIVISION\n");

    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("ENTER FIRST NUMBER: \n");
        scanf("%d", &a);
        printf("ENTER SECOND NUMBER: \n");
        scanf("%d", &b);
        printf("ANSWER IS: %d", a+b);
    }
    
    else if (choice == 2)
    {
        printf("ENTER FIRST NUMBER: \n");
        scanf("%d", &a);
        printf("ENTER SECOND NUMBER: \n");
        scanf("%d", &b);
        printf("ANSWER IS: %d", a-b);
    }
    
    else if (choice == 3)
    {
        printf("ENTER FIRST NUMBER: \n");
        scanf("%d", &a);
        printf("ENTER SECOND NUMBER: \n");
        scanf("%d", &b);
        printf("ANSWER IS: %d", a*b);
    }
    
    else if (choice == 4)
    {
        printf("ENTER FIRST NUMBER: \n");
        scanf("%d", &a);
        printf("ENTER SECOND NUMBER: \n");
        scanf("%d", &b);
        if (b == 0)
        {
            printf("COMPLEX INFINITY");
        }
        else
         printf("ANSWER IS: %d", a/b);
    }
    
    return 0;
}