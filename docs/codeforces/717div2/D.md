# [Codeforces Round #717 (Div. 2) D. Cut](https://codeforces.com/contest/1516/problem/D)
## "2021-04-29 18-40-04"
長さn<=1e5の数列と、q<=1e5個のクエリが与えられる。
クエリは数列の範囲をしていするもので、LCMが積と一致するように範囲を部分列に分割すると最小でいくつの部分列を構築できるか答えよ。

本番ではこの１つ前の問題に時間を使ってしまって解けなかった覚えがある。尺取り法っぽさを感じる。
でもクエリ毎に尺取りしていても間に合わないから事前に何か構築するんだろうか。

同じ素因数を持たないようにすれば良いのかな。GCDが1であり続けされば良いということ。
`(* 2 3 5 7 11 13 17 23)` が `11741730` だし登場する素数の種類自体は多くなさそう。

全体に対する解答からある範囲を切り出したとして、変更があるのは両端の２つの部分列だけだで、両端をその隣とマージ出来るかを判定すれば良さそう。実装が面倒に思えるけど。
いやでも切り出す部分って線形時間にならない・・・？

## "2021-04-29 22-52-16"
> This is a pretty standard problem solvable with the binary lifting technique.

`binary lifting technique` て何？ダブリングのことかな。

## "2021-04-30 17-24-50"
高輪ゲートウェイ駅のスタバにはスマートラウンジなる作業スペース特化みたいな店舗がある。

```
Now, we have the following greedy algorithm: suppose we start at index l; we'll keep extending our first subrange while the condition (every pair of numbers is coprime) is satisfied. We clearly don't gain anything by stopping when we can extend, since every new element just comes with new restrictions. Once we're unable to extend our subrange, we'll start a new subrange, until we reach index r. Now, for every index l, let's define gol to be the first index that will make the condition break when we add it to the subrange. Then, our algorithm is equivalent to starting with an index cur=l, then replacing cur with gocur until we exceed index r. The number of steps it takes is our answer. We now have 2 subproblems to solve:
```

ダブリングだろうと１つの領域を伸ばしていくとしたらクエリあたり線形時間になるんじゃ・・・？何か解釈が間違っていそう。

`DP[i][j]:=i番目を左端として2^j個目の部分列の右端` かな？

+ `DP[i][0]=i番目から始めて最初にGCDが1でなくなるインデックス`
+ `DP[i][1]=i番目から最適に構築して2個目の部分列の右端`
+ `DP[i][2]=i番目から最適に構築して4個目の部分列の右端`

なるほど？クエリがO(logN)になるのかな。

ダブリングの出題頻度がそれ程だとしても何だか難しく感じるなあ。何だろう。木構造でないから？

ダブリングはライブラリにしてあったけどもう使い方を忘れているレベル。

TLE。この問題2秒じゃないのね。

1e5以下の素数が約1e4個あるっぽい。普通に割っていたら1e9かかる。

## "2021-05-01 12-36-16"
配列の要素に積がLCMにならない次の要素を充分高速に探さないといけない。さてどうしたものか。

素数で割るのではなくて約数を列挙すれば√Nだろうか。

TLEは回避できたけれど500msも使っとるぞ。WAなのは1だけ特別扱いすることを忘れていたから。

AC。

考察が足りなかったなあ。

## Code
main.cpp
{% raw %}
```cpp
// codeforces/717div2/D/main.cpp
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

namespace doubling {
  constexpr int N = 1e5 + 5;
  constexpr int DEPTH = 30;

  int T[N][DEPTH];
  function<int(int)> fn;

  void build(const int size, function<int(int)> fn_)
  {
    fn = fn_;

    for (int i = 0; i < size; ++i) {
      T[i][0] = fn(i);
    }

    for (int i = 1; i < DEPTH; ++i) {
      for (int j = 0; j < size; ++j) {
        T[j][i] = T[T[j][i - 1]][i - 1];
      }
    }

    return ;
  }

  int query(int x, int ntimes)
  {
    for (int i = DEPTH; 0 <= i; --i) {
      if (ntimes & (1 << i)) {
        x = T[x][i];
      }
    }
    return x;
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  const int N = 1e5 + 5;
  static bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < N; ++i) {
    for (int j = 2; i * j < N; ++j) {
      prime[i * j] = false;
    }
  }
  vector<int> p;
  for (int i = 0; i < N; ++i) {
    if (prime[i]) p.push_back(i);
  }

  int n, q;
  while (cin >> n >> q) {
    vec<int> a(n);
    cin >> a;

    map<int, vec<int>> m;
    for (int i = 0; i < a.size(); ++i) {
      m[a[i]].push_back(i);
    }

    static int next[N];
    fill(next, next + N, a.size());
    static int idx[N];
    fill(idx, idx + N, -1);
    for (int i = a.size() - 1; 0 <= i; --i) {
      for (lli j = 2; j * j <= a[i]; ++j) {
        if (a[i] % j == 0) {
          int k = a[i] / j;
          if (idx[k] != -1) setmin(next[i], idx[k]);
          if (idx[j] != -1) setmin(next[i], idx[j]);
          idx[k] = i;
          idx[j] = i;
        }
      }
      if (idx[a[i]] != -1) {
        setmin(next[i], idx[a[i]]);
      }
      if (a[i] != 1) idx[a[i]] = i;
    }
    for (int i = a.size() - 2; 0 <= i; --i) {
      setmin(next[i], next[i + 1]);
    }

    doubling::build(n + 1, [&] (int idx) { return next[idx]; });

    while (q--) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      int z = 0;
      int b = doubling::DEPTH - 1;
      while (0 <= b) {
        int w = doubling::query(x, 1 << b);
        if (w <= y) {
          x = w;
          z += (1 << b);
        }
        --b;
      }
      cout << z + 1 << endl;
    }
  }

  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/codeforces)
+ [repository](https://github.com/Johniel/contests/tree/master/codeforces/717div2/D)
