# atcoder/abc185/F

## Code
main.cpp
{% raw %}
```cpp
// atcoder/abc185/F/main.cpp
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

template<typename T>
struct SegTree {
  int n;
  int origin_size;
  vector<T> v;
  using F = function<T(T, T)>;
  F fn;
  T e;
  SegTree(int n_, T e_, F fn_) {
    origin_size = n_;
    e = e_;
    fn = fn_;
    n = 1;
    while (n < n_) n *= 2;
    v.resize(2 * n - 1, e);
  }

  void update(size_t k, T a) {
    k += n - 1;
    v[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      v[k] = fn(v[k * 2 + 1], v[k * 2 + 2]);
    }
    return ;
  }

  T operator [] (size_t idx) const {
    return v.at(idx + n - 1);
  }

  inline T operator () () const {
    return query(0, origin_size, 0, 0, n);
  }

  inline T operator () (size_t a) const {
    return query(a, a+1, 0, 0, n);
  }

  inline T operator () (size_t a, size_t b) const {
    return query(a, b, 0, 0, n);
  }

  inline T query(size_t a, size_t b) const {
    assert(a < b);
    assert(b <= origin_size);
    return query(a, b, 0, 0, n);
  }

  T query(size_t a, size_t b, size_t k, size_t l, size_t r) const {
    if (r <= a || b <= l) return e;
    if (a <= l && r <= b) return v.at(k);

    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

    return fn(vl, vr);
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, q;
  while (cin >> n >> q) {
    vec<int> a(n);
    cin >> a;

    SegTree<int> segtree(n, 0, [] (auto a, auto b) { return a ^ b; });
    for (int i = 0; i < a.size(); ++i) {
      segtree.update(i, a[i]);
    }

    while (q--) {
      int t, x, y;
      cin >> t >> x >> y;
      if (t == 1) {
        --x;
        int z = segtree.query(x, x + 1);
        segtree.update(x, z ^ y);
      }
      if (t == 2) {
        --x;
        --y;
        cout << segtree.query(x, y + 1) << endl;
      }
    }
  }

  return 0;
}
```
{% endraw %}
main.go
{% raw %}
```go
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type SegmentTree struct {
	data []interface{}
	n    int
	e    interface{}
	op   func(interface{}, interface{}) interface{}
}

func NewSegmentTree(n int, e interface{}, op func(interface{}, interface{}) interface{}) *SegmentTree {
	segtree := new(SegmentTree)
	segtree.op = op
	segtree.n = 1
	for segtree.n < n {
		segtree.n *= 2
	}
	segtree.data = make([]interface{}, segtree.n*2-1)
	for i := 0; i < segtree.n*2-1; i++ {
		segtree.data[i] = e
	}
	return segtree
}

func (segtree *SegmentTree) Update(idx int, x interface{}) {
	idx += segtree.n - 1
	segtree.data[idx] = x
	for 0 < idx {
		idx = (idx - 1) / 2
		segtree.data[idx] = segtree.op(segtree.data[idx*2+1], segtree.data[idx*2+2])
	}
}

func (segtree *SegmentTree) query(begin, end, idx, a, b int) interface{} {
	if b <= begin || end <= a {
		return 0
	}
	if begin <= a && b <= end {
		return segtree.data[idx]
	}
	v1 := segtree.query(begin, end, idx*2+1, a, (a+b)/2)
	v2 := segtree.query(begin, end, idx*2+2, (a+b)/2, b)
	return segtree.op(v1, v2)
}

func (segtree *SegmentTree) Query(begin, end int) interface{} {
	return segtree.query(begin, end, 0, 0, segtree.n)
}

func main() {
	const N = 300000 + 1

	segtree := NewSegmentTree(N, 0, func(a, b interface{}) interface{} { return a.(int) ^ b.(int) })

	var n, q int
	fmt.Scan(&n, &q)

	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	for i := 0; i < n; i++ {
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		segtree.Update(i, a)
	}

	for i := 0; i < q; i++ {
		sc.Scan()
		t, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		x, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		y, _ := strconv.Atoi(sc.Text())
		if t == 1 {
			z := segtree.Query(x-1, x)
			segtree.Update(x-1, (interface{})(z.(int)^y))
		}
		if t == 2 {
			fmt.Println(segtree.Query(x-1, y))
		}
	}
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/abc185/F)
