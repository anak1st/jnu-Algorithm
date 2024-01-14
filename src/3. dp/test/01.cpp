/**
 * @author: XiaFan
 * @date: 2023-04-25 15:36
 */
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n;
    std::cin >> m >> n;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }
    std::reverse(a.begin() + 1, a.end());
    std::reverse(b.begin() + 1, b.end());

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j >= b[i]) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - b[i]] + a[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    std::cout << dp[n][m] << std::endl;
    std::vector<int> ans;
    for (int i = n, j = m; i > 0; i--) {
        if (dp[i][j] > dp[i - 1][j]) {
            ans.push_back(i);
            j -= b[i];
        }
    }

    for (int i = 0; i < (int)ans.size(); i++) {
        std::cout << n + 1 - ans[i] << " ";
    }

    return 0;
}