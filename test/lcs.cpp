/**
 * @author: XiaFan
 * @date: 2023-06-01 18:29
 */
#include <bits/stdc++.h>

using i64 = long long;

std::string get() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::string a;
    char c;
    while (ss >> c) {
        a.push_back(c);
    }
    return a;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto a = get();
    auto b = get();
    int n = a.size();
    int m = b.size();
    a = "!" + a;
    b = "?" + b;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::cout << dp[n][m] << "\n";

    if (dp[n][m] == 0) {
        std::cout << "None";
        return 0;
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         std::cerr << dp[i][j] << " \n"[j == m];
    //     }
    // }
    std::string ans;
    for (int i = n, j = m; i >= 1 && j >= 1; ) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        } else {
            ans += a[i];
            i--;
            j--;
        }
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << ans << "\n";

    return 0;
}