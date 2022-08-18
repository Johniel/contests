// github.com/Johniel/contests
// codeforces/815div2/C/main.cpp

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
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int h, w;
  while (cin >> h >> w) {
    int g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        char c;
        cin >> c;
        g[i][j] = c - '0';
      }
    }

    int x = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        x += g[i][j];
      }
    }

    int mn = 3;
    for (int i = 0; i + 1 < h; ++i) {
      for (int j = 0; j + 1 < w; ++j) {
        // oo
        // o
        setmin(mn, g[i + 0][j + 0] + g[i + 0][j + 1] + g[i + 1][j + 0]);
        //  o
        // oo
        setmin(mn, g[i + 1][j + 1] + g[i + 0][j + 1] + g[i + 1][j + 0]);
        // o
        // oo
        setmin(mn, g[i + 0][j + 0] + g[i + 1][j + 1] + g[i + 1][j + 0]);
        // oo
        //  o
        setmin(mn, g[i + 0][j + 0] + g[i + 1][j + 1] + g[i + 0][j + 1]);
      }
    }
    if (mn == 0) cout << x << endl;
    if (mn == 1) cout << x << endl;
    if (mn == 2) cout << x - 1 << endl;
    if (mn == 3) cout << x  - 2 << endl;
  }

  return 0;
}
