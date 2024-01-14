/**
 * @author: XiaFan
 * @date: 2023-04-21 09:55
 */
#include <bits/stdc++.h>

using i64 = long long;

struct point { int x, y; };

int main() {
    int n;
    std::cin >> n;
    std::vector<point> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].x >> a[i].y;
    }

    std::vector<std::vector<double>> dis(n, std::vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dx = a[i].x - a[j].x;
            int dy = a[i].y - a[j].y;
            dis[i][j] = std::hypot(dx, dy);
        }
    }

    std::function<double (int, int, int)> weight = [&](int i, int j, int k) {
        // assert(0 <= i && i < j && j < k && k < n);
        // std::cerr << i << " " << j << " " << k << std::endl;
        return dis[i][j] + dis[i][k] + dis[j][k];
    };

    std::vector<std::vector<double>> dp(n, std::vector<double>(n));
    std::vector<std::vector<int>> ans(n, std::vector<int>(n));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len < n; i++) {
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j] + weight(i, i + 1, j + 1);
            ans[i][j] = i;
            for (int k = i + 1; k < j; k++) {
                double t = dp[i][k] + dp[k + 1][j] + weight(i, k + 1, j + 1);
                if (t < dp[i][j]) {
                    dp[i][j] = t;
                    ans[i][j] = k;
                }
            }
        }
    }

    // std::cerr << std::fixed << std::setprecision(3);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         std::cerr << ans[i][j] << " ";
    //     }
    //     std::cerr << std::endl;
    // }      

    std::function<void (int, int)> find = [&](int i, int j) {
        if (i == j) return;
        find(i, ans[i][j]);
        find(ans[i][j] + 1, j);
        std::cout << i << ans[i][j] + 1 << j + 1 << std::endl;
    };

    find(0, n - 2);

    return 0;
}