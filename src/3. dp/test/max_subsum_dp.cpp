/**
 * @author: XiaFan
 * @date: 2023-04-12 19:38
 */
#include <bits/stdc++.h>
using i64 = long long;

std::pair<int, int> max_subsum(std::vector<i64> &a) {
    int n = a.size();
    std::vector<i64> b(n + 1);
    for (int i = 0; i < n; i++) {
        b[i + 1] = b[i] + a[i];
    }

    int ansmin = 0, ansmax = 1;
    int min = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] - b[min] >= b[ansmax] - b[ansmin]) {
            ansmin = min;
            ansmax = i;
        }
        min = b[i] <= b[min] ? i : min;
    }
    return {ansmin, ansmax};
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x;
    std::vector<i64> a;
    while (std::cin >> x) {
        a.push_back(x);
    }
    
    auto res = max_subsum(a);
    int ansmin = res.first, ansmax = res.second;
    i64 ans = std::accumulate(a.begin() + ansmin, a.begin() + ansmax, 0LL);
    std::cout << ans << "\n";
    std::cout << ansmin + 1 << "\n" << ansmax << std::endl;

    return 0;
}