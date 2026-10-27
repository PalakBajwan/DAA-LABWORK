#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // p contains n+1 dimensions for n matrices
    vector<int> p(n + 1);

    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    vector<vector<int>> dp(n + 1,
                           vector<int>(n + 1, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << "Minimum multiplications = "
         << dp[1][n] << endl;

    return 0;
}