/**
 * @author: XiaFan
 * @date: 2023-03-08 21:43
 **/
#include <bits/stdc++.h>
using i64 = long long;

template <typename T> i64 merge(std::vector<T> &a, std::vector<T> &b, int l, int r) {
    int m = (l + r) / 2;
    int i = l, j = m + 1, k = l;
    i64 res = 0;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            // res += (j - k);
            b[k++] = a[j++];
        }
    }
    while (i <= m) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    std::copy(b.begin() + l, b.begin() + r + 1, a.begin() + l);
    return res;
}
template <typename T> i64 merge_sort(std::vector<T> &a, std::vector<T> &b, int l, int r) {
    i64 res = 1;
    if (l < r) {
        int m = (l + r) / 2;
        res += merge_sort<T>(a, b, l, m);
        res += merge_sort<T>(a, b, m + 1, r);
        res += merge<T>(a, b, l, r);
    }
    return res;
}
template <typename T> i64 merge_sort(std::vector<T> &a) {
    std::vector<T> b(a);
    return merge_sort<T>(a, b, 0, (int)a.size() - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x;
    std::vector<int> a;
    while (std::cin >> x) {
        a.push_back(x);
    }

    i64 cnt = merge_sort(a);
    std::cout << cnt << std::endl;
    for (auto x : a) {
        std::cout << x << " ";
    }

    return 0;
}
