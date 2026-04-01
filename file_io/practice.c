#include<stdio.h>
#include<string.h>

typedef struct Test
{
    int age;
    float score;
}Test;

int main(){

    FILE *fp;
    FILE *fp2;
    Test test1 = {5, 3.6};
    Test test2;
    char words[50];

    fp = fopen("test.txt","w");
    if (fp == NULL)
    {
        printf("File unable to opened\n");
        return 1;
    }
    fprintf(fp, "testing, testing. Anyone home?");
    fclose(fp);

    fp = fopen("test.txt","r");
    if (fp == NULL)
    {
        printf("File unable to opened\n");
        return 1;
    }
    fscanf(fp, "%49[^\n]\n", words);
    printf("%s\n", words);
    fclose(fp);

    fp2 = fopen("test.bin","wb");
    if (fp == NULL)
    {
        printf("File unable to opened\n");
        return 1;
    }
    fwrite(&test1, sizeof(Test), 1, fp2);
    fclose(fp2);

    fp2 = fopen("test.bin","rb");
    if (fp == NULL)
    {
        printf("File unable to opened\n");
        return 1;
    }
    fread(&test2, sizeof(Test), 1, fp2);
    fclose(fp2);

    printf("age: %d score: %.2f\n", test1.age, test1.score);
    printf("age: %d score: %.2f\n", test2.age, test2.score);

    return 0;
}