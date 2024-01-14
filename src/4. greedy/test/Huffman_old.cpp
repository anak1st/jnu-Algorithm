#include <bits/stdc++.h>

int node_cnt = 0;

struct node {
    typedef node* ptr;

    int val;
    ptr left, right;

    node() : left(nullptr), right(nullptr) {
        // std::cerr << ++node_cnt << "\n";
    }

    ~node() {
        // std::cerr << --node_cnt << "\n";
    }
};

struct Huffman {
    typedef typename node::ptr ptr;
    struct status {
        ptr p;

        status() : p(new node) {}

        status(int val) : p(new node) { p->val = val; }

        friend bool operator<(const status lhs, const status rhs) {
            return lhs.p->val > rhs.p->val;
        }

        void merge(status left, status right) {
            p->left = left.p;
            p->right = right.p;
            p->val = left.p->val + right.p->val;
        }
    };

    ptr root;
    std::map<int, int> mp;
    std::vector<std::string> code;
    int max_depth;

    Huffman(const std::vector<int>& v) : root(nullptr), code(v.size()), max_depth(0) {
        for (int i = 0; i < (int)v.size(); i++) {
            mp[v[i]] = i;
        }
        build(v);
    }

    ~Huffman() { clear(); }

    void build(const std::vector<int>& v) {
        int n = v.size();

        std::priority_queue<status> Q;

        for (int i = 0; i < n; i++) {
            status S(v[i]);
            Q.push(S);
        }

        while (Q.size() >= 2) {
            status S1 = Q.top();
            Q.pop();
            status S2 = Q.top();
            Q.pop();
            status S;
            S.merge(S1, S2);
            Q.push(S);
        }

        root = Q.top().p;

        DFS(root, "");
    }

    void clear() { delete_node(root); }

    void delete_node(ptr N) {
        if (N == nullptr) {
            return;
        }
        delete_node(N->left);
        delete_node(N->right);
        delete N;
    }

    void print_code() {
        for (int i = 0; i < (int)code.size(); i++) {
            std::cout << char('a' + i) << " " << code[i] << "\n";
        }
    }

    void DFS(ptr N, std::string S) {
        if (N->left != nullptr) {
            DFS(N->left, S + '0');
        }
        if (N->right != nullptr) {
            DFS(N->right, S + '1');
        }
        if (N->left == nullptr && N->right == nullptr) {
            code[mp[N->val]] = S;
            max_depth = std::max(max_depth, (int)S.length());
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    Huffman hf(v);
    hf.print_code();

    return 0;
}