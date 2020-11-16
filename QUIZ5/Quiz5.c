#include <stdio.h>
#include <stdlib.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_32_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char* argv[])
{
    unsigned int flag_holder[5] = { 0 };

    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);

    display_flags(flag_holder, 5);
    printf("\n\n");

    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);

    display_flags(flag_holder, 5);
    printf("Press any key to continue . . .\n");
    return 0;
}

/*
   Precondition: Function recieves array of unsigned in and integer value
   Postcondition: Confirms either zero or one at position specified
*/
void set_flag(unsigned int flag_holder[], int flag_position)
{
    int bitPosition = flag_position;   // Set position
    flag_position /= 32; // Divides by 32 to discovery access point

    flag_holder[flag_position] |= 1 << (bitPosition%32);
}

/*
    Precondition: Function receives array of zeros and ones and position
    Postcondition: Returns value for specific position
*/
int check_flag(unsigned int flag_holder[], int flag_position)
{
    int i; // Return variable
    int bitPosition = flag_position; // Set position
    flag_position /= 32; // Divides by 32 to discovery access point

    // If statement evulates to true return 1
    if((flag_holder[flag_position] >> bitPosition) & 1){
        i = 1;
    }
    // Return False
    else{
        i = 0;
    }

    return i;
}

/*
   Precondition: Function recieves unsigned integer array and integer value
   Postcondition: Sets bit in complement state
*/
void unset_flag(unsigned int flag_holder[], int flag_position)
{
    int bitPosition = flag_position; // Set position
    flag_position /= 32; // Divides by 32 to discover access point

    flag_holder[flag_position] &= ~(1 << (bitPosition%32));
}

/*
   Precondition: Receives unsigned integer array and size
   Postcondition: Iterates through the size passed to the function and calls
   print function that many times
*/
void display_flags(unsigned int flag_holder[], int size)
{
    // Iterates through the array and prints
    for(int i = 0; i < size; i++){
        display_32_flags_as_array(flag_holder[i]);
    }
}

/*
    Precondition: Function received unsigned int value
    Postcondition: Function iterates through 32 bits and prints series of
    zeros and ones
*/
void display_32_flags_as_array(unsigned int flag_holder)
{
    int i = 0; // Counter variable
    // Interate through whole bit stream
    while(i <= 31)
    {
        printf("%d", check_flag(&flag_holder, i));
        i++;
        
        //  Print space after four numbers
        if(i%4 == 0){
            printf(" ");
        }
    }
    printf("\n");
}
