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
    printf("%d", deQueue(int)(intQueue));
}