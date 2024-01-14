/**
 * @author: XiaFan
 * @date: 2023-06-01 18:11
 */
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n;
    std::cin >> m >> n;
    std::vector<int> w(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> w[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j >= w[i]) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         std::cerr << dp[i][j] << " \n"[j == m];
    //     }
    // }

    std::cout << dp[n][m] << "\n";

    int t = m;
    for (int i = n; i >= 1 && t; i--) {
        if (dp[i][t] != dp[i - 1][t]) {
            t -= w[i];
            std::cout << i << " ";
        }
    }

    return 0;
}