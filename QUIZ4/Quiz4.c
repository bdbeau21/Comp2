// Include Section
#include <stdio.h>

// Function Section
void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int * flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

int main(int argc, char* argv[])
{
    unsigned int flag_holder = 0;
    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);

    display_32_flags(flag_holder);
    
    unset_flag(&flag_holder, 31);
    unset_flag(&flag_holder, 3);
    set_flag(&flag_holder, 9);
    
    display_32_flags(flag_holder);
    return 0;
}

/*
    Precondition: Function recieves addresss and integer value
    Postcondition: Confirms either zero or one at position specified
 */
void set_flag(unsigned int* flag_holder, int flag_position)
{
    //*flag_holder = *flag_holder | (1<< flag_position);
    *flag_holder |= (1<< flag_position);
}

/*
    Precondition: Function receives values of zeros and ones
    Postcondition: Returns value for specific position
*/
int check_flag(unsigned int flag_holder, int flag_position)
{
    return (flag_holder >> flag_position) & 1;
}

/*
   Precondition: Function recieves address and integer value
   Postcondition: Sets bit in complement state
*/
void unset_flag(unsigned int * flag_holder, int flag_position)
{
    *flag_holder ^=1<<flag_position;
}

/*
    Precondition: Receives unset integer value
    Postcondition: Iterates through 32 bytes and
    prints a certain pattern of zeroes and ones.
 */
void display_32_flags(unsigned int flag_holder)
{
    // Used to iterate though 32 bits
    for(int i=31; i>=0; i--)
    {
        printf("%d", check_flag(flag_holder, i));
        // Prints space after 4 integers
        if(i%4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}
