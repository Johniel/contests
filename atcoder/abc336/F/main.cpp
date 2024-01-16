// github.com/Johniel/contests
// atcoder/abc336/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

namespace grid2d {
  template<typename T>
  void rot90(vec<vec<T>>& g, int base_i, int base_j, int k) {
    vec<vec<T>> tmp(k, vec<T>(k));
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < k; ++j) {
        tmp[i][j] = g[base_i + j][base_j + (k - 1) - i];
      }
    }
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < k; ++j) {
        g[base_i + i][base_j + j] = tmp[i][j];
      }
    }
    return ;
  }

  template<typename T>
  void rot180(vec<vec<T>>& g, int base_i, int base_j, int h, int w) {
    // ABC336F
    set<pair<pair<int, int>, pair<int, int>>> vis;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        pair<int, int> a = make_pair(base_i + i, base_j + j);
        pair<int, int> b = make_pair(base_i + (h - 1) - i, base_j + (w - 1) - j);
        unless (vis.count(make_pair(a, b))) {
          swap(g.at(a.first).at(a.second), g.at(b.first).at(b.second));
          vis.insert(make_pair(a, b));
          vis.insert(make_pair(b, a));
        }
      }
    }
    return ;
  }
};

int main(int argc, char *argv[])
{
  int h, w;
  while (cin >> h >> w) {
    vec<vec<int>> src(h, vec<int>(w));
    cin >> src;
    auto dst = src;
    {
      int k = 0;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          dst[i][j] = ++k;
        }
      }
    }
    auto fn = [&] (const vec<vec<int>>& src) {
      map<vec<vec<int>>, int> c;
      queue<vec<vec<int>>> q;
      c[src] = 0;
      for (q.push(src); q.size(); q.pop()) {
        auto g = q.front();
        const int x = c[g];
        for (int i = 0; i < 2; ++i) {
          for (int j = 0; j < 2; ++j) {
            grid2d::rot180(g, i, j, h - 1, w - 1);
            if (!c.count(g)) {
              c[g] = x + 1;
              if (x + 1 < 10) q.push(g);
            }
            grid2d::rot180(g, i, j, h - 1, w - 1);
          }
        }
      }
      return c;
    };
    map<vec<vec<int>>, int> a = fn(src);
    map<vec<vec<int>>, int> b = fn(dst);
    const int inf = 1 << 27;
    int z = inf;
    each (i, a) {
      if (b.count(i.first)) setmin(z, i.second + b[i.first]);
    }
    if (z == inf) z = -1;
    cout << z << endl;
  }
  return 0;
}
