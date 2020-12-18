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
