/**
 * @author: XiaFan
 * @date: 2023-04-12 11:45
 */
#include <bits/stdc++.h>

using i64 = long long;

std::array<int, 4> fun(std::vector<i64> &a, int l, int r) {
    if (l == r) {
        return {l, l, l, l};
    }
    int m = (l + r) / 2;
    auto res1 = fun(a, l, m);
    auto res2 = fun(a, m + 1, r);

    int minl = res1[0], maxl = res1[1], minlans = res1[2], maxlans = res1[3];
    int minr = res2[0], maxr = res2[1], minrans = res2[2], maxrans = res2[3];

    int minans = minl, maxans = maxr;
    if (maxlans != minlans && a[maxlans] - a[minlans] > a[maxans] - a[minans]) {
        minans = minlans;
        maxans = maxlans;
    }
    if (maxrans != minrans && a[maxrans] - a[minrans] > a[maxans] - a[minans]) {
        minans = minrans;
        maxans = maxrans;
    }

    int min = a[minl] < a[minr] ? minl : minr;
    int max = a[maxl] > a[maxr] ? maxl : maxr;
    return {min, max, minans, maxans};
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x;
    std::vector<i64> a;
    while (std::cin >> x) {
        a.push_back(x);
    }
    int n = a.size();

    std::vector<i64> b(n + 1);
    for (int i = 0; i < n; i++) {
        b[i + 1] = b[i] + a[i];
    }

    auto res = fun(b, 0, b.size() - 1);

    int minans = res[2], maxans = res[3];
    
    std::cout << b[maxans] - b[minans] << "\n";
    std::cout << minans + 1 << "\n" << maxans << std::endl;

    return 0;
}