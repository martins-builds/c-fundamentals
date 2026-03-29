#include <stdio.h>
#include <string.h>

void reverseString(char *str){
    char *start = str;
    char *end = str + strlen(str)-1;

    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int countVowel(char *str){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            count++;
        
    }
    return count;
}

void toUpperCase(char *str){
    for (int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] > 96){
            str[i] = (str[i] - 32);
        }
    }
    
}

int main(){
    //printf("");
    char s[100];
    char ss[30];
    printf("Enter string: ");
    fgets(s, sizeof(s), stdin);
    s[strlen(s)-1] = '\0';
    printf("\nLength of the string you enetered is: %lu\n", strlen(s));
    strcpy(ss,s);
    printf("\nNew string is %s\n", ss);
    strcat(s,ss);
    printf("\nConcantenated string is %s\n", s);
    printf("\nThe number of vowel is %d\n", countVowel(s));
    toUpperCase(s);
    printf("\nFirst string in Upper case is: %s\n", s);
    reverseString(s);
    printf("\nThe reversed string is %s\n", s);
    return 0;
}