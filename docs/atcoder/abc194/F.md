# [AtCoder Beginner Contest 194 F - Digits Paradise in Hexadecimal](https://atcoder.jp/contests/abc194/tasks/abc194_f)
## "2021-05-01 18-35-47"
> 1以上N以下の整数のうち、先頭に 0のない十六進表記で書くとちょうどK種類の数字が現れるようなものはいくつあるでしょうか?10^9+7で割ったあまりを出力してください。

+ 1<=N<=(16^2)*1e5
+ 1<=k<=16

どうして解いてないんだっけこの問題。まずは頭から決めていくようなDPが思い浮かぶ。
`DP[X桁目まで決めた][Nより既に小さいか][どの文字を使ったかの2進数表現]:=パターン数`

状態数が1e5\*2^16\*2で遷移数が16通り?2^16が厳しくて無理そう。

一度Nより小さくなったら何種類使ったかは、使った文字数だけで良いのでは？つまり `DP[X桁目まで決めた][Nより既に小さいか][何種類の文字を使ったか]:=パターン数`

今度は状態数が1e5\*16\*2で遷移数が2通り。これが本当なら間に合いそう。

`DP[x][true][y] = DP[x-1][true][y] * c + DP[x-1][true][y-1]*(16-(y-1)) + DP[x-1][false][y-1] * x-1桁目の数-1` みたいない？
`DP[x][false][y]` は、Nを先頭から見ていって登場した文字を数えていけば計算出来るかな。
`DP[x-1][false][y-1] * x-1桁目の数-1` の部分は、それまでに登場した数字を使うかで分岐があるから違いそう。

実装が泥沼化してしまってツラい。落ち着くために貰うDPでなく配るDPで書き直そう。

あー、桁数が違う場合に考慮漏れが。桁数が異なる場合に0を使った扱いをして使った文字数を増やしていた。困った。
`DP[x][true][0]` からの遷移だけ特別扱いかな。

うまく書けない。もう状態数2倍にしよう。`DP[X桁目まで決めた][Nより既に小さいか][0を使えるか(1文字目でないか)][何種類の文字を使ったか]:=パターン数`
まだサンプルが合わない。何。

## "2021-05-05 19-33-55"
全然サンプルが合わない。一旦全て忘れて書き直そう。4次元が厳しい。これを解ける人々は高度場合分け人材なの？
leading 0があるものと扱った方が計算しやすいかな。

猛烈に大変だったけれど場合分けで何とかした。

`DP[X桁目まで決めた][何種類の文字を使ったか]:=パターン数` で解けるの・・・？凄くない。？

## Code
main.cpp
{% raw %}
```cpp
// atcoder/abc194/F/main.cpp
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

  str s;
  int kind;
  while (cin >> s >> kind) {
    const int N = 2 * 1e5 + 5;
    const int M = 18;
    static lli dp[N][2][2][M];
    fill(&dp[0][0][0][0], &dp[N - 1][2 - 1][2 - 1][M - 1] + 1, 0);
    dp[0][false][true][0] = 1;

    map<char, int> m;
    str t = "0123456789ABCDEF";
    for (int i = 0; i < t.size(); ++i) {
      m[t[i]] = i;
    }

    set<char> vis;

    for (int i = 0; i < s.size(); ++i) {
      for (int less = 0; less < 2; ++less) {
        for (int prefix = 0; prefix < 2; ++prefix) {
          for (int k = 0; k <= kind; ++k) {
            const lli curr = dp[i][less][prefix][k];
            if (curr == 0) continue;
            if (less) {
              (dp[i + 1][less][prefix][k] += curr * k) %= mod;
              unless (prefix) {
                (dp[i + 1][less][prefix][k + 1] += curr * (16 - k)) %= mod;
              } else {
                (dp[i + 1][less][true][k] += curr) %= mod;
                (dp[i + 1][less][false][k + 1] += curr * (15 - k)) %= mod;
              }
            } else {
              for (int p = 0; p < m[s[i]]; ++p) {
                if (i == 0 && p == 0) {
                  (dp[i + 1][true][true][0] += curr) %= mod;
                } else {
                  (dp[i + 1][true][false][vis.size() + 1 - vis.count(t[p])] += curr) %= mod;
                }
              }
            }
          }
        }
      }
      const int prev = vis.size();
      vis.insert(s[i]);
      if (i) {
        dp[i + 1][false][false][vis.size()] += dp[i][false][false][prev];
      } else {
        dp[i + 1][false][false][vis.size()] += dp[i][false][true][prev];
      }
    }

    lli x = 0;
    x += dp[s.size()][true][false][kind];
    x += dp[s.size()][false][false][kind];
    cout << x % mod << endl;
  }
  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/abc194/F)
