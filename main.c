#include <stdlib.h>
#include <stdio.h>
#include "queue.c"

int main()
{
    struct intQueue *queueOne = (struct intQueue *)malloc(sizeof(struct intQueue));
    queueOne->start = NULL;
    intQueue_enQueue(queueOne, 5);
    intQueue_enQueue(queueOne, 6);
    intQueue_enQueue(queueOne, 4);

    struct intQueue *queueTwo = (struct intQueue *)malloc(sizeof(struct intQueue));
    queueTwo->start = NULL;
    intQueue_enQueue(queueTwo, 2);
    intQueue_enQueue(queueTwo, 4);
    intQueue_enQueue(queueTwo, 15);

    printf("%d\n", intQueue_deQueue(queueOne));
    printf("%d\n", intQueue_deQueue(queueOne));
    printf("%d\n", intQueue_deQueue(queueOne));

    printf("%d\n", intQueue_deQueue(queueTwo));
    printf("%d\n", intQueue_deQueue(queueTwo));
    printf("%d\n", intQueue_deQueue(queueTwo));

    intQueue_enQueue(queueOne, 10);

    printf("%d\n", intQueue_deQueue(queueOne));
    printf("%d\n", intQueue_deQueue(queueOne));
}