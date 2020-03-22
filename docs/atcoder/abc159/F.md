# ABC159F Knapsack for All Segments

```
dp[iまで見た][合計がj][右端を決めていない or 右端を決めた or 両端を決めた] := パターン数
```

大きな数字を文字列として取って、先頭の文字から見ていくような典型DPに似ているように思える。<br />
状態遷移は複雑だけれど本番で思い付かなかったのはとても悔しい。<br />

## Codes
main.cpp
{% raw %}
```cpp
// atcoder/abc159/F/main.cpp
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

int main(int argc, char *argv[])
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  int n, s;
  while (cin >> n >> s) {
    vec<lli> a(n);
    cin >> a;

    const int N = 3000 + 5;
    static lli dp[N][N][3];
    fill(&dp[0][0][0], &dp[N - 1][N - 1][3 - 1] + 1, 0);
    dp[0][0][0] = 1;

    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < N; ++j) {
        if (j + a[i] <= s) {
          (dp[i + 1][j + a[i]][1] += dp[i][j][0]) %= mod;
          (dp[i + 1][j + a[i]][1] += dp[i][j][1]) %= mod;
          (dp[i + 1][j + a[i]][2] += dp[i][j][0]) %= mod;
          (dp[i + 1][j + a[i]][2] += dp[i][j][1]) %= mod;
        }
        (dp[i + 1][j][0] += dp[i][j][0]) %= mod;
        (dp[i + 1][j][1] += dp[i][j][0]) %= mod;
        (dp[i + 1][j][1] += dp[i][j][1]) %= mod;
        (dp[i + 1][j][2] += dp[i][j][0]) %= mod;
        (dp[i + 1][j][2] += dp[i][j][1]) %= mod;
        (dp[i + 1][j][2] += dp[i][j][2]) %= mod;
      }
    }

    cout << dp[a.size()][s][2] << endl;
  }

  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/abc159/F)
