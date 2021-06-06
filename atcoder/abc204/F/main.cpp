// atcoder/abc204/F/main.cpp
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
constexpr lli mod = 998244353;

const int N = (1 << 6) + 5;
struct M {
  lli val[N][N];
  M () {
    fill(&val[0][0], &val[N - 1][N - 1] + 1, 0);
  }
};
M E;
M operator * (M a, M b)
{
  M c;
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        (c.val[i][j] += (a.val[i][k] * b.val[k][j]) % mod) %= mod;
      }
    }
  }
  return c;
}

M fn(M m, lli p)
{
  if (p == 0) return E;
  if (p == 1) return m;
  M a = fn(m, p / 2);
  a = a * a;
  if (p % 2) a = a * m;
  return a;
}

void show(M m, int n = N)
{
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << m.val[i][j] << ' ';
    }
    cout << endl;
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  for (int i = 0; i < N; ++i) {
    E.val[i][i] = 1;
  }

  lli h, w;
  while (cin >> h >> w) {
    M m;

    char g[6][2];
    for (int bit = 0; bit < (1 << (h + h)); ++bit) {
      fill(&g[0][0], &g[6 - 1][2 - 1] + 1, '.');
      int b = bit;
      bool f = true;
      char c = 'a';
      for (int i = 0; i < h; ++i) {
        // cout << make_pair(i, b%4) << endl;
        if (b % 4 == 0) { // 縦
          if (g[i][0] != '.') f = false;
          unless (i + 1 < h) f = false;
          else g[i][0] = g[i + 1][0] = c++;
        }
        if (b % 4 == 1) { // 横
          if (g[i][0] == '.') g[i][0] = g[i][1] = c++;
          else f = false;
        }
        if (b % 4 == 2) { // 置かない
          // if (g[i][0] != '.') f = false;
        }
        if (b % 4 == 3) { // 1x1
          if (g[i][0] != '.') f = false;
          else g[i][0] = c++;
        }
        b /= 4;
      }
      // cout << bit << ' ' << f << endl;
      // for (int i = 0; i < h; ++i) cout << g[i][0] << g[i][1] << endl; cout << endl;
      if (f) {
        // for (int i = 0; i < h; ++i) cout << g[i][0] << g[i][1] << endl; cout << endl;
        int a, b;
        a = b = 0;
        for (int i = 0; i < h; ++i) {
          if (g[i][0] != '.') a += (1 << i);
          if (g[i][1] != '.') b += (1 << i);
        }
        int c = a ^ ((1 << h) - 1);
        ++m.val[c][b];
        // cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>. " << bit << ' ' << make_pair(c, b) << endl; for (int i = 0; i < h; ++i) cout << g[i][0] << g[i][1] << endl;
      }
    }
    // ++m.val[(1 << h) - 1][0];
    // m.val[0][0] = 0;

    // cout << "BEFORE" << endl; show(m, 1 << h);
    // m = fn(m, w);
    m = fn(m, w);
    // cout << "AFTER" << endl; show(m, 1 << h);
    // cout << m.val[0][(1 << h) - 1] << endl;
    // cout << m.val[(1 << h) - 1][(1 << h) - 1] << endl;
    cout << m.val[0][0] << endl;
    // break;
  }

  return 0;
}
