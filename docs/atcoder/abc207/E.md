# AtCoder Beginner Contest 207 E - Mod i
```
長さNの数列Aが与えられます。Aをいくつかの連続した空でない部分列B1,B2,…,Bkに切り分ける方法であって、以下の条件を満たすものの個数を求めてください。
・全てのi(1≤i≤k) について、Biに含まれる要素の総和がiで割り切れる。
答えは非常に大きくなることがあるので、(10^9+7) で割ったあまりを出力してください。
```
```
・N≤3000
・1≤Ai≤10^15
・入力は全て整数
```

`fn(どこまで見た,Bの長さi,和modi):=パターン数`だと空間計算量がO(N^3)でアウト。
`fn(どこまで見た,Bの長さi):=パターン数`にして、次に和がiで割り切れるインデックスを事前計算する方向で考えたい。
累積和を思い出すとBxからByまでの和がiで割り切れるなら`(0からBxまでの和)-(0からByまでの和)=0`になる。
和modiが直前に出現した位置を覚えておいてO(1)で遷移できれば良いはず。`N≤3000`なので3000*3000くらい？
絶対に半開区間か何かで間違うやつ。

全然合わない。何。解説を見て配るDPを貰うDPに変えたら通った。何故。

```
dp[i][j] = (dp[g[j][i]][j] + dp[g[j][i]][j - 1]) % mod;
```

```
(dp[g[j][i]][j + 1] += dp[i][j]) %= mod;
(dp[g[j][i]][j] += dp[i][j]) %= mod;
```

しかしこれTLEギリギリだなあ。1.7msec。

```
const int k = g[j][i];
dp[k][j] += dp[i][j];
if (j) dp[k][j] += dp[i][j - 1];
```
これなら合いそう。前処理で作っているテーブルと添字の意味が一致していないのかな。分からなかった。
しかしTLEする。困った。前処理でmapを使っている部分を静的配列に変えて・・・。AC。

## Code
main.cpp
{% raw %}
```cpp
// atcoder/abc207/E/main.cpp
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

  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;

    const int N = 3000 + 3;

    static int g[N][N];
    fill(&g[0][0], &g[N - 1][N - 1] + 1, -1);
    for (int i = 1; i <= n; ++i) {
      static int prev[N];
      fill(prev, prev + N, -1);
      prev[0] = 0;
      int sum = 0;
      for (int j = 0; j < a.size(); ++j) {
        (sum += a[j] % i) %= i;
        if (prev[sum] != -1) g[i][prev[sum]] = j + 1;
        prev[sum] = j + 1;
      }
    }

    static lli dp[N][N];
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, 0);
    dp[0][0] = 1;

    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j <= a.size(); ++j) {
        const int k = g[j][i];
        if (k != -1) {
          (dp[k][j] += dp[i][j]) %= mod;
          if (j) (dp[k][j] += dp[i][j - 1]) %= mod;
        }
      }
    }

    lli x = 0;
    for (int i = 0; i < N; ++i) {
      (x += dp[n][i]) %= mod;
    }
    cout << x << endl;
  }


  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/abc207/E)
