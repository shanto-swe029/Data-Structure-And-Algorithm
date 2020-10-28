/*
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Insert a new element in a sorted array so that the array      |
        | remains sorted.                                               |
        -----------------------------------------------------------------
*/

#include <stdio.h>

void insertElement(int ara[], int sz, int indx, int newElement)
{
    int i;
    for(i = sz; i > indx; i--) {
        ara[i] = ara[i - 1];    // Right-Shifting all element from the index of the newElement
    }
    ara[indx] = newElement;     // Inserting the new element at desired index
}

int main()
{
    int sz;                 // declaring variable for storing the size of the array
    scanf("%d", &sz);       // taking the size of the array from user
    sz++;                   // incrementing the size by 1 as we have to insert one new element
    int ara[sz];            // declaring the array of the necessary size

    for(int i = 0; i < sz - 1; i++) {
        scanf("%d", &ara[i]);           // taking the sorted array from the user
    }

    int indx;                   // declaring variable for storing the index of the new element
    int newElement;             // declaring variable for storing the new element
    scanf("%d", &newElement);   // taking the new element from the user

    indx = sz - 1;      /* initializing the value of the index of the new element
                         * basing on the algorithm of this code
                         */

    if(ara[0] <= ara[sz-2]) {   // the array is ascending
        for(int i = 0; i < sz-1; i++){
            if(ara[i] >= newElement)        // determining the index of the new element for ascending array
            {
                indx = i;                   // so that the array remains sorted
                break;
            }
        }
    }
    else {      // the array is descending
        for(int i = 0; i < sz-1; i++){
            if(ara[i] <= newElement)        // determining the index of the new element for descending array
            {
                indx = i;                   // so that the array remains sorted
                break;
            }
        }
    }

    insertElement(ara, sz, indx, newElement);   // inserting the element at the desired position

    printf("The updated array is: ");
    for(int i = 0; i < sz; i++) {
        printf("%d ", ara[i]);      // printing the updated array
    }
    printf("\n");

    return 0;
}
