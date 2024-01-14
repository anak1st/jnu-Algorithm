/**
 * @author: XiaFan
 * @date: 2023-03-23 15:44
 **/
#include <bits/stdc++.h>
using i64 = long long;

bool flag = true;

int partition(std::vector<int> &v, int l, int r, int x) {
    int p = std::find(v.begin() + l, v.begin() + r + 1, x) - v.begin();
    assert(l <= p && p <= r);
    std::swap(v[l], v[p]);
    int i = l, j = r;
    while (i < j) {
        while (i < j && v[j] >= x) {
            j--;
        }
        v[i] = v[j];
        while (i < j && v[i] <= x) {
            i++;
        }
        v[j] = v[i];
    }
    v[i] = x;
    return i;
}

int kth(std::vector<int> &v, int l, int r, int k) {
    // std::cerr << "in " << l << " " << r << " " << k << "\n";
    if (r - l + 1 <= 5) {
        std::sort(v.begin() + l, v.begin() + r + 1);
        return v[k];
    }

    int n = r - l + 1;
    for (int i = 0; i < n / 5; i++) {
        std::sort(v.begin() + l + i * 5, v.begin() + l + i * 5 + 5);
        std::swap(v[l + i], v[l + i * 5 + 2]);
    }

    // std::cerr << "debug: ";
    // for (int i = 0; i < n / 5; i++) {
    //     std::cerr << v[l + i] << " \n"[i == n / 5 - 1];
    // }

    int x = v[l];
    if (flag) {
        flag = false;
        x = kth(v, l, l + n / 5 - 1, l + (n / 5 + 1) / 2 - 1);
        std::cout << x << "\n";
    } else {
        x = kth(v, l, l + n / 5 - 1, l + (n / 5 + 1) / 2 - 1);
    }

    int p = partition(v, l, r, x);
    if (p == k) {
        return v[p];
    } else if (p < k) {
        return kth(v, p + 1, r, k);
    } else {
        return kth(v, l, p - 1, k);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> v;
    int x;
    while (std::cin >> x) {
        v.push_back(x);
    }
    int k = v.back();
    v.pop_back();
    int n = v.size();
    std::cout << kth(v, 0, n - 1, k - 1) << "\n";

    // for (int i = 1; i <= n; i++) {
    //     std::cout << kth(v, 0, n - 1, i - 1) << " \n"[i == n];
    // }
    // for (int i = 1; i <= n; i++) {
    //     std::cout << v[i - 1] << " \n"[i == n];
    // }
    
    return 0;
}