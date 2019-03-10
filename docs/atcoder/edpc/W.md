# Educational DP Contest: W Intervals

[問題文](https://atcoder.jp/contests/dp/tasks/dp_w)

```
dp[i][j] = i番目の文字までを決めていて、最後の1がj番目であるような場合の最大値
```
もし仮に上記のようなDPを考えると

```
 // f(i, j) は、始点がj以降でiを含むような区間のスコアの合計を返す関数
 for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      dp[i + 1][i] = max(dp[i + 1][i], dp[i][j] + f(i, j));
    }
  }
```
といった風になってO(N^2)で間に合わない。

---

1. dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
2. dp[i + 1][i] = max(dp[i + 1][i], dp[i][j] + f(i, j));

1つ目の式はただのコピーなので領域を使いまわす等できっと解決できるので一旦無視するとして、２つ目が問題になる。
ある位置iに1を立てたとしても獲得できるスコアがそれだけでは決まらない。
※直前に1を立てた位置とiの両方を含むような区間のスコアを重複して獲得しうるため。

なので、
```
dp[i] = i番目の文字が決まっている場合の最大値
```
といった解き方はできない。

---

iを含むような区間のスコアを足せるのか分からないから困るのであって、区間の終端時点でまとめて足してしまって最大値を探すように変えれば良い。

```
dp[i] = i番目までに終端がある区間を全て使ったときの最大値
```
としてみる。

```
dp[i + 1] = max({dp[0], ... dp[i]});
// ajはiを終端とする区間jのスコアで、kは区間jに含まれる。
dp[k] += aj;
```
ある区間に含まれる位置全てを更新しながら決めていくことをイメージすると良いのかもしれない。

これらは、
+ 区間に対するmax
+ 区間に対するadd
+ １カ所の更新

があれば実現できるので区間に対する操作をO(log N)で可能なデータ構造（遅延セグメント木等)を使って解ける。


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

template<typename T=lli>
class LazySegTree {
public:
  LazySegTree(int n_) {
    size_ = n_;
    n = 1;
    while (n < n_) n *= 2;
    node.resize(n * 2 - 1, 0);
    lazy.resize(n * 2 - 1, 0);
  }

  void add(size_t begin, size_t end, T x) {
    assert(begin < end);
    assert(end <= size_);
    add(begin, end, x, 0, 0, n);
  }

  T max(size_t begin, size_t end) {
    assert(begin < end);
    assert(end <= size_);
    return max(begin, end, 0, 0, n);
  }

  T update(size_t k, T x)
  {
    T y = this->max(k, k + 1);
    this->add(k, k + 1, x - y);
  }

  void dump(int n)
  {
    for (int i = 0; i < n; ++i) {
      cout << this->max(i, i + 1) << ' ';
    }
    cout << endl;
  }

private:
  vector<T> node;
  vector<T> lazy;
  int n;
  size_t size_;

  void propagate(int k, int l, int r) {
    node[k] += lazy[k];
    if(r - l > 1) {
      lazy[2 * k + 1] += lazy[k]; // / 2;
      lazy[2 * k + 2] += lazy[k]; // / 2;
    }
    lazy[k] = 0;
    return ;
  }

  void add(size_t begin, size_t end, T x, size_t k, size_t l, size_t r) {
    propagate(k, l, r);
    if (r <= begin || end <= l) {
      return ;
    }

    if (begin <= l && r <= end) {
      // lazy[k] += (r - l) * x;
      lazy[k] += x;
      propagate(k, l, r);
    } else {
      propagate(k, l, r);
      add(begin, end, x, k * 2 + 1, l, (l + r) / 2);
      add(begin, end, x, k * 2 + 2, (l + r) / 2, r);
      node[k] = std::max(node[2 * k + 1], node[2 * k + 2]);
    }
    return ;
  }

  T max(size_t begin, size_t end, size_t k, size_t l, size_t r) {
    if (r <= begin || end <= l) {
      return -(1LL << 60);
    }
    propagate(k, l, r);

    if (begin <= l && r <= end) {
      return node[k];
    } else {
      auto x = max(begin, end, k * 2 + 1, l, (l + r) / 2);
      auto y = max(begin, end, k * 2 + 2, (l + r) / 2, r);
      return std::max(x, y);
    }
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    map<int, vector<pair<int, lli>>> rs;
    for (int i = 0; i < m; ++i) {
      int begin, end;
      lli a;
      cin >> begin >> end >> a;
      --end;
      --begin;
      rs[end].push_back({begin, a});
    }

    const int N = 2 * 1e5 + 5;
    LazySegTree<> segtree(N);
    for (int end = 0; end <= n; ++end) {
      if (end) {
        auto mx = max(0LL, segtree.max(0, end));
        segtree.update(end, mx);
      }
      each (i, rs[end]) {
        auto begin = i.first;
        auto a = i.second;
        segtree.add(begin, end + 1, a);
      }
    }
    cout << segtree.max(0, n + 1) << endl;
  }

  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/edpc/W)
