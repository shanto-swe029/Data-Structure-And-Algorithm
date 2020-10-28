/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 001            --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Using "Linear Search", find the largest and the smallest data |
        | from a dataset.                                               |
        -----------------------------------------------------------------
*/

#include <stdio.h>

int maximum(int a, int b)   // a function that returns the maximum of two numbers
{
    if(a > b) return a;
    return b;
}

int minimum(int a, int b)   // a function that returns the minimum of two numbers
{
    if(a < b) return a;
    return b;
}

int main()
{
    int max = -2147483648;  // declaring & initializing max for storing the maximum number from the array
    int min = 2147483647;   // declaring & initializing min for storing the minimum number from the array

    int sz;                 // declaring variable for storing the size of the array
    scanf("%d", &sz);       // taking the size of the array from user
    int ara[sz];            // declaring the array of the size given by the user

    for(int i = 0; i < sz; i++) {
        scanf("%d", &ara[i]);           // taking the array from the user
        max = maximum(max, ara[i]);     // filtering the maximum number from the array
        min = minimum(min, ara[i]);     // filtering the minimum number from the array
    }

    printf("maximum = %d\n", max);  // showing the maximum number from the array
    printf("minimum = %d\n", min);  // showing the minimum number from the array

    return 0;
}
