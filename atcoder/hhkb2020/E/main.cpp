// atcoder/hhkb2020/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  const int H = 2000 + 5;
  const int W = 2000 + 5;
  const int N = H * W;
  static lli two[N];
  two[0] = 1;
  for (int i = 1; i < N; ++i) {
    two[i] = (two[i - 1] * 2) % mod;
  }

  int h, w;
  while (cin >> h >> w) {
    int dot = 0;
    static char g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
        dot += (g[i][j] == '.');
      }
    }

    static int l[H][W];
    static int r[H][W];
    static int d[H][W];
    static int u[H][W];
    fill(&l[0][0], &l[H - 1][W - 1] + 1, 0);
    fill(&r[0][0], &r[H - 1][W - 1] + 1, 0);
    fill(&d[0][0], &d[H - 1][W - 1] + 1, 0);
    fill(&u[0][0], &u[H - 1][W - 1] + 1, 0);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        l[i][j] = r[i][j] = u[i][j] = d[i][j] = (g[i][j] == '.');
      }
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 1; j < w; ++j) {
        if (l[i][j]) l[i][j] += l[i][j - 1];
      }
      for (int j = w - 2; 0 <= j; --j) {
        if (r[i][j]) r[i][j] += r[i][j + 1];
      }
    }

    for (int j = 0; j < w; ++j) {
      for (int i = 1; i < h; ++i) {
        if (d[i][j]) d[i][j] += d[i - 1][j];
      }
      for (int i = h - 2; 0 <= i; --i) {
        if (u[i][j]) u[i][j] += u[i + 1][j];
      }
    }

    lli x = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '.') {
          int z = l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3;
          x += (two[dot - z] * (two[z] - 1 + mod)) % mod;
          x %= mod;
        }
      }
    }
    cout << x << endl;
  }

  return 0;
}
