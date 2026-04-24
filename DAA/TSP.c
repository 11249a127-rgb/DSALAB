#include <stdio.h>
#include <limits.h>
#define MAXN 15
#define INF INF_MAX
int n;
int d[MAXN][MAXN];
int dp[MAXN][1 << MAXN];
int g(int i,int s)
{
    if (s==0)
        return d[i][0];
    if (dp[i][s] != -1)
        return dp[i][s];
    int mincost = INF;
    for (int k = 0; k < n; k++)
    {
        if (s & (1 << k))
        {
            int cost = d[i][k] + g(k,s & ~(1 <<k));
            if (cost < mincost)
            {
                mincost = cost;
            }
        }
    }
    return dp[i][s] = mincost;
}
int main()
{
    printf("ewnter number of cities:");
    scanf("%d",&n);
    printf("enter cost matrix:\n");
    for (int i=0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &d[i][j]);
    for (int i = 0;i < n; i++)
        for (int mask =0; mask < (1 << n); mask++)
        {
            dp[i][mask] = -1;
        }
    int s = 0;
    for (int i = 1;i <n; i
    ++)
        s |= (1 << i);
    int result = g(0,s);
    printf("given cost matrix\n");
    for(int i = 0;i < n; i++)
    {
        printf("|");
        for (int j = 0; j<n;j++)
            printf("%d",d[i][j]);
        printf("|\n");
    }
    printf("minimum travelling cost: %d\n", result);
    return 0;
}
