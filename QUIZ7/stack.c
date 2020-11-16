#include<stdio.h>
#include<stdlib.h>
#include"stack.h"


// Returns SUCCESS if pair is matching and FAILURE if not
STATUS isMatchingPair(char item1, char item2)
{
    // Matching Braces
    if (item1 == '{' && item2 == '}'){
        return SUCCESS;
    }
    // Matching Parenthesis
    else if (item1 == '(' && item2 == ')'){
        return SUCCESS;
    }
    // Matching Brackets
    else if (item1 == '[' && item2 == ']'){
        return SUCCESS;
    }
    // Not matching
    else{
        return FAILURE;
    }
}

// Return SUCCESS if input is balance, FAILURE otherwise
STATUS balanced(char input[])
{
   int i = 0;   // Declare counter variable
   Node *temp = NULL;   // Declare temp stack
  
   // Iterate through input to determine balance
   while (input[i])
   {
      // Push onto stack if left assigned char
       if (input[i] == '{' || input[i] == '[' || input[i] == '('){
        push(&temp, input[i]);
       }
       
      // Pop off stack if right assigned char
      if (input[i] == '}' || input[i] == ']' || input[i] == ')')
      {
          // Single left end char
          if (temp == NULL){
              return FAILURE;
          }
          // If no pair pop item
          else if (!isMatchingPair(pop(&temp), input[i])){
              return FAILURE;
          }
      }
      // Increment
      i++;
   }
     
   // Check if stack is empty
    if (temp == NULL){
        return SUCCESS;
    }
    // Left ended char value remaining
    else{
        return FAILURE;
    }
}

// Push item onto the stack
void push(Node** head, int new_data)
{
    Node* phead=(Node*)malloc(sizeof(Node*)); // Allocate space
    
    // If Node is empty
    if (phead == NULL)
    {
        printf("EMPTY!!!");
        getchar();
        exit(-1);
    }
  

    phead->data  = new_data;     // Assign data
    phead->next = *head;     // Top Stack
    *head= phead;    // Node change head
}

// Pop top of stack
int pop(Node** head)
{
    char word;  // Char value
    Node* top;  // Node of stack
  
    // If head is NULL
    if (*head == NULL)
    {
        printf("EMPTY!!!");
        getchar();
        exit(0);
    }
    else
    {
        top = *head;    // Assign after head
        word = top->data;   // Assign value of data
        *head = top->next;  // Points to next
        free(top);          // Free data
        return word;        // return int
    }
}
