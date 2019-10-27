// yukicoder/contest232/A/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  while (cin >> n >> q) {
    map<int, int> m;
    SegTree<int> segtree([] (int a, int b) { return min(a, b); }, 1 << 29, n);
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      m[a] = i;
      segtree.update(i, a);
    }
    while (q--) {
      int a, b, c;
      cin >> a >> b >> c;
      if (a == 1) {
        --b;
        --c;
        int x = segtree[b];
        int y = segtree[c];
        segtree.update(b, y);
        segtree.update(c, x);
        m[x] = c;
        m[y] = b;
      }
      if (a == 2) {
        --b;
        cout << m[segtree.query(b, c)] + 1 << endl;
      }
    }
  }

  return 0;
}
