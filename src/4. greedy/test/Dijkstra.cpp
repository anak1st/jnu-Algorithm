#include <bits/stdc++.h>

constexpr int inf = 1e9;

struct Edge {
    int u, w;

    Edge() : u(0), w(0) { }
    Edge(int u, int w) : u(u), w(w) { }

    friend bool operator<(const Edge& lhs, const Edge& rhs) {
        return lhs.w > rhs.w;
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<int, int>>> adj(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            int x;
            std::cin >> x;
            if (x == 0) continue;
            adj[i].push_back({j, x});
        }
    }

    std::priority_queue<Edge> Q;
    Q.push(Edge(0, 0));
    for (auto& x : adj[0]) {
        Q.push(Edge(x.first, x.second));
    }

    std::vector<int> D(n, inf);
    D[0] = 0;
    std::vector<int> P(n, -1);

    while (!Q.empty()) {
        auto e = Q.top();
        Q.pop();
        auto u = e.u;
        // auto d = e.w;
        // std::cerr << u << ' ' << d << '\n';

        for (auto& x : adj[u]) {
            auto &v = x.first;
            auto &w = x.second;
            if (D[v] > D[u] + w) {
                D[v] = D[u] + w;
                P[v] = u;
                Q.push(Edge(v, D[v]));
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     std::cout << D[i] << " \n"[i == n - 1];
    // }

    for (int i = 1; i < n; i++) {
        if (D[i] == inf) {
            std::cout << "inf: " << 1 << "->" << i + 1 << '\n';
            continue;
        }
        std::cout << D[i] << ": ";
        std::vector<int> path;
        for (int j = i; j != -1; j = P[j]) {
            path.push_back(j);
        }
        for (int j = path.size() - 1; j >= 0; j--) {
            std::cout << path[j] + 1 << (j != 0 ? "->" : "\n");
        }
    }

    return 0;
}
