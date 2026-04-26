#include <stdio.h>

// Function to apply Best Fit bin packing algorithm
void bestFit(int items[], int n, int capacity) 
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];          // array to store remaining space in each bin
    int binCount = 0;    // keeps track of how many bins are used

    // initially all bins have full capacity
    for (int i = 0; i < n; i++) 
    {
        bin[i] = capacity;
    }

    // loop through each item
    for (int i = 0; i < n; i++) 
    {
        int bestIndex = -1;         // to store best bin index
        int minSpace = capacity + 1; // to find minimum leftover space

        // check all existing bins
        for (int j = 0; j < binCount; j++)
        {
            // check if item fits and leaves minimum space
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace) 
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        // if suitable bin found
        if (bestIndex != -1) 
        {
            bin[bestIndex] -= items[i];  // reduce space in that bin
            printf("Item %d (Weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        } 
        else
        {
            // if no bin fits, create a new bin
            bin[binCount] = capacity - items[i];
            printf("Item %d (Weight: %d) placed in Bin %d\n", i + 1, items[i], binCount + 1);
            binCount++;
        }
    }

    // print total bins used
    printf("Total bins used = %d\n", binCount);
}

int main()
{
    int n, capacity;

    // get number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n];  // array to store item sizes

    // get bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    printf("Enter item sizes:\n");

    // input item sizes
    for (int i = 0; i < n; i++)
    {
        int itemSize;
        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);

        // check if item fits in bin
        if (itemSize <= capacity) 
        {
            items[i] = itemSize;
        } 
        else 
        {
            // if too big, ask again
            printf("Item size exceeds bin capacity. Please enter a valid size.\n");
            i--;  // repeat this iteration
        }
    }

    // call best fit function
    bestFit(items, n, capacity);

    return 0;
}
