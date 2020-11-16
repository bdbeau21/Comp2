// Include File
#include <stdio.h>

int main(int argc, const char * argv[])
{
    unsigned int x =1;      // Initliaze unsigned int
    
    // For loop to print interation and x value
    for (int i =0;x!=0;i++)
    {
        printf("%u  %u\n", i, x);   // Prints values
        x= (x<<1);      // Shift x by 1
    }
    return 0;
}
