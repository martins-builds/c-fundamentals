#include<stdio.h>
int main(){
    int a, b, c, d, e, avg;

    printf("ENTER YOUR 5 GRADES: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    avg=(a+b+c+d+e)/5;
    printf("YOUR AVERAGE GRADE IS: %d\n", avg);

    if (avg>=80)
    {
        printf("YOUR GRADE IS A");
    }
    
    else if (avg==79 || avg>=70)
    {
        printf("YOUR GRADE IS B");
    }
    
    else if (avg==69 || avg>=60)
    {
        printf("YOUR GRADE IS C");
    }

    else if (avg==59 || avg>=50)
    {
        printf("YOUR GRADE IS D");
    }
    
    else if (avg==49 || avg>=40)
    {
        printf("YOUR GRADE IS E");
    }
    
    else
        printf("YOUR GRADE IS F");

    return 0;
}