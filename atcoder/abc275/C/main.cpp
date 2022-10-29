// github.com/Johniel/contests
// atcoder/abc275/C/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

pair<int, int> rot90(int x, int y)
{
  // int a = x * cos(th) - y * sin(th);
  // int b = x * sin(th) + y * cos(th);
  int a = x * 0 - y * 1;
  int b = x * 1 + y * 0;
  return make_pair(a, b);
}


int main(int argc, char *argv[])
{
  char g[10][10];
  while (true) {
    bool f = true;
    const int H = 9;
    const int W = 9;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        f = f && (cin >> g[i][j]);
      }
    }
    unless (f) break ;

    vec<pair<int, int>> v;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        v.push_back(rot90(i, j));
      }
    }

    auto fn = [&] () {};

    set<vec<pair<int, int>>> vis;
    for (int i1 = 0; i1 < H; ++i1) {
      for (int j1 = 0; j1 < W; ++j1) {
        for (int i2 = 0; i2 < H; ++i2) {
          for (int j2 = 0; j2 < W; ++j2) {
            if (i1 == i2 && j1 == j2) continue;
            unless (g[i1][j1] == '#' && g[i2][j2] == '#') continue;
            int di1 = i2 - i1;
            int dj1 = j2 - j1;

            auto p1 = rot90(di1, dj1);
            int i3 = i2 + p1.first;
            int j3 = j2 + p1.second;
            unless (0 <= i3 && i3 < H) continue;
            unless (0 <= j3 && j3 < W) continue;
            unless (g[i3][j3] == '#') continue;

            int di2 = i3 - i2;
            int dj2 = j3 - j2;
            auto p2 = rot90(di2, dj2);
            int i4 = i3 + p2.first;
            int j4 = j3 + p2.second;
            unless (0 <= i4 && i4 < H) continue;
            unless (0 <= j4 && j4 < W) continue;
            unless (g[i4][j4] == '#') continue;

            vec<pair<int, int>> v;
            v.push_back(make_pair(i1, j1));
            v.push_back(make_pair(i2, j2));
            v.push_back(make_pair(i3, j3));
            v.push_back(make_pair(i4, j4));
            sort(v.begin(), v.end());
            vis.insert(v);
          }
        }
      }
    }
    cout << vis.size() << endl;
  }

  return 0;
}
