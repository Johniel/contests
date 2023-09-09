// github.com/Johniel/contests
// atcoder/abc319/C/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

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

int main(int argc, char *argv[])
{
  vec<vec<int>> g(3, vec<int>(3));
  vec<vec<int>> tmp(3, vec<int>(3));
  while (cin >> g) {
    const int h = 3;
    const int w = 3;
    vec<pair<int, int>> v;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        v.push_back(make_pair(i, j));
      }
    }
    double x = 0;
    double y = 0;
    sort(v.begin(), v.end());
    tmp = g;
    do {
      bool vis[h][w];
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          vis[i][j] = false;
        }
      }
      bool f = false;
      g = vec<vec<int>>(3, vec<int>(3, -1));
      each (p, v) {
        map<int, int> a1;
        if (vis[p.first][0] + vis[p.first][1] + vis[p.first][2] == 2) {
          ++a1[g[p.first][0]];
          ++a1[g[p.first][1]];
          ++a1[g[p.first][2]];
        }
        map<int, int> b1;
        if (vis[0][p.second] + vis[1][p.second] + vis[2][p.second] == 2) {
          ++b1[g[0][p.second]];
          ++b1[g[1][p.second]];
          ++b1[g[2][p.second]];
        }
        map<int, int> c1;
        if (vis[0][0] + vis[1][1] + vis[2][2] == 2) {
          ++c1[g[0][0]];
          ++c1[g[1][1]];
          ++c1[g[2][2]];
        }
        map<int, int> d1;
        if (vis[2][0] + vis[1][1] + vis[0][2] == 2) {
          ++d1[g[2][0]];
          ++d1[g[1][1]];
          ++d1[g[0][2]];
        }
        a1.erase(-1);
        b1.erase(-1);
        c1.erase(-1);
        d1.erase(-1);

        vis[p.first][p.second] = true;
        g[p.first][p.second] = tmp[p.first][p.second];

        if (vis[p.first][0] && vis[p.first][1] && vis[p.first][2] && a1.size() == 1) f = true;
        if (vis[0][p.second] && vis[1][p.second] && vis[2][p.second] && b1.size() == 1) f = true;
        if (vis[1][1] && vis[0][0] && vis[2][2] && c1.size() == 1) f = true;
        if (vis[2][0] && vis[1][1] && vis[0][2] && d1.size() == 1) f = true;
        if (f) break;
      }
      ++x;
      unless (f) ++y;
    } while (next_permutation(v.begin(), v.end()));
    cout << y/x << endl;
  }

  return 0;
}
