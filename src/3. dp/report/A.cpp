#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, inf));
    std::vector<std::vector<int>> p(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = 0;
        }
    }

    for (int z = 1; z < n; z++) {
        for (int i = 0; i + z < n; i++) {
            int j = i + z;
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += a[k];
            }
            for (int k = i; k + 1 <= j; k++) {
                if (dp[i][j] > dp[i][k] + dp[k + 1][j] + sum) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + sum;
                    p[i][j] = k + 1;
                }
            }
        }
    }

    std::cout << dp[0][n - 1] << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << dp[i][j] << " \n"[j == n - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << p[i][j] << " \n"[j == n - 1];
        }
    }

    return 0;
}