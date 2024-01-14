/**
 * @author: XiaFan
 * @date: 2023-06-01 22:26
 */
#include <bits/stdc++.h>

using i64 = long long;
const int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> g[i][j];
            if (g[i][j] == 0) {
                g[i][j] = inf;
            }
        }
    }

    std::vector<int> d(n, inf);

    std::priority_queue<std::array<int, 3>> q;
    q.push({0, 0, 0});
    int cnt = 0;
    std::vector<bool> vis(n);
    while (!q.empty()) {
        auto t = q.top();
        int w = -t[0], u = t[1], v = t[2];
        q.pop();

        if (vis[v]) continue;
        vis[v] = true;

        if (v) {
            std::cout << v + 1 << " " << u + 1 << " " << w << "\n";
            if (++cnt == n) break;
        }            

        for (int i = 0; i < n; i++) {
            if (d[i] > g[v][i]) {
                d[i] = g[v][i];
                q.push({-d[i], v, i});
            }
        }
    }

    return 0;
}