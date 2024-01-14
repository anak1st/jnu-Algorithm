/**
 * @author: XiaFan
 * @date: 2023-05-05 09:57
 */
#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    std::vector<int> f;

    DSU (int n) : f(n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        f[x] = y;
        return true;
    } 
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::array<int, 3>> a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            std::cin >> x;
            if (x && i < j) {
                a.push_back({x, i, j});
            }
        }
    }

    std::sort(a.begin(), a.end());

    DSU dsu(n);

    for (auto it : a) {
        int w = it[0], u = it[1], v = it[2];
        if (dsu.merge(u, v)) {
            std::cout << u + 1 << " " << v + 1 << " " << w << std::endl;
        }
    }

    return 0;
}