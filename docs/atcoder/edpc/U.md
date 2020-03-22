# EDPC: U

状態はビットで持つと良い。ウサギのグループ分け毎に得られる得点は列挙しておく。

愚直な実装をすると `O(2^2N)` になるが、最も下位の1を取り除くように計算すると `O(3^N)` になる。
※ bit = (bit - 1) & bit

詳しくは蟻本を読む。


```
// dp[既に割り当てたウサギの集合] := パターン数
// ウサギのグループzで得られる得点をscore[z]とすると、
dp[x | y] = min(dp[x] + score[y])
```

## Code
main.cpp
{% raw %}
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    lli g[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }

    const lli inf = 1LL << 60;
    const int N = (1 << 16) + 1;

    lli cost[N];
    fill(cost, cost + N, 0);
    for (int bit = 0; bit < (1 << n); ++bit) {
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          unless (bit & (1 << i)) continue;
          unless (bit & (1 << j)) continue;
          cost[bit] += g[i][j];
        }
      }
    }

    lli dp[N];
    fill(dp, dp + N, -inf);
    dp[0] = 0;

    // O(3^N), P.144
    for (int bit = 0; bit < (1 << n); ++bit) {
      int sup = bit ^ ((1 << n) - 1);
      int sub = sup;
      do {
        setmax(dp[bit | sub], dp[bit] + cost[sub]);
        sub = (sub - 1) & sup;
      } while (sub != sup);
    }
    cout << dp[(1 << n) - 1] << endl;
  }

  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/edpc/U)
