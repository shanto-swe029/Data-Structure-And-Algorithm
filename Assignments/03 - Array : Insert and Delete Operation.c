/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 003            --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Array Manipulation:                                           |
        | 1. Sort the array                                             |
        | 2. Insert new element so that array remains sorted            |
        | 3. Delete an element so that array remains sorted             |
        -----------------------------------------------------------------
*/

#include <stdio.h>

int main()
{
	int n;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the array below: \n");
	int ara[n+10];
	for(int i = 0; i < n; i++) 
		scanf("%d", &ara[i]);
	// sorting the array
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(ara[i] > ara[j]) {
				int temp = ara[i];
				ara[i] = ara[j];
				ara[j] = temp;
			}
		}
	}
	//printing the array
	printf("\nYour sorted array is: \n");
	for(int i = 0; i < n; i++)
		printf("%d ", ara[i]);
	printf("\n");

	//adding new element
	printf("Enter the element you want to insert: ");
	int x;
	scanf("%d", &x);
	int indx = n;
	for(int i = n-1; i >= 0; i--) {
		if(ara[i] <= x) {
			indx = i + 1;
			break;
		}
		ara[i+1] = ara[i];
	}
	ara[indx] = x;

	// printing the new array
	printf("\nYour new array is: \n");
	for(int i = 0; i < n+1; i++)
		printf("%d ", ara[i]);
	printf("\n");

	//deleting element from the array
	printf("Enter the element you want to delete: ");
	printf("\n");
	scanf("%d", &x);
	indx = -1;
	for(int i = n-1; i >= 0; i--) {
		if(ara[i] == x) {
			indx = i;
			break;
		}
	}
	if(indx == -1)
		printf("Element Not Found.\n");
	else {
		printf("Succeddfully deleted %d.\n", x);
		for(int i = indx; i < n-1; i++) {
			ara[i] = ara[i+1];
		}
		// printing the new array
		printf("\nYour new array is: \n");
		for(int i = 0; i < n-1; i++)
			printf("%d ", ara[i]);
		printf("\n");
	}

    return 0;
}
