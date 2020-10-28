/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 004            --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Bubble Sort:                                                  |
        | 1. Sort an array                                              |
        | 2. Count the number of comparisons                            |
        | 3. Count the number of interchanges                           |
        -----------------------------------------------------------------
*/

#include <stdio.h>

int main()
{
    int n, comparisons = 0, interchanges = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int ara[n];
    printf("Enter the array below: \n");
    for (int i = 0; i < n; ++i)
        scanf("%d", &ara[i]);

    // sorting the array
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n - i; j++){
            comparisons++;
            if(ara[j] > ara[j+1]) {
                interchanges++;
                //swap
                ara[j]   ^= ara[j+1];
                ara[j+1] ^= ara[j];
                ara[j]   ^= ara[j+1];
            }
        }
    }
    //printing the sorted array
    printf("Your Sorted Array is : ");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", ara[i]);
    }
    printf("\n");
    printf("Number of comparisons = %d\n", comparisons);
    printf("Number of interchanges = %d\n", interchanges);

    return 0;
}
