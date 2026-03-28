/*
 * Author: Martins Oviawe
 * Github: github.com/martins-builds
 * Description: Student record system using structs, 
 * array of structs and pointer to struct
*/

#include<stdio.h>

typedef struct Car
{
    char brand[50];
    int year;
    float price;
}Car;

void getIn(Car *car){
    scanf("%s %d %f", car->brand, &car->year, &car->price);
}

void print(Car *car){
    printf("%s %d %.2f", car->brand, car->year, car->price);
}

int main(){
    Car cars[3];
    
    for (int i = 0; i < 3; i++)
    {
        printf("Enter the brand name, then the year followed by the price of the car ");
        getIn(&cars[i]);
        printf("\n");
    }
    
    for (int i = 0; i < 3; i++)
    {
        print(&cars[i]);
        printf("\n");
    }
    return 0;
}
