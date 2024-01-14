/**
 * @author: XiaFan
 * @date: 2023-02-14 10:43
 **/
#include <bits/stdc++.h>
using i64 = long long;

const double inf = 1e9;

int n;
double a[100][100];

double ansd = inf;
std::vector<int> ans;

void print(const std::vector<int> &v) {
    for (int i = 0; i < (int)v.size(); ++i) {
        std::cout << v[i] + 1;
        if (i < (int)v.size() - 1) {
            std::cout << "->";
        }
    }
    std::cout << "\n";
}

struct node {
    std::vector<int> v;
    double d;
    bool operator<(const node &rhs) const {
        return d > rhs.d;
    }
};

void tsp() {
    int cnt = 0;
    std::priority_queue<node> q;
    q.push({{0}, 0});
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        auto v = cur.v;
        auto d = cur.d;
        
        cnt++;
        if (cnt <= 20) {
            print(v);
        }
        if (d >= ansd) {
            continue;
        }
        if (int(v.size()) == n) {
            d += a[v.back()][0];
            if (ansd > d) {
                ansd = d;
                ans = v;
            }
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (std::find(v.begin(), v.end(), i) == v.end()) {
                d += a[v.back()][i];
                v.push_back(i);
                if (d < ansd) {
                    q.push({v, d});
                }
                v.pop_back();
                d -= a[v.back()][i];
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
            if (a[i][j] == 0) {
                a[i][j] = inf;
            }
        }
    }

    tsp();
    // std::cout << std::fixed;
    std::stringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << ansd;
    std::string s;
    ss >> s;
    while (s.back() == '0') {
        s.pop_back();
    }
    if (s.back() == '.') {
        s.pop_back();
    }
    std::cout << s << ": ";
    print(ans);

    return 0;
}

