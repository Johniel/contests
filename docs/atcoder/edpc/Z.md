# EDPC: Z

[ConvexHullTrick](https://codeforces.com/blog/entry/63823)。蟻本にはdequeの活用方法のあたりに載っている。これはDPなんだろうか。

足場iと足場jで移動する場合のコストは `f(hi)=min{(hi-hj)^2+C+f(hi)}` になる。

変形した `f(hj)=min{hi^2-2*hi*hj-hj^2+C+f(hi)}` という式を見ると、`-2*hi` を傾きにしようにも `hi^2` と `hj^2` が出てくるあたりどう扱って良いのか分からなかった。

が、管理する直線を `f(hj)=-2*hi*hj+hi^2+C+f(hi)` にしてしまえば良い。 `hj` は注目しているタイミングでは定数なので後から加算する。

柔らか頭でないと実装で戸惑う気がした。

## Code
main.cpp
{% raw %}
```cpp
// atcoder/edpc/Z/main.cpp
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

template<typename T>
struct ConvexHullTrick {
  deque<pair<T, T>> q;
  ConvexHullTrick() {}
  void append(T a, T b) // DESC a, aX+b
  {
    if (q.size()) {
      assert(q.back().first >= a);
    }
    q.push_back({a, b});
    while (3 <= q.size() && check()) {
      q[q.size() - 2] = q[q.size() - 1];
      q.pop_back();
    }
    return ;
  }
  bool check(void)
  {
    pair<T, T> a = q[q.size() - 3];
    pair<T, T> b = q[q.size() - 2];
    pair<T, T> c = q[q.size() - 1];
    assert(a.first >= b.first);
    assert(b.first >= c.first);
    return (b.first - a.first) * (c.second - b.second) >= (b.second - a.second) * (c.first - b.first);
  }
  T eval(T x, pair<T, T> p)
  {
    return p.first * x + p.second;
  }
  T query(T x) // ASC x
  {
    while (2 <= q.size() && eval(x, q[0]) >= eval(x, q[1])) {
      q.pop_front();
    }
    return eval(x, q.front());
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  lli c;
  while (cin >> n >> c) {
    vector<lli> h(n);
    cin >> h;
    ConvexHullTrick<lli> cht;
    for (int i = 0; i < n; ++i) {
      lli x = i ? cht.query(h[i]) + h[i] * h[i] : 0;
      cht.append(-2 * h[i], h[i] * h[i] + x + c);
    }
    cout << cht.query(h.back()) + h.back() * h.back() << endl;
  }

  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/edpc/Z)
