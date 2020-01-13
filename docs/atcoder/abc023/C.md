# ABC023 C

R*Cのグリッド上にN個の飴が落ちている。マスを1つ選び、同じ行もしくは同じ列にある飴を全て得る。<br />
ちょうどK個の飴を得られるマスの選び方は何種類あるか答えろ。

R,C,K,N<=1e5

## 考えたこと
R*C個のマス全てを検証するのは確実に無理。少なくともO(R*C) になる。

座標圧縮すれば考慮するマスが減るかとも思ったが、RとC、Nの最大値は同じなので充分に分散していたら意味がない。

2次元累積和で取られない個数を数え上げる、というのも結局はO(R*C)になる。

そもそも選ぶマスを決める事が不可能。

行だけ選ぶ or 列だけ選ぶ、というのはどうか？行を決めると、あと何個を拾うべきか分かる。

拾える個数毎に列を数えておいて計算できるのでは？しかし、行と列で独立に情報を持っておくと選択したマスに飴がある場合にどうする？　

何もしなければ重複して数えて1つズレてしまう。どうしよう。思い浮かばない。

飴のマスをsource、マスの全てをsinkにしてkの流量を流せるか試す、というのは頂点が多すぎてダメそう。

※ここで解説を途中まで読む

やはり事前に行と列とで何個の飴を取れるか事前に数えておくらしい。で、やはり選択したマスに飴がある場合が問題。

飴のあるマスでk個を獲得できるマスの数自体はO(N)で数えられる。引き算する？

重複を考えずに行と列の選び方でk個にパターン数を数えて、その後、飴のある位置だけでみてk個になるものを引く。

意図に反してマイナスの数が出てくる。絶対値を見れば期待通りだけど計算を間違った？

```cpp
    int cnt = 0;
    for (int i = 0; i <= n; ++i) {
      cnt += rr[i] * cc[k - i];
    }
    each (i, v) {
      cnt -= cc[k - R[i.first]];
      cnt -= rr[k - C[i.second]];
    }
    cout << cnt << endl;
```

間違ってた。rr[i]はi個の飴を取得できるような行の数、Rはその行での飴の個数。cc,Cは列。vは飴の位置。

```cpp
    int cnt = 0;
    for (int i = 0; i <= k; ++i) {
      cnt += rr[i] * cc[k - i];
    }
    each (i, v) {
      cnt -= (R[i.first] + C[i.second] == k);
    }
    cout << cnt << endl;
```

こう？全然答えが違う。少し落ち着こう。

> 足してk個になる行と列の組み合わせ - （重複ありで考えて）k個を獲得できる飴のあるマスの個数 + （重複ありで考えて）k+1個を獲得できる飴のあるマスの個数

こうか？しかしダメ。サンプルが合わない。

```cpp
    int cnt = 0;
    for (int i = 0; i <= k; ++i) {
      cnt += rr[i] * cc[k - i];
    }
    each (i, v) {
      cnt -= (R[i.first] + C[i.second] == k);
      cnt += (R[i.first] + C[i.second] == k + 1);
    }
    cout << cnt << endl;
```

rrの作り方を間違えていた。submit。WA。32bitだとダメじゃん。64bitに変えてsubmit。AC。

足し引きして都合を合わせる問題、すんなり出てこない事がある。やっていることは簡単なのに。

## Codes
main.cpp
{% raw %}
```cpp
// atcoder/abc023/C/main.cpp
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

template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "("; each (i, s) os << i << ","; os << ")"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "("; each (i, m) os << i << ","; os << ")"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int r, c, k, n;
  while (cin >> r >> c >> k >> n) {
    vector<pair<int, int>> v(n);
    cin >> v;

    map<int, lli> R, C;
    each (i, v) {
      ++R[i.first];
      ++C[i.second];
    }
    map<int, lli> rr, cc;
    each (i, R) ++rr[i.second];
    each (i, C) ++cc[i.second];
    rr[0] = r - R.size();
    cc[0] = c - C.size();

    lli cnt = 0;
    for (int i = 0; i <= k; ++i) {
      cnt += rr[i] * cc[k - i];
    }
    each (i, v) {
      cnt -= (R[i.first] + C[i.second] == k);
      cnt += (R[i.first] + C[i.second] == k + 1);
    }
    cout << cnt << endl;
  }

  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/abc023/C)
