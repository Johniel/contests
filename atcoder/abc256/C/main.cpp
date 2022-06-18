// atcoder/abc256/C/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  vec<int> h(3);
  vec<int> w(3);
  while (cin >> h >> w) {
    int g[3][3];
    int z = 0;
    for (int a = 1; a < 30; ++a) {
      for (int b = 1; b < 30; ++b) {
        for (int c = 1; c < 30; ++c) {
          for (int d = 1; d < 30; ++d) {
            g[0][0] = a;
            g[0][1] = b;
            g[1][0] = c;
            g[1][1] = d;

            g[0][2] = h[0] - (g[0][0] + g[0][1]);
            g[1][2] = h[1] - (g[1][0] + g[1][1]);
            g[2][0] = w[0] - (g[0][0] + g[1][0]);
            g[2][1] = w[1] - (g[0][1] + g[1][1]);

            int x = w[2] - (g[0][2] + g[1][2]);
            int y = h[2] - (g[2][0] + g[2][1]);
            g[2][2] = x;

            unless (x == y) continue;

            int mn = 1 << 29;
            for (int i = 0; i < 3; ++i) {
              for (int j = 0; j < 3; ++j) {
                setmin(mn, g[i][j]);
              }
            }
            z += (1 <= mn);
          }
        }
      }
    }
    cout << z << endl;
  }

  return 0;
}
