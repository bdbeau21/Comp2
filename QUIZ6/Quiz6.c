#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node* next;
};

//declare your function here.
void reverse(Node** header);
// Free memory
void destroy_list(Node** header);


int main(int argc, char* argv[])
{
    Node* head = NULL;
    int i;
    Node* temp;

    //set up a test list with values 9->8->7->...->0
    for (i = 0; i < 10; i++)
    {
        temp = (Node*)malloc(sizeof(Node));
        if (temp == NULL)
        {
            printf("out of memory?\n");
            exit(1);
        }
        temp->data = i;
        temp->next = head;
        head = temp;
    }
    
    //call your function to reverse the list (should work for any list given the head node).
    reverse(&head);

    //print the reversed list.
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    destroy_list(&head);
    destroy_list(&temp);
    return 0;
}

/*
    Precondition: Structure Node received with 10 numbers
    Postcondition: Linked list is reverse and return by pointer
*/
void reverse(Node** header)
{
    Node* previous = NULL;          // Previous Node
    Node* current = *header;        // Current Node
    Node* next = NULL;              // Next Node
    
    // Makes sure node is not empty
    while (current != NULL)
    {
        // Stores the next node
        next = current->next;
      
        // Changes directioj of node
        current->next = previous;
      
        // Pointer is shifted
        previous = current;
        current = next;
        
        // Points previous to head
        *header = previous;
    }
}

/*
    Precondition: Node received with allocated space
    Postcondition: Memory is freed
 */
void destroy_list(Node** header)
{
    Node* temp;
    while(*header != NULL){
        temp = *header;
        *header = (*header)->next;
        free(temp);
    }
}
