/**
 * @author: XiaFan
 * @date: 2023-06-01 22:06
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

    std::priority_queue<std::pair<int, int>> q;
    q.push({0, 0});

    std::vector<int> d(n, inf), p(n, -1);
    d[0] = 0;
    while (!q.empty()) {
        auto t = q.top();
        int w = -t.first, u = t.second;
        q.pop();

        for (int i = 0; i < n; i++) {
            if (d[i] > d[u] + g[u][i]) {
                d[i] = d[u] + g[u][i];
                p[i] = u;
                q.push({-d[i], i});
            }
        }
    }

    for (int i = 1; i < n; i++) {
        std::vector<int> path;
        for (int u = i; u != -1; u = p[u]) {
            path.push_back(u);
        }
        std::cout << d[i] << ": ";
        for (int i = (int)path.size() - 1; i >= 0; i--) {
            std::cout << path[i] + 1;
            if (i) std::cout << "->";
            else std::cout << "\n";
        }
    }

    return 0;
}