#include <stdlib.h>
#include <stdio.h>
#include "queue.c"

int main()
{
    defineGenericQueue(int);
    struct Queue(int) *intQueue = newQueue(int);
    intQueue->enQueue(intQueue, 16);
    printf("%d\n", intQueue->deQueue(intQueue));
    printf("%d\n", intQueue->isEmpty(intQueue));
}