# atcoder/abc084/D

## Code
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

struct Acc {
  vector<lli> sum;
  Acc(vector<lli> v) {
    sum.push_back(0);
    each (i, v) {
      sum.push_back(sum.back() + i);
    }
  }
  lli query(lli begin, lli end) {
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  const int N = 1e5 + 5;
  bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < N; ++i) {
    for (int j = 2; i * j < N; ++j) {
      prime[i * j] = false;
    }
  }

  vector<lli> v;
  for (int i = 0; i < N; ++i) {
    int j = (i + 1) / 2;
    v.push_back(i % 2 && prime[i] && prime[j]);
  }
  Acc acc(v);
  
  int q;
  while (cin >> q) {
    while (q--) {
      int a, b;
      cin >> a >> b;
      cout << acc.query(a, b + 1) << endl;
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
	"fmt"
)

type SegmentTree struct {
	data []int
	n    int
}

func NewSegmentTree(n int) *SegmentTree {
	segtree := new(SegmentTree)
	segtree.n = 1
	for segtree.n < n {
		segtree.n *= 2
	}
	segtree.data = make([]int, segtree.n*2-1)
	return segtree
}

func (segtree *SegmentTree) Update(idx, x int) {
	idx += segtree.n - 1
	segtree.data[idx] = x
	for 0 < idx {
		idx = (idx - 1) / 2
		segtree.data[idx] = segtree.data[idx*2+1] + segtree.data[idx*2+2]
	}
}

func (segtree *SegmentTree) query(begin, end, idx, a, b int) int {
	if b <= begin || end <= a {
		return 0
	}
	if begin <= a && b <= end {
		return segtree.data[idx]
	}
	v1 := segtree.query(begin, end, idx*2+1, a, (a+b)/2)
	v2 := segtree.query(begin, end, idx*2+2, (a+b)/2, b)
	return v1 + v2
}

func (segtree *SegmentTree) Query(begin, end int) int {
	return segtree.query(begin, end, 0, 0, segtree.n)
}

func main() {
	const N = 100000 + 1

	prime := make([]bool, N)
	for i := 0; i < N; i++ {
		prime[i] = true
	}
	prime[0] = false
	prime[1] = false
	for i := 2; i*i < N; i++ {
		for j := 2; i*j < N; j++ {
			prime[i*j] = false
		}
	}

	segtree := NewSegmentTree(N)
	for i := 2; i < N; i++ {
		if prime[i] && prime[(i+1)/2] {
			segtree.Update(i, 1)
		}
	}

	var q int
	fmt.Scan(&q)
	for i := 0; i < q; i++ {
		var l, r int
		fmt.Scan(&l)
		fmt.Scan(&r)
		fmt.Println(segtree.Query(l, r+1))
	}
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/abc084/D)
