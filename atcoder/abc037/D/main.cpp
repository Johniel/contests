// atcoder/abc037/D/main.cpp
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

const int N = 1000 + 5;
int g[N][N];

const lli mod = 1e9 + 7;

int h, w;
lli memo[N][N];
lli rec(int i, int j)
{
  lli& ret = memo[i][j];
  if (ret != -1) return ret;

  lli sum = 1;
  int di[] = {0, 0, -1, +1};
  int dj[] = {-1, +1, 0, 0};
  for (int d = 0; d < 4; ++d) {
    int ni = i + di[d];
    int nj = j + dj[d];
    unless (0 <= ni && ni < h) continue;
    unless (0 <= nj && nj < w) continue;
    if (g[i][j] < g[ni][nj]) {
      sum += rec(ni, nj);
      sum %= mod;
    }
  }
  return ret = sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> h >> w) {
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    lli sum = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        sum += rec(i, j);
        sum %= mod;
      }
    }
    cout << sum << endl;
  }

  return 0;
}
