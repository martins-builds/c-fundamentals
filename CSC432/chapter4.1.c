#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void *sayGreeting(){
    for (int i = 0; i < 5; i++)
    {
        printf("\nI am Alive\n");
    }
    sleep(1);
    
    return NULL;
}
int main(){
    pthread_t thread1;
    pthread_create(&thread1, NULL, sayGreeting, NULL);
    pthread_join(thread1, NULL);

return 0; 
}
