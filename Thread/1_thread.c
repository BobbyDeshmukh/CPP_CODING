#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *routine()
{
    printf("Thread is running\n");
    sleep(3);
    printf("Thread is finishing\n");
}

int main()
{
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
    {
        perror("Failed to create thread 1");
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
    {
        perror("Failed to create thread 2");
        return 1;
    }

    if (pthread_join(t1, NULL) != 0)
    {
        perror("Failed to join thread 1");
        return 1;
    }

    if (pthread_join(t2, NULL) != 0)
    {
        perror("Failed to join thread 2");
        return 1;
    }

    return 0;
}