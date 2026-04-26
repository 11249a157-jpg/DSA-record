#include<stdio.h>

// function to solve Tower of Hanoi
void towerofhanoi(int n, char s, char d, char t)
{
    // base case: only one disk
    if(n == 1)
    {
        printf("Move disk %d from %c to %c\n", n, s, d);
        return;
    }

    // move n-1 disks from source to temporary
    towerofhanoi(n-1, s, t, d);

    // move nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, s, d);

    // move n-1 disks from temporary to destination
    towerofhanoi(n-1, t, d, s);
}

int main()
{
    int n;

    // input number of disks
    printf("Enter no. of disks: ");
    scanf("%d", &n);

    // call function (s = source, d = destination, t = temporary)
    towerofhanoi(n, 'S', 'D', 'T');

    return 0;
}
