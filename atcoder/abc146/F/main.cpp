// atcoder/abc146/F/main.cpp
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
  string s;
  while (cin >> n >> m >> s) {
    if (s == "1") {
      cout << -1 << endl;
      continue;
    }
    if (s == "0") {
      cout << 0 << endl;
      continue;
    }

    SegTree<pair<int, int>>::fn merge = [] (pair<int, int> a, pair<int, int> b) {
      if (a.first != b.first) return a < b ? a : b;
      return a.second < b.second ? b : a;
    };
    const int inf = 1 << 29;
    SegTree<pair<int, int>> segtree(merge, make_pair(inf, -1), s.size());
    segtree.update(0, make_pair(0, 0));

    reverse(s.begin(), s.end());
    const int N = 1e5 + 5;
    static int prev[N];
    fill(prev, prev + N, -1);
    prev[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == '1') continue;
      auto mn = segtree.query(max(0, i - m), i);
      auto p = make_pair(mn.first + 1, i);
      segtree.update(i, p);
      prev[i] = mn.second;
    }

    if (inf <= segtree.query(s.size() - 1, s.size()).first) {
      cout << -1 << endl;
      continue;
    }

    vector<int> path;
    for (int curr = s.size() - 1; curr; curr = prev[curr]) {
      path.push_back(curr);
    }
    path.push_back(0);
    vector<int> v;
    for (int i = 0; i + 1 < path.size(); ++i) {
      v.push_back(path[i] - path[i + 1]);
    }
    each (i, v) cout << i << ' '; cout << endl;
  }

  return 0;
}
