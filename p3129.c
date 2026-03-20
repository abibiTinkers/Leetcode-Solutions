#include <stdio.h>
#include <string.h>

#define MOD 1000000007

long long dp[201][201][2];

int numberOfStableArrays(int zero, int one, int limit)
{
    memset(dp,0,sizeof(dp));

    // base cases
    for(int i=1;i<=zero && i<=limit;i++)
        dp[i][0][0]=1;

    for(int j=1;j<=one && j<=limit;j++)
        dp[0][j][1]=1;

    for(int i=0;i<=zero;i++)
    {
        for(int j=0;j<=one;j++)
        {
            for(int k=1;k<=limit && k<=i;k++)
                dp[i][j][0] = (dp[i][j][0] + dp[i-k][j][1]) % MOD;

            for(int k=1;k<=limit && k<=j;k++)
                dp[i][j][1] = (dp[i][j][1] + dp[i][j-k][0]) % MOD;
        }
    }

    return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
}
