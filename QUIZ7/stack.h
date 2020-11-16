#ifndef stack_h
#define stack_h

typedef struct node Node;   // Change struct node to Node

// Struct to use for Stack
struct node
{
   char data;   // Holds characters
   Node *next;  // Holds next pointer
};
typedef enum{FAILURE,SUCCESS}STATUS;    // Used to determine success of function

/*
    Precondition: Function receives top of stack and integer value
    Postcondition: Data is pushed onto the stack
*/
void push(Node** head, int new_data);

/*
    Precondition: Function receives top value of stack
    Postcondition: Items are pop of top of stack if called
*/
int pop(Node** head);

/*
    Precondition: Two char items are passed to function
    Postcondition: Return SUCCESS if pair is matching
*/
STATUS isMatchingPair(char item1, char item2);

/*
    Precondtion: Function receives char input
    Postcondtion: Returns true if string is balanced equally
*/
STATUS balanced(char input[]);


#endif /* stack_h */
