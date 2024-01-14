/**
 * @author: XiaFan
 * @date: 2023-04-05 13:30
 */
#include <bits/stdc++.h>

using i64 = long long;

std::string get() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::string s;
    char c;
    while (ss >> c) {
        s += c;
    }
    return s;
}

std::pair<int, std::string> lcs(std::string s1, std::string s2) {
    int n = s1.size();
    int m = s2.size();
    s1 = " " + s1;
    s2 = " " + s2;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }
    std::string res;
    {
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (s1[i] == s2[j]) {
                res += s1[i];
                i--, j--;
            } else {
                if (dp[i - 1][j] >= dp[i][j - 1]) {
                    i--;
                } else {
                    j--;
                }
            }
        }
    }
    std::reverse(res.begin(), res.end());
    return {dp[n][m], res};
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s1 = get();
    std::string s2 = get();

    auto res = lcs(s1, s2);
    std::cout << res.first << "\n";
    if (res.first > 0) {
        std::cout << res.second;
    } else {
        std::cout << "None";
    }

    return 0;
}
