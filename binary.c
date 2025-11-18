Aim:

To write a C program that performs binary search on a sorted array to find 
the position of a given element entered by the user.
Algorithm for Binary Search:

1.Start
2.Declare variables: n (size of array), i (loop counter), key (element to 
search), start, end, and mid.
3.Ask the user to enter the size of the array and read n.
4.Declare an array of size n.
5.Ask the user to enter n elements in sorted order and store them in the array.
6.Ask the user to enter the element (key) to be searched.
7.Initialize:
  start = 0
  end = n - 1
8.Repeat while start <= end:
  Compute mid = (start + end) / 2
  If arr[mid] == key:
    Print that the element is found at index mid
    Exit the algorithm

  Else if arr[mid] < key:
    Set start = mid + 1
  Else:
    Set end = mid - 1
9.If the loop ends without finding the element:
 Print "Element not found in the array"
10.Stop
program:
#include <stdio.h>

int main() 
{
    int n, i, key;
    
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the elements of array in sorted order:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    int start = 0, end = n - 1, mid;
    
    while (start <= end) {
        mid = (start + end) / 2;
        
        if (arr[mid] == key) {
            printf("\nElement found at index %d\n", mid);
            return 0;
        }
        else if (arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    printf("\nElement not found in the array.\n");
    return 0;
}
