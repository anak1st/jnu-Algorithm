
/**
 * @author: XiaFan
 * @date: 2023-05-05 09:06
 */
#include <bits/stdc++.h>
#include <debug/vector>

using i64 = long long;

constexpr i64 inf = 1e9;
struct edge {
    int a, b;
    i64 c;
    // friend bool operator<(const edge &lhs, const edge &rhs) {
    //     return lhs.c < rhs.c;
    // }
};

const i64 N = 30;
i64 dis[N];
i64 bak[N];
int pos[N];

// return true if there is a negative cycle
bool BellmanFord(int n, std::vector<edge> E) {
    std::fill(dis, dis + N, inf);
    std::fill(pos, pos + N, -1);
    dis[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        std::copy(dis, dis + N, bak);
        for (auto it : E) {
            int a = it.a, b = it.b; i64 c = it.c;
            if (dis[a] == inf) continue;
            if (dis[b] > bak[a] + c) {
                pos[b] = a;
                dis[b] = bak[a] + c;
            }
        }
    }

    for (auto it : E) {
        int a = it.a, b = it.b; i64 c = it.c;
        if (dis[a] == inf) continue;
        if (dis[b] > dis[a] + c) {
            return false;
        }
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<edge> E;

    for (int i = 0; i < m; i++) {
        char cha, chb;
        int c;
        std::cin >> cha >> chb >> c;

        E.push_back({cha - 'a', chb - 'a', c});
    }

    // for (auto [a, b, c] : E) {
    //     std::cerr << a << " " << b << " " << c << "\n";
    // }

    bool ok = BellmanFord(n, E);

    // for (int i = 0; i < N; i++) {
    //     std::cerr << dis[i] << "\n";
    // }

    if (!ok) {
        std::cout << "Negative-weight cycle found in the graph\n";
        return 0;
    }
    for (int i = 1; i < N; i++) {
        if (dis[i] == inf) continue;
        std::cout << dis[i] << ": ";
        std::vector<int> path;
        for (int j = i; j != -1; j = pos[j]) {
            path.push_back(j);
        }
        int len = path.size();
        for (int j = len - 1; j >= 0; j--) {
            std::cout << char('a' + path[j]);
            if (j != 0) {
                std::cout << "->";
            } else {
                std::cout << "\n";
            }
        }
    }

    return 0;
}
