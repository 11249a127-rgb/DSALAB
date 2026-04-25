// AIM:
// To sort elements using Randomized Quick Sort algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two numbers
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];   // Pivot element
    int i = low - 1;

    for (int j = low; j < high; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);   // <-- fixed semicolon
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Randomized Quick Sort
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        // Choose random pivot
        int randomIndex = low + rand() % (high - low + 1);
        swap(&arr[randomIndex], &arr[high]);

        // Partition
        int pi = partition(arr, low, high);

        // Recursive calls
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() 
{
    int n;

    srand(time(NULL)); // Initialize random seed

    // Input number of elements
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int numbersToSort[n];

    // Input elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) 
        scanf("%d", &numbersToSort[i]);

    // Sort array
    quickSort(numbersToSort, 0, n - 1);

    // Display sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) 
        printf("%d ", numbersToSort[i]);

    printf("\n");

    return 0;
}
