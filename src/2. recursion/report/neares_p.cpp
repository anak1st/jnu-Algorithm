/**
 * @author: XiaFan
 * @date: 2023-03-02 11:30
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr double eps = 1e-7;
constexpr double inf = 1e18;

int sign(double x) {
    return (x > eps) - (x < -eps);
}
bool equal(double x, double y) {
    return sign(x - y) == 0;
}
// Vector for 2rank & double
struct Vector2d {
    double x, y;
    Vector2d() : x(0), y(0) {}
    Vector2d(double x, double y) : x(x), y(y) {}
    friend bool operator==(const Vector2d &lhs, const Vector2d &rhs) {
        return equal(lhs.x, rhs.x) && equal(lhs.y, rhs.y);
    }
    friend bool operator<(const Vector2d &lhs, const Vector2d &rhs) {
        Vector2d tmp = lhs - rhs;
        return sign(tmp.x) < 0 || (sign(tmp.x) == 0 && sign(tmp.y) < 0);
    }
    friend Vector2d operator+(const Vector2d &lhs, const Vector2d &rhs) {
        return Vector2d(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend Vector2d operator-(const Vector2d &lhs, const Vector2d &rhs) {
        return Vector2d(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    double norm() const {
        return std::hypot(x, y);
    }
    /// @brief rotate by radian around point p
    Vector2d rotate(double radian, Vector2d p = Vector2d(0, 0)) {
        Vector2d tmp = p;
        Vector2d v = *this - p;
        tmp.x += v.x * std::cos(radian) - v.y * std::sin(radian);
        tmp.y += v.x * std::sin(radian) + v.y * std::cos(radian);
        return tmp;
    }
};
double dot(const Vector2d &lhs, const Vector2d &rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}
double cross(const Vector2d &lhs, const Vector2d &rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}
double dis(const Vector2d &lhs, const Vector2d &rhs) {
    return (lhs - rhs).norm();
}
double disx(const Vector2d &lhs, const Vector2d &rhs) {
    return std::abs(lhs.x - rhs.x);
}
double disy(const Vector2d &lhs, const Vector2d &rhs) {
    return std::abs(lhs.y - rhs.y);
}

std::array<double, 5> NearestPoints(std::vector<Vector2d> &p) {
    std::stable_sort(p.begin(), p.end());

    constexpr double inf = 1e18;

    std::function<std::array<double, 5>(int, int)> 
        merge = [&](int l, int r) -> std::array<double, 5> {
        if (r - l == 1) {
            return {inf, inf, inf, inf, inf};
        }
        if (r - l == 2) {
            return {dis(p[l], p[l + 1]), p[l].x, p[l].y, p[l + 1].x, p[l + 1].y};
        }

        int mid = (l + r) / 2;

        double d = inf, x1 = inf, y1 = inf, x2 = inf, y2 = inf;
        auto res1 = merge(l, mid);
        auto res2 = merge(mid, r);

        auto update = [&](double td, Vector2d a, Vector2d b) {
            if (d > td) {
                d = td;
                if (a.x > b.x) {
                    std::swap(a, b);
                }
                x1 = a.x;
                y1 = a.y;
                x2 = b.x;
                y2 = b.y;
            }
        };
        update(res1[0], Vector2d(res1[1], res1[2]), Vector2d(res1[3], res1[4]));
        update(res2[0], Vector2d(res2[1], res2[2]), Vector2d(res2[3], res2[4]));
        
        std::vector<int> tmp;
        for (int i = l; i < r; i++) {
            if (disx(p[mid - 1], p[i]) < d) {
                tmp.push_back(i);
            }
        }
        std::sort(tmp.begin(), tmp.end(), [&](int i, int j) {
            return p[i].y < p[j].y;
        });
        int m = tmp.size();
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m && disy(p[tmp[i]], p[tmp[j]]) < d; j++) {
                update(dis(p[tmp[i]], p[tmp[j]]), p[tmp[i]], p[tmp[j]]);
            }
        }

        return {d, x1, y1, x2, y2};
    };

    return merge(0, p.size());
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<Vector2d> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i].x >> p[i].y;
    }
    std::sort(p.begin(), p.end());

    int m = (n + 1) / 2;
    std::vector<Vector2d> l(p.begin(), p.begin() + m);
    std::vector<Vector2d> r(p.begin() + m, p.end());

    std::cout << std::fixed << std::setprecision(1);
    auto print_ans = [&](std::array<double, 5> ary) {
        std::cout << ary[0] << "\n";
        std::cout << ary[1] << " " << ary[2] << "\n";
        std::cout << ary[3] << " " << ary[4] << "\n";
    };

    print_ans(NearestPoints(l));
    print_ans(NearestPoints(r));
    print_ans(NearestPoints(p));

    return 0;
}
