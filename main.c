#include <stdlib.h>
#include <stdio.h>
#include "queue.c"

// Generic test

#define defineSizeOf(T)       \
    int sizeOf(T value)       \
    {                         \
        return sizeof(value); \
    }

int main()
{
    defineGenericQueue(int);
    struct Queue(int) *intQueue = (struct Queue(int) *)malloc(sizeof(struct Queue(int)));
    enQueue(int)(intQueue, 10);
    printf("%d\n", deQueue(int)(intQueue));

    defineGenericQueue(char);
    struct Queue(char) *charQueue = (struct Queue(char) *)malloc(sizeof(struct Queue(char)));
    enQueue(char)(charQueue, 'c');
    printf("%c\n", deQueue(char)(charQueue));
}