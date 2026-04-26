// AIM :
// To implement Best Fit algorithm for Bin Packing problem.

#include <stdio.h>

// Function to apply Best Fit algorithm
void bestFit(int items[], int n, int capacity) 
{ 
    printf("\nBest Fit Algorithm\n");

    int bin[n]; 
    int binCount = 0; 

    // Initialize bins with full capacity
    for (int i = 0; i < n; i++) 
        bin[i] = capacity; 

    // Place each item
    for (int i = 0; i < n; i++) 
    { 
        int bestIndex = -1; 
        int minSpace = capacity + 1; 

        // Find best bin (minimum leftover space)
        for (int j = 0; j < binCount; j++) 
        { 
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace) 
            { 
                bestIndex = j; 
                minSpace = bin[j] - items[i]; 
            } 
        } 

        // If suitable bin found
        if (bestIndex != -1) 
        { 
            bin[bestIndex] -= items[i]; 
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        } 
        else 
        {
            // Create new bin
            bin[binCount] -= items[i]; 
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], binCount + 1); 
            binCount++; 
        }
    } 

    // Display total bins used
    printf("Total bins used = %d\n", binCount); 
} 

int main() 
{ 
    int n, capacity;   

    // Input number of items
    printf("Enter number of items: "); 
    scanf("%d", &n);  

    int items[n];   

    // Input bin capacity
    printf("Enter bin capacity: "); 
    scanf("%d", &capacity); 

    // Input item sizes
    printf("Enter item sizes:\n"); 
    for (int i = 0; i < n; i++) 
    { 
        int itemSize; 
        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);

        // Validate item size
        if (itemSize <= capacity) 
        { 
            items[i] = itemSize; 
        } 
        else 
        { 
            printf("Item size exceeds bin capacity. Please enter a valid size.\n"); 
            i--; 
        } 
    }  

    // Function call
    bestFit(items, n, capacity); 

    return 0; 
}
