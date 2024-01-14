#include <bits/stdc++.h>

constexpr int INF = 1e9;

struct edge {
    int u, v, d;
    friend bool operator<(const edge &lhs, const edge &rhs) {
        return lhs.d > rhs.d;
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> G(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> G[i][j];
            if (G[i][j] == 0) G[i][j] = INF;
        }
    }

    std::priority_queue<edge> q;
    int start = 1;
    std::vector<int> dis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i != start) {
            dis[i] = G[start][i];
            q.push({start, i, G[start][i]});
        }
    }

    int cnt = 1;
    std::vector<bool> vis(n + 1);
    while (!q.empty()) {
        auto t = q.top();
        q.pop();

        int u = t.u, v = t.v, d = t.d;

        if (vis[v]) continue;
        vis[v] = true;

        std::cout << v << " " << u << " " << d << "\n";

        if (++cnt == n) break;

        for (int i = 1; i <= n; i++) {
            if (!vis[i] && G[v][i] < dis[i]) {
                dis[i] = G[v][i];
                q.push({v, i, G[v][i]});
            }
        }
    }

    return 0;
}
