// atcoder/tdpc/M/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

const int R = 16;
const lli mod = 1e9 + 7;

struct M {
  lli g[R][R];
  M ()
  {
    fill(&g[0][0], &g[R - 1][R - 1] + 1, 0);
  }
};

M operator * (const M & a, const M & b)
{
  M c;
  for (int k = 0; k < R; ++k) {
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < R; ++j) {
        (c.g[i][j] += (a.g[i][k] * b.g[k][j]) % mod) %= mod;
      }
    }
  }
  return c;
}

M fn(M x, lli p)
{
  if (p == 1) return x;
  if (p == 2) return x * x;

  M y = fn(x, p / 2);
  y = y * y;
  return p % 2 ? y * x : y;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int h, r;
  while (cin >> h >> r) {
    static lli g[R][R];
    fill(&g[0][0], &g[R - 1][R - 1] + 1, 0);
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < r; ++j) {
        cin >> g[i][j];
      }
      g[i][i] = 1;
    }

    M m;
    for (int src = 0; src < r; ++src) {
      const int BIT = 1 << R;
      static lli dp[BIT][R];
      fill(&dp[0][0], &dp[BIT - 1][R - 1] + 1, 0);
      dp[1 << src][src] = 1;
      for (int bit = 0; bit < BIT; ++bit) {
        for (int i = 0; i < R; ++i) {
          unless (bit & (1 << i)) continue;
          for (int j = 0; j < R; ++j) {
            if (bit & (1 << j)) continue;
            (dp[bit | (1 << j)][j] += dp[bit][i] * g[i][j]) %= mod;
          }
        }
      }
      for (int bit = 0; bit < BIT; ++bit) {
        for (int i = 0; i < R; ++i) {
          (m.g[src][i] += dp[bit][i]) %= mod;
        }
      }
    }

    m = fn(m, h);
    cout << m.g[0][0] << endl;
  }

  return 0;
}
