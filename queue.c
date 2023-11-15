#include <stdio.h>
#include <stdlib.h>

/*
Example usage:

struct Queue *queueOne = (struct Queue *)malloc(sizeof(struct Queue));
queueOne->start = NULL;
intQueue_enQueue(queueOne, 5);
intQueue_enQueue(queueOne, 6);
intQueue_enQueue(queueOne, 4);

printf("%d\n", intQueue_deQueue(queueOne));
printf("%d\n", intQueue_deQueue(queueOne));
printf("%d\n", intQueue_deQueue(queueOne));
*/

#define defineGenericQueue(T)                                                                                  \
    struct QueueElement##T                                                                                     \
    {                                                                                                          \
        T data;                                                                                                \
        struct QueueElement##T *ptrNextElement; /*Pointer to the next element in the queue, enqueued later*/   \
    };                                                                                                         \
                                                                                                               \
    struct Queue##T                                                                                            \
    {                                                                                                          \
        struct QueueElement##T *end;   /* Pointer to last element enqueued*/                                   \
        struct QueueElement##T *start; /* Pointer to first element in queue*/                                  \
    };                                                                                                         \
                                                                                                               \
    int isQueueEmpty##T(struct Queue##T *queue)                                                                \
    {                                                                                                          \
        return (queue->start == NULL);                                                                         \
    }                                                                                                          \
                                                                                                               \
    void enQueue##T(struct Queue##T *queue, T data)                                                            \
    {                                                                                                          \
        struct QueueElement##T *newElement = (struct QueueElement##T *)malloc(sizeof(struct QueueElement##T)); \
        newElement->data = data;                                                                               \
        newElement->ptrNextElement = NULL;                                                                     \
        if (isQueueEmpty##T(queue))                                                                            \
        {                                                                                                      \
            queue->start = newElement;                                                                         \
            queue->end = newElement;                                                                           \
        }                                                                                                      \
        else                                                                                                   \
        {                                                                                                      \
            queue->end->ptrNextElement = newElement;                                                           \
        }                                                                                                      \
        queue->end = newElement;                                                                               \
    }                                                                                                          \
                                                                                                               \
    int deQueue##T(struct Queue##T *queue)                                                                     \
    {                                                                                                          \
        if (isQueueEmpty##T(queue))                                                                            \
        {                                                                                                      \
            return NULL;                                                                                       \
        }                                                                                                      \
        if (queue->start->ptrNextElement == NULL)                                                              \
        {                                                                                                      \
            T lastValue = queue->start->data;                                                                  \
            free(queue->start);                                                                                \
            queue->start = NULL;                                                                               \
            return lastValue;                                                                                  \
        }                                                                                                      \
        T startValue = queue->start->data;                                                                     \
        struct QueueElement##T *newStart = queue->start->ptrNextElement;                                       \
        free(queue->start);                                                                                    \
        queue->start = newStart;                                                                               \
        return startValue;                                                                                     \
    }

#define QueueElement(T) QueueElement##T
#define Queue(T) Queue##T
#define isQueueEmpty(T) isQueueEmpty##T
#define enQueue(T) enQueue##T
#define deQueue(T) deQueue##T