#include <stdio.h>

// structure to store item details
struct Item {
    int Weight;
    int Value;
    float PPW; // Profit Per Weight (value/weight ratio)
};

// function to sort items based on PPW (descending order)
void sort(struct Item items[], int n)
{
    struct Item temp;

    // bubble sort based on ratio
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            // swap if next item has higher ratio
            if (items[j].PPW < items[j + 1].PPW)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    // print sorted items
    printf("Items sorted by value/weight ratio:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: Weight = %d, Value = %d, Ratio = %.2f\n", 
                i + 1, items[i].Weight, items[i].Value, items[i].PPW);
    }
}

int main() 
{
    int n;
    float capacity;

    // input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // input weight and value of each item
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].Weight, &items[i].Value);

        // calculate value per weight ratio
        items[i].PPW = (float)items[i].Value / items[i].Weight;
    }

    // input knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // sort items by highest ratio first
    sort(items, n);

    float totalProfit = 0.0;

    // apply fractional knapsack logic
    for (int i = 0; i < n; i++)
    {
        // if whole item can be taken
        if (capacity >= items[i].Weight)
        {
            totalProfit += items[i].Value;
            capacity -= items[i].Weight;
        } 
        else 
        {
            // take fractional part of item
            totalProfit += items[i].PPW * capacity;
            capacity = 0; // knapsack becomes full
            break;
        }
    }

    // print maximum profit
    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
