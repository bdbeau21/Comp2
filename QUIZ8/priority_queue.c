#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

typedef struct item Item;
struct item
{
    int priority;   // Priority level
    int item;       // Data Value
};

typedef struct queue Queue;
struct queue
{
    int size;   // Size of queue
    int capacity;   // Capacity of queue
    int front;  // Front of queue
    int back;   // Back of queue
    Item* data; // Data for queue
};

// Create and return empty priority queue
PRIORITY_QUEUE priority_queue_init_default(void)
{
    // Allocate Space
    Queue* pQueue= (Queue*)malloc(sizeof(Queue));
    
    // Checks if Queue was properly allocated
    if (pQueue != NULL)
    {
        pQueue->size = 0;
        pQueue->capacity = 7;
        pQueue->front = 0;
        pQueue->back = 0;
        
        // Allocate space for data
        pQueue->data = (Item*)malloc(sizeof(Item)*pQueue->capacity);
        
        // Checks if space is properly allocated
        if (pQueue->data == NULL)
        {
            free(pQueue);
            pQueue = NULL;  // Makes sure the queue is freed
        }
    }
    return pQueue;
}

/*
    Return SUCCESS: if item propely added to queue
    Return FAILURE: otherwise it is not
 */
Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
    Queue* pQueue = (Queue*)hQueue;
    Item* resize,temp;
    int i; // i is a tracker for length of queue
    int j; // j holds the value for the index of parent
    
    // If size is greater than capacity resize
    if (pQueue->size >= pQueue->capacity)
    {
        // Allocate space with double capacity
        resize = (Item*)malloc(sizeof(Item)* pQueue->capacity*2);
        
        // Make sure space is properly allocated
        if (resize == NULL)
        {
            printf("FAILED TO ALLOCATE\n");
            return FAILURE;
        }
        
        // Fill with current values
        for (i = 0; i < pQueue->size; i++)
        {
            resize[i] = pQueue->data[i];

        }
        pQueue->capacity *= 2;  // Double size of variable capacity
        free(pQueue->data);     // Free memory after being assigned
        pQueue->data = resize;
    }
    i = pQueue->size;   // Counter set equal to size
    
    // Assign values to data of queue
    (pQueue->data[i]).item = data_item;
    (pQueue->data[i]).priority = priority_level;
    
    // Index of parent
    j = (i - 1) / 2;
    
    // While pirority level is greater than parent and queue is not empty
    while (!priority_queue_is_empty(pQueue) &&((pQueue->data[i]).priority) > (pQueue->data[j]).priority)
    {
        // Changes poisition of child and parent
        temp = pQueue->data[j];
        pQueue->data[j] = pQueue->data[i];
        pQueue->data[i] = temp;
        i = j; // set index equal to size
        j = (i - 1) / 2;    // Reset the value of size
    }
    pQueue->front = 0;  // Change the front of queue
    pQueue->size++;  // Increment size
    pQueue->back= pQueue->size-1;  // Alter back of queue
    return SUCCESS;
}

/*
    Returns SUCCESS: if highest proirty item was removed
    Returns FAILURE: if queue is empty
*/
Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
    Queue* pQueue = (Queue*)hQueue;
    Item* temp=(Item*)malloc(sizeof(Item));
    Item* hold=(Item*)malloc(sizeof(Item));
    int i = 0, f = 1;    // Index and flag
    int lchild = (i*2)+1; // Create left child
    int rchild = (i*2)+2; // Create right child
    
    // If queue is empty return FAILURE
    if (priority_queue_is_empty(pQueue))
    {
        printf("Queue is empty\n");
        return FAILURE;
    }

    // Set temp item equal to front
    *temp = pQueue->data[0];
    pQueue->data[0] = pQueue->data[pQueue->back];
    pQueue->data[pQueue->back] = *temp;
    pQueue->size--; // Decrease size
    
    
    // Left Child is less than size
    while (lchild < pQueue->size && f==1)
    {
        f = 0;  // Set flag to zero

        // If right child is less than size and right child has a higher priority level
        if (rchild < pQueue->size && (pQueue->data[rchild]).priority>(pQueue->data[lchild]).priority)
        {
            if((pQueue->data[rchild]).priority>(pQueue->data[i]).priority)
            {// Swap positions of queue data of current index and right child
                *hold = pQueue->data[i];
                pQueue->data[i] = pQueue->data[rchild];
                pQueue->data[rchild] = *hold;
                i = rchild;
            
                // Readjust values of children
                lchild = (i*2) + 1;
                rchild = (i*2) + 2;
                f = 1;
            }
        }
        
        /*
            If right child is greater than size or left child has a higher
            priority level than right child
        */
        else
        {
            // Left child has higher priority level than right child
            if ((pQueue->data[lchild]).priority > (pQueue->data[i]).priority)
            {
                // Swap places of current index and left child
                *hold = pQueue->data[i];
                pQueue->data[i] = pQueue->data[lchild];
                pQueue->data[lchild] = *hold;
                i = lchild;
                
                // Readjust values of children
                lchild = (i*2)+ 1;
                rchild = (i*2)+ 2;
                f = 1;
            }
        }
    }
    // Queue removes item so back is decreased
    pQueue->back=pQueue->size - 1;
    return SUCCESS;
}

/*
    Returns: data value in front
    Sets to SUCCESS: if there is at least one item in queue
    Sets to FAILURE: otherwise it is not
*/
int priority_queue_front(PRIORITY_QUEUE hQueue, Status* status)
{
    Queue* pQueue = (Queue*)hQueue;
    
    // Return boolean type for queue emptiness
    if (priority_queue_is_empty(pQueue))
    {
        // If status is NULL, status ignored
        if (status != NULL)
        {
            *status = FAILURE;
        }
        // Return unique number to recognize error
        return -3.14159265;
    }
    
    // Queue is not empty and passed status of NULL
    if (status != NULL)
    {
        *status = SUCCESS;
    }
    
    // Return data value for front
    return ((pQueue->data[pQueue->front]).item);
}


/*
    Returns TRUE: if priority queue is empty
    Returns FALSE: otherwise it is not
*/
Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
    Queue* pQueue = (Queue*)hQueue;
    
    // Return true or false based on if queue is empty
    return (Boolean)(pQueue->size==0);
}

// Free the memory from the queue
void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
    Queue* pQueue = (Queue*)*phQueue;
    Item* temp;
    free(pQueue->data);
    free(*phQueue);
    *phQueue = NULL;    // Confirms memory is free
}
