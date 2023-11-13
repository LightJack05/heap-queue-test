#include <stdio.h>
#include <stdlib.h>

struct queue_element
{
    int element;
    struct queue_element *ptrNextElement; // Pointer to the next element in the queue, enqueued later
};
struct queue_element *end;   // Pointer last element enqueued
struct queue_element *start; // Pointer first element in queue

/// @brief Check if the Queue is empty
/// @return 1 if empty, 0 if not
int isQueueEmpty()
{
    return (start == NULL);
}

/// @brief Add an element to the queue
/// @param element Element to add
void enQueue(int element)
{
    struct queue_element *newElement = (struct queue_element *)malloc(sizeof(struct queue_element));
    newElement->element = element;
    newElement->ptrNextElement = NULL;
    if (isQueueEmpty())
    {
        start = newElement;
        end = newElement;
    }
    else
    {
        end->ptrNextElement = newElement;
    }
    end = newElement;
}

/// @brief Remove the first element from the queue
/// @return The removed element
int deQueue()
{
    if (isQueueEmpty())
    {
        return NULL;
    }
    if (start->ptrNextElement == NULL)
    {
        int lastValue = start->element;
        free(start);
        start = NULL;
        return lastValue;
    }
    int startValue = start->element;
    struct queue_element *newStart = start->ptrNextElement;
    free(start);
    start = newStart;
    return startValue;
}

int main()
{
    start = NULL;
    enQueue(5);
    enQueue(6);
    enQueue(4);

    printf("%d\n", deQueue());
    printf("%d\n", deQueue());
    printf("%d\n", deQueue());

    enQueue(10);

    printf("%d\n", deQueue());
    printf("%d\n", deQueue());
}