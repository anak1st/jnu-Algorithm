/**8
 * @author: XiaFan
 * @date: 2023-03-14 22:47
 **/
#include <bits/stdc++.h>

// ===== Quick Sort =====
template <typename T> int quick_sort(std::vector<T> &a, int l, int r) {
    if (l >= r) return 1;
    int i = l, j = l;
    while (j < r) {
        if (a[j] < a[r]) {
            std::swap(a[i], a[j]);
            i++;
        }
        j++;
    }
    std::swap(a[i], a[r]);
    int res = 1;
    res += quick_sort(a, l, i - 1);
    res += quick_sort(a, i + 1, r);
    return res;
}
template <typename T> int quick_sort(std::vector<T> &a) {
    return quick_sort(a, 0, (int)a.size() - 1);
}

int main() {

    int x;
    std::vector<int> a;
    while (std::cin >> x) {
        a.push_back(x);
    }
    std::cout << quick_sort(a) << "\n";
    for (auto x : a) {
        std::cout << x << " ";
    }

    return 0;
}
