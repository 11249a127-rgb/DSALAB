
// aim:To solve Travelling Salesman Problem using Dynamic Programming (Bitmasking).

#include<stdio.h>
#include<limits.h>

#define MAXN 15
#define INF INT_MAX

int n, k;
int d[MAXN][MAXN];          // Cost matrix
int dp[MAXN][1<<MAXN];      // DP table

// Function to find minimum cost
int g(int i, int S)
{
    // If all cities visited, return cost to go back to start
    if(S == 0)
    {
        return d[i][0];
    }

    // If already computed, return stored value
    if(dp[i][S] != -1)
    {
        return dp[i][S];
    }

    int minCost = INF;

    // Try visiting all remaining cities
    for(k = 0; k < n; k++)
    {
        if(S & (1 << k))
        {
            int cost = d[i][k] + g(k, S & ~(1 << k));

            if(cost < minCost)
            {
                minCost = cost;
            }
        }
    }

    // Store result in DP table
    return dp[i][S] = minCost;
}

int main()
{
    int i, j, mask;

    // Taking number of cities
    printf("Enter the number of cities:\n");
    scanf("%d", &n);

    // Input cost matrix
    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &d[i][j]);
        }
    }

    // Initialize DP table with -1
    for(i = 0; i < n; i++)
    {
        for(mask = 0; mask < (1 << n); mask++)
        {
            dp[i][mask] = -1;
        }
    }

    // Create bitmask for all cities except starting city (0)
    int S = 0;
    for(i = 1; i < n; i++)
    {
        S |= (1 << i);
    }

    // Function call starting from city 0
    int result = g(0, S);

    // Display cost matrix
    printf("Given Cost Matrix:\n");
    for(i = 0; i < n; i++)
    {
        printf("|");
        for(j = 0; j < n; j++)
        {
            printf(" %d ", d[i][j]);
        }
        printf("|\n");
    }

    // Display result
    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
