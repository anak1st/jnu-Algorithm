/**
 * @author: XiaFan
 * @date: 2023-06-01 14:33
 */
#include <bits/stdc++.h>

using i64 = long long;

const int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second;
    }

    std::vector<std::vector<double>> d(n, std::vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dx = std::abs(a[i].first - a[j].first);
            int dy = std::abs(a[i].second - a[j].second);
            d[i][j] = std::sqrt(dx * dx + dy * dy);
        }
    }

    auto get = [&](int x, int y, int z) -> int {
        return d[x][y] + d[y][z] + d[z][x];
    };

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, inf));
    std::vector<std::vector<int>> p(n, std::vector<int>(n));

    for (int i = 1; i < n; i++) {
        for (int l = 0; l + i < n; l++) {
            int r = l + i;
            p[l][r] = l;
            // dp[l][r] = dp[l][m] + dp[m][r] + get(l, m, r);
            if (i == 1) {
                dp[l][r] = 0;
                continue;
            }
            for (int m = l + 1; m < r; m++) {
                if (dp[l][r] > dp[l][m] + dp[m][r] + get(l, m, r)) {
                    dp[l][r] = dp[l][m] + dp[m][r] + get(l, m, r);
                    p[l][r] = m;
                }
            }
        }
    }

    // std::cout << dp[0][n - 1] << "\n";

    std::function<void (int, int)> dfs = [&](int l, int r) -> void {
        if (l + 1 == r) {
            return;
        }
        int m = p[l][r];
        dfs(l, m);
        dfs(m, r);
        std::cout << l << "" << m << "" << r << "\n";
    };

    dfs(0, n - 1);

    return 0;
}