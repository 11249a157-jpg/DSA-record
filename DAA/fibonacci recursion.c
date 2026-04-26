#include <stdio.h>

// recursive function to find nth Fibonacci number
int fib(int n)
{
    // base case: fib(0) = 0
    if(n == 0)
    {
        return 0;
    }

    // base case: fib(1) = 1
    if(n == 1)
    {
        return 1;
    }

    // recursive case: fib(n) = fib(n-1) + fib(n-2)
    return fib(n-1) + fib(n-2);
}

int main()
{
    int n, result;

    // take input from user
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // check for invalid input
    if(n < 0)
    {
        printf("Invalid number");
        return 0;
    }

    // call fibonacci function
    result = fib(n);

    // print result
    printf("Fibonacci term : %d", result);

    return 0;
}
