#include <bits/stdc++.h>

using i64 = long long;

std::string mat(int x) {
    return "A" + std::to_string(x);
}
constexpr int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x;
    std::vector<int> v;
    while (std::cin >> x) {
        v.push_back(x);
    }
    int n = v.size() - 1;

    using Status = std::pair<int, std::string>;

    std::vector<std::vector<Status>> dp(n + 1, std::vector<Status>(n + 1, {inf, ""}));

    int cnt = 0;

    std::function<Status(int, int)> solve = [&](int l, int r) -> Status {
        if (l + 1 == r) {
            return {0, mat(r)};
        }

        if (dp[l][r].first != inf) {
            return dp[l][r];
        }

        cnt++;

        for (int m = l + 1; m + 1 <= r; m++) {
            auto res1 = solve(l, m);
            auto a = res1.first;
            auto s1 = res1.second;

            auto res2 = solve(m, r);
            auto b = res2.first;
            auto s2 = res2.second;

            int c = a + b + v[l] * v[m] * v[r];
            if (dp[l][r].first > c) {
                dp[l][r].first = c;
                dp[l][r].second = "(" + s1 + s2 + ")";
            }
        }

        return dp[l][r];
    };

    auto res = solve(0, n);
    auto ans = res.first;
    auto str = res.second;
    std::cout << ans << "\n";
    std::cout << str << "\n";

    // std::cerr << cnt;

    return 0;
}