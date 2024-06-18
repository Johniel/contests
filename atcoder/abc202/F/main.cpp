// github.com/Johniel/contests
// atcoder/abc202/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

using point = complex<lli>;

constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

point normal(point v)
{
  return v * point(0, -1);
}

lli dot(point a, point b)
{
  return (a.real() * b.real() + a.imag() * b.imag());
}

lli cross(point a, point b)
{
  return (a.real() * b.imag() - a.imag() * b.real());
}

namespace CCW {
  enum { RIGHT = 1, LEFT = -1, FRONT = -2, BACK = +2, OTHER = 0 };
};
int ccw(point a, point b, point c)
{
  b -= a;
  c -= a;
  if (cross(b, c) < 0)return CCW::RIGHT;
  if (cross(b, c) > 0)return CCW::LEFT;
  if (dot(b, c) < 0)return CCW::BACK;
  if (norm(b) < norm(c))return CCW::FRONT;
  return CCW::OTHER;
}

lli area(point a, point b, point c) {
  return abs(cross(b - a, c - a)); // / 2.0;
}

namespace std {
  bool operator < (const point& a, const point& b) {
    if (a.real() != b.real()) return a.real() < b.real();
    return a.imag() < b.imag();
  }
};

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<pair<int, int>> v(n);
    cin >> v;
    sort(v.begin(), v.end());

    vec<point> ps;
    each (i, v) ps.push_back(point(i.first, i.second));

    map<point, int> idx;
    for (int i = 0; i < ps.size(); ++i) {
      idx[ps[i]] = i;
    }

    const int N = 80 + 2;
    static lli inside[N][N][N];
    fill(&inside[0][0][0], &inside[N - 1][N - 1][N - 1] + 1, 0);
    for (int i = 0; i < ps.size(); ++i) {
      for (int j = 0; j < ps.size(); ++j) {
        for (int k = 0; k < ps.size(); ++k) {
          if (i == j || j == k || k == i) continue;
          for (int x = 0; x < ps.size(); ++x) {
            int a = ccw(ps[i], ps[j], ps[x]);
            int b = ccw(ps[j], ps[k], ps[x]);
            int c = ccw(ps[k], ps[i], ps[x]);
            if (a == b && b == c) ++inside[i][j][k];
            // if (a == CCW::OTHER) ++inside[i][j][k];
            // if (b == CCW::OTHER) ++inside[i][j][k];
            // if (c == CCW::OTHER) ++inside[i][j][k];
          }
        }
      }
    }
    lli p2[N];
    p2[0] = 1;
    for (int i = 1; i < N; ++i) {
      p2[i] = p2[i - 1] * 2 % mod;
    }
    lli w[N][N][N];
    for (int i = 0; i < ps.size(); ++i) {
      for (int j = 0; j < ps.size(); ++j) {
        for (int k = 0; k < ps.size(); ++k) {
          w[i][j][k] = p2[inside[i][j][k]];
        }
      }
    }

    lli z = 0;
    for (int i = 0; i < ps.size(); ++i) {
      for (int j = i + 1; j < ps.size(); ++j) {
        vec<point> upper;
        vec<point> lower;
        upper.push_back(ps[i]);
        lower.push_back(ps[i]);
        for (int k = i + 1; k < j; ++k) {
          if (ccw(ps[i], ps[j], ps[k]) == CCW::LEFT) upper.push_back(ps[k]);
          if (ccw(ps[i], ps[j], ps[k]) == CCW::RIGHT) lower.push_back(ps[k]);
        }
        upper.push_back(ps[j]);
        lower.push_back(ps[j]);

        auto fn = [&] (lli dp[N][N][2], const vec<point>& v, int dir) {
          fill(&dp[0][0][0], &dp[N - 1][N - 1][2 - 1] + 1, 0);
          for (int i = 1; i < v.size() - 1; ++i) {
            dp[0][i][0] = 1;
          }
          for (int i = 0; i < v.size(); ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
              for (int mod2 = 0; mod2 < 2; ++mod2) {
                unless (dp[i][j][mod2]) continue;
                for (int k = j + 1; k < v.size(); ++k) {
                  if (ccw(v[i], v[j], v[k]) == dir) {
                    lli a = area(v[0], v[j], v[k]);
                    int x = idx[v[0]];
                    int y = idx[v[j]];
                    int z = idx[v[k]];
                    (dp[j][k][(mod2 + a) % 2] += dp[i][j][mod2] * w[x][y][z] % mod) %= mod;
                  }
                }
              }
            }
          }
          return ;
        };
        static lli dp1[N][N][2];
        static lli dp2[N][N][2];
        fn(dp1, upper, CCW::RIGHT);
        fn(dp2, lower, CCW::LEFT);
        lli tmp = z;
        for (int x = 1; x < upper.size(); ++x) {
          for (int y = 1; y < lower.size(); ++y) {
            (z += dp1[x][upper.size() - 1][0] * dp2[y][lower.size() - 1][0] % mod) %= mod;
            (z += dp1[x][upper.size() - 1][1] * dp2[y][lower.size() - 1][1] % mod) %= mod;
          }
        }
        for (int x = 0; x < upper.size(); ++x) {
          (z += dp1[x][upper.size() - 1][0]) %= mod;
        }
        for (int y = 0; y < lower.size(); ++y) {
          (z += dp2[y][lower.size() - 1][0]) %= mod;
        }
      }
    }
    cout << z << endl;
  }
  return 0;
}
