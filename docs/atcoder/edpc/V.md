# EDPC: V

まず頂点0を根としてパターン数を数える。次にその結果を使いまわしつつ頂点0から再帰して別の頂点の分も数えていく。

全方位木DPと言われているアプローチ。老害には難しい。

## 頂点0を根に黒く塗るパターン数を考える

黒だけを辿って全ての黒に到達可能ということは、一度白に塗ったらそれより下は全て白になるということ。

+ 黒に塗る場合: 子の塗り方の総乗
+ 白に塗る場合: 1通り

なので、

```
f(i) := Π(f(j) + 1) // (i,j)∈E
```

これは `O(N)` で終わる。DFSは `O(V+E)` だが木は `V=E-1` なので線形時間。

## 使い回して別の頂点を考える

頂点0とまったく同じことをしていては `O(N^2)` で間に合わない。

まず、xを根にした場合は分かっていてw-x-y-zというパスが存在したとしたとする。

次にxから遷移してyを根にした場合を考えたい。y→zについてはxを根にしたときに既に数えているので使い回せる。

残りはy→xの塗り方さえ知れれば良いのだが、これはxからyに遷移するときに引数として渡してやる。関数宣言はこんな風↓

```
fn(注目している頂点x,親の頂点y,xを親としてyを塗るパターン数)
```

yを根とした場合のパターン数の計算に必要な値のうち、y→xの分は渡して、残りはxを根にしたときに数えている。

`xを親としてyを塗るパターン数` を毎回計算していては間に合わないが、累積積を使って総乗の計算からx→yの分を取り除けば計算できる。

つまり、v0がv1〜vnを子に持つ場合に、

+ L[i] = v1からi番目の頂点までの塗り方の総乗
+ R[i] = vnからi番目の頂点までの塗り方の総乗

とした場合にj番目の頂点以外の総乗は、 `L[j] * R[j + 1]` で計算できる※半開区間

これは前計算全体でも `O(E)` になる。遷移は `O(V)` なので全体で `O(N)` となる。

## Codes
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

lli mod;
const int N = 1e5 + 5;
vector<int> g[N];

map<pair<int, int>, lli> memo;
lli rec1(int curr, int prev)
{
  const pair<int, int> key = make_pair(prev, curr);
  if (memo.count(key)) return memo[key];
  lli x = 1;
  each (next, g[curr]) {
    if (next == prev) continue;
    (x *= rec1(next, curr) + 1) %= mod;
  }
  return memo[key] = x;
}

void rec2(int curr, int prev, lli p)
{
  memo[make_pair(curr, prev)] = p;

  vector<lli> pref = {1};
  each (next, g[curr]) {
    lli x = pref.empty() ? 1 : pref.back();
    x *= memo[make_pair(curr, next)] + 1;
    pref.push_back(x % mod);
  }
  reverse(g[curr].begin(), g[curr].end());

  vector<lli> suff = {1};
  each (next, g[curr]) {
    lli x = suff.empty() ? 1 : suff.back();
    x *= memo[make_pair(curr, next)] + 1;
    suff.push_back(x % mod);
  }
  reverse(g[curr].begin(), g[curr].end());
  reverse(suff.begin(), suff.end());

  for (int i = 0; i < g[curr].size(); ++i) {
    int next = g[curr][i];
    if (next == prev) continue;
    rec2(next, curr, (pref[i] * suff[i + 1]) % mod);
  }

  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n >> mod) {
    memo.clear();
    fill(g, g + N, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    rec1(0, 0);
    rec2(0, 0, 0);
    for (int i = 0; i < n; ++i) {
      lli x = 1;
      each (j, g[i]) (x *= memo[make_pair(i, j)] + 1) %= mod;
      cout << x << endl;
    }
  }

  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/edpc/V)
