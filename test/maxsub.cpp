/**
 * @author: XiaFan
 * @date: 2023-06-01 22:08
 */
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> a;
    int x;
    while (std::cin >> x) {
        a.push_back(x);
    }
    int n = a.size();
    std::vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i - 1];
    }
    int l = 1, r = n;
    auto get = [&](int l, int r) {
        return b[r] - b[l - 1];
    };
    
    for (int i = 1, j = 1; i <= n; i++) {
        if (get(j, i) < 0) {
            j = i + 1;
        }
        if (get(j, i) >= get(l, r)) {
            l = j;
            r = i;
        }
    }

    std::cout << get(l, r) << "\n";
    std::cout << l << "\n" << r << "\n";

    return 0;
}