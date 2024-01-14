/**
 * @author: XiaFan
 * @date: 2023-06-01 19:28
 */
#include <bits/stdc++.h>

using i64 = long long;
const int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> v;
    int x;
    while (std::cin >> x) {
        v.push_back(x);
    }

    int n = v.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, inf));
    std::vector<std::vector<int>> p(n, std::vector<int>(n, -1));

    for (int i = 1; i < n; i++) {
        for (int l = 0; l + i < n; l++) {
            int r = l + i;
            if (i == 1) {
                dp[l][r] = 0;
                continue;
            }

            for (int m = l + 1; m < r; m++) {
                int cost = dp[l][m] + dp[m][r] + v[l] * v[m] * v[r];
                if (cost < dp[l][r]) {
                    dp[l][r] = cost;
                    p[l][r] = m;
                }
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         std::string v = dp[i][j] == inf ? "inf" : std::to_string(dp[i][j]);
    //         std::cerr << v << " \n"[j == n - 1];
    //     }
    // }

    std::function<std::string (int, int)> dfs = [&](int l, int r) -> std::string {
        if (l + 1 == r) {
            return "A" + std::to_string(l + 1);
        } else {
            int m = p[l][r];
            return "(" + dfs(l, m) + dfs(m, r) + ")";
        }
    };

    std::cout << dfs(0, n - 1) << std::endl;

    return 0;
}