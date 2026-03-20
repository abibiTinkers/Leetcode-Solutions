#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int numberOfStableArrays(int zero, int one, int limit) {
    // dp[i][j][last_bit]
    // Using long to prevent overflow during subtraction/addition before modulo
    long ***dp = (long ***)malloc((zero + 1) * sizeof(long **));
    for (int i = 0; i <= zero; i++) {
        dp[i] = (long **)malloc((one + 1) * sizeof(long *));
        for (int j = 0; j <= one; j++) {
            dp[i][j] = (long *)calloc(2, sizeof(long));
        }
    }

    // Base cases: arrays with only 0s or only 1s
    for (int i = 1; i <= (zero < limit ? zero : limit); i++) dp[i][0][0] = 1;
    for (int j = 1; j <= (one < limit ? one : limit); j++) dp[0][j][1] = 1;

    for (int i = 1; i <= zero; i++) {
        for (int j = 1; j <= one; j++) {
            // Ending with 0
            // Current = (Prev_with_0 + Prev_with_1) - (Invalid_sequences)
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
            if (i > limit) {
                // Subtract arrays that would now have limit+1 zeros
                dp[i][j][0] = (dp[i][j][0] - dp[i - limit - 1][j][1] + MOD) % MOD;
            }

            // Ending with 1
            dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
            if (j > limit) {
                // Subtract arrays that would now have limit+1 ones
                dp[i][j][1] = (dp[i][j][1] - dp[i][j - limit - 1][0] + MOD) % MOD;
            }
        }
    }

    int result = (dp[zero][one][0] + dp[zero][one][1]) % MOD;

    // Cleanup memory
    for (int i = 0; i <= zero; i++) {
        for (int j = 0; j <= one; j++) free(dp[i][j]);
        free(dp[i]);
    }
    free(dp);

    return result;
}
