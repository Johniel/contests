// yukicoder/contest232/D/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    vector<int> v(n);
    cin >> v;

    auto fn = [] (vector<int> a, vector<int> b) {
      if (a.empty()) return b;
      each (i, b) {
        if (a.back() < i) {
          a.push_back(i);
        }
      }
      return a;
    };
    SegTree<vector<int>> segtree(fn, vector<int>(), n);
    for (int i = 0; i < v.size(); ++i) {
      segtree.update(i, vector<int>(1, v[i]));
    }

    while (m--) {
      int _, a, b;
      cin >> _ >> a >> b;
      --a;
      --b;
      cout << segtree.query(a, b + 1).size() << endl;
    }
  }

  return 0;
}
