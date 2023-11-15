#include <stdio.h>
#include <stdlib.h>

struct intQueueElement
{
    int data;
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
void intQueue_enQueue(struct intQueue *queue, int data)
{
    struct intQueueElement *newElement = (struct intQueueElement *)malloc(sizeof(struct intQueueElement));
    newElement->data = data;
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
        int lastValue = queue->start->data;
        free(queue->start);
        queue->start = NULL;
        return lastValue;
    }
    int startValue = queue->start->data;
    struct intQueueElement *newStart = queue->start->ptrNextElement;
    free(queue->start);
    queue->start = newStart;
    return startValue;
}