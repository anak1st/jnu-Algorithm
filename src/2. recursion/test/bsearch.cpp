/**
 * @author: XiaFan
 * @date: 2023-03-08 21:43
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x;
    std::vector<int> a;
    while (std::cin >> x) {
        a.push_back(x);
    }
    a.pop_back();

    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        for (int i = l; i <= r; i++) {
            std::cout << a[i] << " \n"[i == r];
        }
        if (a[mid] == x) {
            std::cout << mid + 1 << "\n";
            return 0;
        }

        if (a[l] > x || a[r] < x) {
            break;
        }
        
        if (a[mid] > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    std::cout << 0 << "\n";

    return 0;
}
