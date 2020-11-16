#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define MAXCHAR 2048

// Main Program
int main()
{
    char string[MAXCHAR];   // Holds large string value
    int n;  // Number for strings
    
    // Input number of strings
    printf("How many strings will be tested: ");
    scanf("%d", &n);
    fflush(stdin);
    
    // Error checks number to be greater than zero
    while (n <= 0)
    {
        printf("Integer is less than zero!\n");
        // Re-input
        printf("Please enter a positive integer: ");
        scanf("%d", &n);
        fflush(stdin);
    }
    
    // Runs for loop for each string test value
    for(int i=0;i<n;i++){
        printf("Balance input: ");
        scanf("%s",string);
        // If string returns SUCCESS print yes
        if (balanced(string)){
            printf("Yes \n");
        }
        // Return Failure print No
        else{
            printf("No \n");
        }
    }
    return 0;
}
