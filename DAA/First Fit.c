#include <stdio.h>

// Function to implement First Fit bin packing
void firstFit(int items[], int n, int capacity) 
{
    int bin[n];        // array to store remaining space in bins
    int binCount = 0;  // number of bins used

    printf("\nExecuting First Fit Algorithm\n");

    // initially no bins are used, so set all to 0
    for (int i = 0; i < n; i++) 
    {
        bin[i] = 0;
    }

    // loop through each item
    for (int i = 0; i < n; i++) 
    {
        // if item is larger than capacity, skip it
        if (items[i] > capacity)
        {
            printf("Item %d with size %d cannot be placed in any bin\n", i + 1, items[i]);
            continue;
        }

        int placed = 0;  // flag to check if item is placed

        // check each existing bin (first fit condition)
        for (int j = 0; j < binCount; j++) 
        {
            if (bin[j] >= items[i]) 
            {
                bin[j] -= items[i];  // reduce remaining space
                printf("Item %d placed in Bin %d\n", items[i], j + 1);
                placed = 1;
                break;  // stop after first suitable bin
            }
        }

        // if item not placed in any bin, create new bin
        if (!placed) 
        {
            bin[binCount] = capacity;      // new bin with full capacity
            bin[binCount] -= items[i];     // place item in it
            printf("Item %d placed in Bin %d\n", items[i], binCount + 1);
            binCount++;
        }
    }

    // print total bins used
    printf("Total bins used = %d\n", binCount);
}

int main() 
{
    int n, capacity;

    // input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n];  // array to store item sizes

    // input item sizes
    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);
    }

    // input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    // call first fit function
    firstFit(items, n, capacity);

    return 0;
}
