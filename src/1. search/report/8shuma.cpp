/**
 * @author: XiaFan
 * @date: 2023-02-14 13:28
 **/
#include <bits/stdc++.h>
using i64 = long long;

typedef std::pair<std::string, int> status;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y;
    std::cin >> x >> y;
    std::vector<int> a(9);
    for (int i = 0; i < 9; ++i) {
        std::cin >> a[i];
    }
    std::vector<bool> vis(9);
    for (int i = 0; i < 9; ++i) {
        if (a[i] != -1)
            vis[a[i]] = true;
    }
    int p = std::find(vis.begin(), vis.end(), false) - vis.begin();
    for (int i = 0; i < 9; ++i) {
        if (a[i] == -1)
            a[i] = p;
    }
    char C = p + '0';
    std::string A;
    for (int i = 0; i < 9; ++i) {
        A += a[i] + '0';
    }
    auto B = A;
    std::sort(B.begin(), B.end());

    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1}; 
    std::set<std::string> st;
    st.insert(A);
    std::queue<status> q;
    q.push({A, 0});
    while (!q.empty()) {
        auto F = q.front();
        std::string s = F.first;
        int step = F.second;
        q.pop();
        if (s == B) {
            std::cout << step << std::endl;
            break;
        }
        int pos = s.find(C);
        int x = pos / 3, y = pos % 3;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
                continue;
            std::swap(s[x * 3 + y], s[nx * 3 + ny]);
            if (!st.count(s)) {
                st.insert(s);
                q.push({s, step + 1});
            }
            std::swap(s[x * 3 + y], s[nx * 3 + ny]);
        }
    }

    return 0;
}
