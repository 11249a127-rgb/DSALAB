// AIM:
// To implement First Fit algorithm for Bin Packing problem.

#include <stdio.h>

// Function to apply First Fit algorithm
void firstFit(int items[], int n, int capacity) 
{ 
    int bin[n];       
    int binCount = 0;

    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++) 
        bin[i] = capacity; 

    // Place each item
    for (int i = 0; i < n; i++) 
    {
        int placed = 0; 

        // Try placing item in existing bins
        for (int j = 0; j < binCount; j++) 
        { 
            if (bin[j] >= items[i]) 
            { 
                bin[j] -= items[i]; 
                printf("Item %d placed in Bin %d\n", items[i], j + 1);     
                placed = 1;          
                break;
            }  
        }     

        // If not placed, create new bin
        if (!placed) 
        { 
            bin[binCount] -= items[i]; 
            printf("Item %d placed in Bin %d\n", items[i], binCount + 1); 
            binCount++; 
        } 
    } 

    // Display total bins used
    printf("Total bins used = %d\n", binCount);
}  

int main() 
{ 
    int n, capacity; 

    // Taking number of items
    printf("Enter number of items: "); 
    scanf("%d", &n);  

    // Taking bin capacity
    printf("Enter bin capacity: "); 
    scanf("%d", &capacity); 

    int items[n];  

    // Input item sizes
    printf("Enter item sizes:\n"); 
    for (int i = 0; i < n; i++) 
    { 
        int itemSize; 
        printf("Item %d: ", i + 1); 
        scanf("%d", &itemSize); 
  
        // Validate input
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
    firstFit(items, n, capacity); 

    return 0; 
}
