# ABC164: D
本番では分からなくて4億のDPをして1800msで通した。

実は[類題](https://atcoder.jp/contests/abc158/tasks/abc158_e)が出ていた。

この類題の方が出題された回でも恐らく同じ間違いをしているが、先頭から考えると駄目で、後ろから考える。

例えば `12345789` が与えられたとして、

> ((345789 - 005789) / 10^p) % 2019 == 0

となるような位置２つを探せれば良い。で、これは `345789` と `005789` の余りが一致すれば良い。

何故なら 2019 と 10 は互いに素で、引き算した結果の `345000` のように何度10を掛けたとしてもそれは割り切れるかどうかに影響しない。

## Code
main.cpp
{% raw %}
```cpp
// atcoder/abc164/D/main.cpp
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
  while (cin >> s) {
    lli sum = 0;
    const int M = 2019;
    const int N = 2;
    const lli K = 2;
    static int dp[2][M][K];
    fill(&dp[0][0][0], &dp[N - 1][M - 1][K - 1] + 1, 0);
    dp[0][0][false] = 1;
    for (int i = 0; i < s.size(); ++i) {
      int curr = i % 2;
      int next = (curr + 1) % 2;
      for (int j = 0; j < M; ++j) {
        dp[next][j][false] = dp[next][j][true] = 0;
      }
      for (int j = 0; j < M; ++j) {
        {
          dp[next][(j * 10 + s[i] - '0') % M][true] += dp[curr][j][true];
        }
        {
          dp[next][j][false] += dp[curr][j][false];
        }
        {
          dp[next][(j * 10 + s[i] - '0') % M][true] += dp[curr][j][false];
        }
      }
      sum += dp[next][0][true];
    }
    cout << sum << endl;
  }


  return 0;
}
```
{% endraw %}
main2.cpp
{% raw %}
```cpp
// atcoder/abc164/D/main2.cpp
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
  while (cin >> s) {
    map<int, lli> m;
    reverse(s.begin(), s.end());
    int x = 0;
    int w = 1;
    each (c, s) {
      x = (x + (c - '0') * w) % 2019;
      (w *= 10) %= 2019;
      ++m[x];
    }

    lli y = m[0];
    each (i, m) y += i.second * (i.second - 1) / 2;
    cout << y << endl;
  }

  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/abc164/D)
