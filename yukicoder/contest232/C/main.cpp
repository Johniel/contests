// yukicoder/contest232/C/main.cpp
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

template<typename T>
class BIT {
public:
  vector<T> bit;
  size_t n;
  T z;
  BIT (size_t n_, T zero) : n(n_), z(zero) {
    bit.resize(n + 1, z);
  }
  T sum(size_t i) {
    assert(i < bit.size());
    T s = z;
    while (0 < i) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }
  void add(size_t i, T x) {
    ++i; // 1-origin
    assert(i < bit.size());
    while (i <= n) {
      bit[i] += x;
      i += i & -i;
    }
    return ;
  }
  T query(size_t begin, size_t end) // (begin, end]
  {
    assert(begin <= end);
    return sum(end) - sum(begin);
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<pair<lli, int>> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i].first;
      v[i].second = i;
    }
    sort(v.begin(), v.end());

    vector<vector<lli>> u(m);
    for (int i = 0; i < m; ++i) {
      u[i].resize(4);
      cin >> u[i];
      swap(u[i][0], u[i][3]);
      u[i][3] = i;
    }
    sort(u.begin(), u.end());
    reverse(u.begin(), u.end());

    vector<lli> r(m);
    BIT<lli> bit(n, 0);
    SegTree<lli> segtree([] (lli a, lli b) { return a + b; }, 0, n);
    for (int i = 0; i < u.size(); ++i) {
      while (v.size() && u[i][0] <= v.back().first) {
        segtree.update(v.back().second, v.back().first);
        bit.add(v.back().second, 1);
        v.pop_back();
      }
      int begin = u[i][1] - 1;
      int end = u[i][2] - 1;
      int idx = u[i][3];
      r[idx] = segtree.query(begin, end + 1) - bit.query(begin, end + 1) * u[i][0];
    }
    each (i, r) cout << i << endl;
  }


  return 0;
}
