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
