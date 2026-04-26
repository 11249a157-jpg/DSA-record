#include <stdio.h>
#include <limits.h>

#define MAXN 15        // maximum number of cities
#define INF INT_MAX    // infinity value

int n;                        // number of cities
int d[MAXN][MAXN];            // cost matrix
int dp[MAXN][1 << MAXN];      // DP table for memoization

// function to find minimum cost
int g(int i, int s)
{
    // if all cities visited, return cost to go back to start
    if (s == 0)
        return d[i][0];

    // if already calculated, return stored value
    if (dp[i][s] != -1)
        return dp[i][s];

    int min_cost = INF;

    // try visiting all remaining cities
    for (int k = 0; k < n; k++)
    {
        // check if city k is in set s
        if (s & (1 << k))
        {
            // calculate cost of going to city k
            int cost = d[i][k] + g(k, s & ~(1 << k));

            // update minimum cost
            if (cost < min_cost)
                min_cost = cost;
        }
    }

    // store result in dp table
    return dp[i][s] = min_cost;
}

int main()
{
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");

    // input cost matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &d[i][j]);
        }
    }

    // initialize dp table with -1
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < (1 << n); s++)
        {
            dp[i][s] = -1;
        }
    }

    int s = 0;

    // create set of cities except starting city (0)
    for (int i = 1; i < n; i++)
    {
        s |= (1 << i);
    }

    printf("S value is: %d\n", s);

    // call function starting from city 0
    int result = g(0, s);

    // print minimum travelling cost
    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
