# [AtCoder Beginner Contest 149 F - Surrounded Nodes](https://atcoder.jp/contests/abc149/tasks/abc149_f)
## "2021-05-08 18-52-19"
N頂点の木が与えられる。等確率で白か黒に頂点を塗る。
黒に塗られるもしくは黒に塗られた頂点を子孫に持つような直接の子が複数あって、自身が白に塗られているような頂点の個数の期待値を計算せよ。
※白に塗られてかつ黒へのパスが複数ある、とか言い換えられる？

各頂点毎に条件を満たす確率を求めた後に全て足し合わせたら答えにならないのかな。
ある頂点に注目したとして、その子それぞれを根とした部分技に黒が含まれる確率が分かれば計算できる？

でもそれが複数ってどういう感じだろう。 `1.0-黒が１つもない確率-黒が１つしかない確率` かな。rerootingってやつ？
しかし有理数で出力する系の問題って何だか苦手意識がある。

## "2021-05-09 16-58-20"
木のサイズがnなら、全て白の確率は `1/2^(n-1)` で、
１つだけ黒の確率は子それぞれの部分木のサイズをxiとして `Σ(1/2^(n-1-xi))*(1-1/2^xi)` かな。

うーわ、全然サンプル合わない。xiってnで良いじゃないの。

あー、普通に実装を間違っていた。提出したもののサンプル以外ほぼWAなんだけど何なの。

## "2021-05-15 14-52-08"
間が空いてしまったけれど見直し。rerootingは慣れてないんだよなー。
うーん。よく分からないけどAC。

## Code
main.cpp
{% raw %}
```cpp
// atcoder/abc149/F/main.cpp
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

namespace math {
  lli extgcd(lli a, lli b, lli& x, lli& y)
  {
    lli g = a;
    x = 1;
    y = 0;
    if (b != 0) {
      g = extgcd(b, a % b, y, x);
      y -= (a / b) * x;
    }
    return g;
  }

  lli mod_inverse(lli a, lli m)
  {
    lli x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
  }
  // nHm=n+m-1Cm

  lli mod_pow(lli n, lli p)
  {
    if (p == 0) return 1;
    if (p == 1) return n;
    lli m = mod_pow(n, p / 2);
    m *= m;
    m %= mod;
    if (p % 2) m = (m * n) % mod;
    return m;
  }
}

const int N = 2 * 1e5 + 3;
vec<int> g[N];
int memo[N];
int parent[N];

int rec(int curr, int prev)
{
  parent[curr] = prev;
  memo[curr] = 1;
  each (next, g[curr]) {
    if (next == prev) continue;
    memo[curr] += rec(next, curr);
  }
  return memo[curr];
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    fill(g, g + N, vec<int>());
    fill(memo, memo + N, -1);
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    rec(0, -1);
    lli sum = 0;
    const lli white = math::mod_inverse(math::mod_pow(2, n - 1), mod);
    for (int i = 0; i < n; ++i) {
      lli one_black = 0;
      each (j, g[i]) {
        lli x = (j == parent[i] ? n - memo[i] : memo[j]);
        lli a = math::mod_inverse(math::mod_pow(2, n - 1 - x), mod);
        lli b = math::mod_inverse(math::mod_pow(2, x), mod);
        b = (1 - b + mod) % mod;
        one_black += (a * b) % mod;
        one_black %= mod;
      }
      (sum += (1 - white - one_black + mod + mod) % mod) %= mod;
    }
    cout << (sum * math::mod_inverse(2, mod)) % mod << endl;
  }

  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/abc149/F)
