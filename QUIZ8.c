#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int main(void)
{
    PRIORITY_QUEUE hQueue = NULL;
    hQueue = priority_queue_init_default();
    if (hQueue == NULL)
    {
        printf("failed to create Queue\n");
        exit(-1);
    }
    
    priority_queue_insert(hQueue, 2, 4);
    priority_queue_insert(hQueue, 1, 5);
    priority_queue_insert(hQueue, 3, 3);
    priority_queue_insert(hQueue, 4, 2);
    priority_queue_insert(hQueue, 5, 1);
    priority_queue_insert(hQueue, -1, 6);
    
    // While queue is not empty
    while(!priority_queue_is_empty(hQueue)){
        printf("%d\n", priority_queue_front(hQueue, NULL));
        priority_queue_service(hQueue);
    }
    
    priority_queue_destroy(&hQueue);
    return 0;
}
