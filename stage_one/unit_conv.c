#include<stdio.h>
int main(){
    int choice;
    float num, conv;

    printf("CHOOSE A CONVERSION\n");
    printf("1. CELCIUS TO FAHRENHEIT\n");
    printf("2. FAHRENHEIT TO CALCIUS\n");
    printf("3. KILOMETERS TO MILES\n");
    printf("4. MILES TO KILOMETERS\n");

    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("ENTER YOUR VALUE IN CELCIUS: ");
        scanf("%f",&num);
        conv=((num*9)/5)+32;
        printf("YOUR VALUE IN FAHRENHEIT IS: %f", conv);
    }

    else if (choice == 2)
    {
        printf("ENTER YOUR VALUE IN FAHRENHEIT: ");
        scanf("%f",&num);
        conv=((num-32)*5)/9;
        printf("YOUR VALUE IN CELCIUS IS: %f", conv);
    }

    else if (choice == 3)
    {
        printf("ENTER YOUR VALUE IN KILOMETERS: ");
        scanf("%f",&num);
        conv= num*0.621371;
        printf("YOUR VALUE IN MILES IS: %f", conv);
    }

    else if (choice == 4)
    {
        printf("ENTER YOUR VALUE IN MILES: ");
        scanf("%f",&num);
        conv=num*1.60934;
        printf("YOUR VALUE IN KILOMETERS IS: %f", conv);
    }
    
    return 0;
}