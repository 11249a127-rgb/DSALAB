Aim

To write a C program that performs linear search on anarray to find the 
position of an element entered by the user.
Algorithm for Linear Search

1.Start
2.Declare variables:
  n → size of array
  i → loop counter
  key → element to be searched
3.Ask the user to enter the size of the array (n).
4.Declare an array A of size n.
5.Ask the user to enter n elements and store them in the array.
6.Ask the user to enter the element to be searched (key).
7.Set i = 0.
8.Repeat the following steps while i < n:
  If A[i] == key:
    Print that the element is found at index i.
    Stop the algorithm.
  Otherwise increment i.

9.If the loop exits without finding the key:
 Print "Element not found".
10.Stop
program:
#include<stdio.h>
int main()
{
    int n,i,key;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the elements of the array:\n");
    for (i=0; i<n; i++)
    {
        printf("Element %d:",i);
        scanf("%d", &A[i]);
    
    }

    printf("Enter element to find:");
    scanf("%d", &key);

    for(i=0; i<n; i++)
    {
        if (A[i] == key)
        {
        printf("\n\t\t Element found at index %d\n",i);
        return 0;
        }
    }

    printf("\n\t\t Element not found;");
    return 0;
}
