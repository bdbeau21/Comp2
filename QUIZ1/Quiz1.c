#include <stdio.h>
#include <stdlib.h>

// Function to find maximum numbers index in array
int find_max(int arr[],int num);

int main(int argc, const char * argv[])
{
    int n=-1,*a;    // Declare n and a
    
    // Asks user for positive integer
    printf("Input a positive integer: ");
    scanf("%d",&n);
    fflush(stdin);  // Flushes input
    
    // Input must be greater than 0
    while(n<=0)
    {
        printf("Number is not a positive integer: ");
        scanf("%d",&n);
        fflush(stdin);      // Flushes input
    }
    
    a =(int*) calloc(n, sizeof(int)); // Allocate space for array
    
    // Generate random numbers for each array index of length n
    for(int i =0; i<n; i++)
    {
        a[i]= rand();
    }
    
    int index = find_max(a,n);  // Index is returned for largest random value in array
    printf("The maximum value in the array is: %d\n", index);
    free(a);    // Frees up space after completion
    return 0;
}

/*
    Precondition: Function takes an array of num values with space allocated
    Postcondition: The index is returned from largest value in the array of random values
*/
int find_max(int arr[],int num)
{
    int temp = 0, hold=0;    // Local variables declared and initialized
    
    // For loop to iterate through array
    for (int k = 0;k<num;k++)
    {
        // If statement finds the maximum value in area
        if (arr[k] > temp)
        {
            temp = arr[k];  // Temp receives new maximum value
            hold =k; // Index is the counter
        }
    }
    return hold;     // Index returned
}
