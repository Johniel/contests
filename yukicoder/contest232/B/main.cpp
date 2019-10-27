// yukicoder/contest232/B/main.cpp
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
class SegTree {
public:
  using fn = function<T(T&, T&)>;
  SegTree (fn f, T ini_, size_t n_) : merge(f), ini(ini_) {
    n = 1;
    while (n < n_) n *= 2;
    v.resize(n * 2 - 1, ini = ini_);
    merge = f;
  }
  void update(size_t k, T x) {
    k += n - 1;
    v[k] = x;
    while (0 < k) {
      k = (k - 1) / 2;
      v[k] = merge(v[k * 2 + 1], v[k * 2 + 2]);
    }
    return ;
  }
  // [begin, end)
  T query(size_t begin, size_t end) {
    return query(begin, end, 0, 0, n);
  }
  T operator [] (size_t idx) const {
    return v[idx + n - 1];
  }
  void show(void) {
    for (int i = 0; i * 2 + 2 < v.size() && v[i] != ini; ++i) {
      clog << make_pair(i, v[i]) << ": " << make_pair(i * 2 + 1, v[i * 2 + 1]) << ", " << make_pair(i * 2 + 2, v[i * 2 + 2]) << endl;
    }
    return ;
  }
private:
  vector<T> v;
  int n;
  fn merge;
  T ini;

  T query(int begin, int end, int k, int l, int r) {
    if (r <= begin || end <= l) {
      return ini;
    }
    if (begin <= l && r <= end) {
      return v[k];
    } else {
      auto x = query(begin, end, k * 2 + 1, l, (l + r) / 2);
      auto y = query(begin, end, k * 2 + 2, (l + r) / 2, r);
      return merge(x, y);
    }
  }
};

template<typename V>
class BIT {
public:
  vector<V> bit;
  int n;
  V z;
  BIT (int n_, V zero) : n(n_), z(zero) {
    bit.resize(n + 1, z);
  }
  V sum(int i) {
    ++i; // 1-origin
    V s = z;
    while (0 < i) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }
  void add(int i, V x) {
    ++i; // 1-origin
    while (i <= n) {
      bit[i] += x;
      i += i & -i;
    }
    return ;
  }
  V query(int begin, int end)
  {
    return sum(end) - sum(begin - 1);
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  while (cin >> n >> q) {
    vector<int> v(n);
    cin >> v;

    BIT<lli> bit(n, 0);
    bit.add(0, v[0]);
    for (int i = 1; i < v.size(); ++i) {
      bit.add(i, v[i] - v[i - 1]);
    }

    SegTree<int> segtree([] (int a, int b) { return a + b; }, 0, n);
    for (int i = 0; i + 1 < v.size(); ++i) {
      segtree.update(i, bit.sum(i) == bit.sum(i + 1));
    }

    while (q--) {
      int op, a, b, c;
      cin >> op;
      if (op == 1) {
        cin >> a >> b >> c;
        --a;
        --b;
        bit.add(a, +c);
        bit.add(b + 1, -c);
        if (a) segtree.update(a - 1, bit.sum(a - 1) == bit.sum(a));
        if (b < n) segtree.update(b, bit.sum(b) == bit.sum(b + 1));
      }
      if (op == 2) {
        cin >> a >> b;
        --a;
        --b;
        cout << (b + 1 - a) - segtree.query(a, b) << endl;
      }
    }
  }

  return 0;
}
