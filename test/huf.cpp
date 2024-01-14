#include <bits/stdc++.h>

struct node {
    int v;
    using ptr = node*;
    ptr l, r;
    node(int v, ptr l, ptr r) : v(v), l(l), r(r) {}
};
using ptr = node::ptr;

struct status {
    ptr p;
    status(ptr p) : p(p) {}
    friend bool operator<(status lhs, status rhs) {
        return lhs.p->v > rhs.p->v;
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::map<ptr, int> id;
    std::vector<ptr> buff;

    std::priority_queue<status> q;
    for (int i = 0; i < n; i++) {
        auto p = new node(a[i], nullptr, nullptr);

        buff.push_back(p);
        id[p] = buff.size() - 1;

        q.push(status(p));
    }

    while (q.size() > 1) {
        auto l = q.top();
        q.pop();
        auto r = q.top();
        q.pop();
        
        auto p = new node(l.p->v + r.p->v, l.p, r.p);
        buff.push_back(p);
        // std::cerr << p->v << "\n";
        id[p] = buff.size();

        q.push(status(p));
    }

    std::vector<std::string> ans(n);

    auto dfs = [&](auto &&dfs, ptr p, std::string s) -> void {
        if (!p) return;

        if (id[p] < n) {
            ans[id[p]] = s;
        }

        dfs(dfs, p->l, s + "0");
        dfs(dfs, p->r, s + "1");
    };

    dfs(dfs, q.top().p, "");
    for (int i = 0; i < n; i++) {
        delete buff[i];
    }

    for (int i = 0; i < n; i++) {
        std::cout << char('a' + i) << " " << ans[i] << "\n";
    }

    return 0;
}