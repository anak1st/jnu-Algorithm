#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    std::vector<std::vector<int>> b(n, std::vector<int>(m, inf));
    std::vector<std::vector<int>> c(n, std::vector<int>(m));

    b[0][0] = 0;
    c[0][0] = 1;

    auto update = [&](int i, int j, int x, int y) -> void {
        if (x < 0 || y < 0) return;
        if (b[i][j] > b[x][y]) {
            b[i][j] = b[x][y];
            c[i][j] = c[x][y];
        } else if (b[i][j] == b[x][y]) {
            c[i][j] += c[x][y];
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // std::cerr << k << " " << i << " " << j << "\n";

            update(i, j, i - 1, j);
            update(i, j, i, j - 1);
            
            b[i][j] += a[i][j];
        }
    }

    std::cout << b[n - 1][m - 1] << "\n";
    std::cout << c[n - 1][m - 1] << "\n";

    return 0;
}



