#include <stdio.h>
#include <stdlib.h>

struct intQueueElement
{
    int element;
    struct intQueueElement *ptrNextElement; // Pointer to the next element in the queue, enqueued later
};

struct intQueue
{
    struct intQueueElement *end;   // Pointer to last element enqueued
    struct intQueueElement *start; // Pointer to first element in queue
};

/// @brief Check if the Queue is empty
/// @return 1 if empty, 0 if not
int intQueue_isQueueEmpty(struct intQueue *queue)
{
    return (queue->start == NULL);
}

/// @brief Add an element to the queue
/// @param element Element to add
void intQueue_enQueue(struct intQueue *queue, int element)
{
    struct intQueueElement *newElement = (struct intQueueElement *)malloc(sizeof(struct intQueueElement));
    newElement->element = element;
    newElement->ptrNextElement = NULL;
    if (intQueue_isQueueEmpty(queue))
    {
        queue->start = newElement;
        queue->end = newElement;
    }
    else
    {
        queue->end->ptrNextElement = newElement;
    }
    queue->end = newElement;
}

/// @brief Remove the first element from the queue
/// @return The removed element
int intQueue_deQueue(struct intQueue *queue)
{
    if (intQueue_isQueueEmpty(queue))
    {
        return NULL;
    }
    if (queue->start->ptrNextElement == NULL)
    {
        int lastValue = queue->start->element;
        free(queue->start);
        queue->start = NULL;
        return lastValue;
    }
    int startValue = queue->start->element;
    struct intQueueElement *newStart = queue->start->ptrNextElement;
    free(queue->start);
    queue->start = newStart;
    return startValue;
}

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