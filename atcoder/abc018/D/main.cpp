// atcoder/abc018/D/main.cpp
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

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, p, q, r;
  while (cin >> n >> m >> p >> q >> r) {
    const int N = 20;
    int g[N][N];
    fill(&g[0][0], &g[N - 1][N - 1] + 1, 0);
    for (int i = 0; i < r; ++i) {
      int x, y, z;
      cin >> x >> y >> z;
      --x;
      --y;
      g[x][y] = z;
    }

    int mx = 0;
    for (int bit = 0; bit < (1 << n); ++bit) {
      if (__builtin_popcount(bit) != p) continue;
      priority_queue<int> v;
      for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
          if (bit & (1 << j)) {
            sum += g[j][i];
          }
        }
        v.push(sum);
      }
      int sum = 0;
      for (int i = 0; i < q; ++i) {
        sum += v.top();
        v.pop();
      }
      setmax(mx, sum);
    }
    cout << mx << endl;
  }

  return 0;
}
