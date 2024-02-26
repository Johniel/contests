// atcoder/abc017/D/main.cpp
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

constexpr lli mod = 1e9 + 7;

template<typename F>
struct DualSegTree {
  // ABC017D
  using composition_fn = function<F(F, F)>; // composition(f(x), g(x)):=f(g(x))
  DualSegTree(size_t n_, composition_fn composition_, F e_)
    : n(n_), composition(composition_), e(e_), bit_ceiled_n(bit_ceil(n_)) {
    lazy.resize(2 * bit_ceiled_n, e);
  }
  void apply(size_t begin, size_t end, F f) {
    assert(0 <= begin && begin < n);
    assert(0 <= end && end <= n);
    assert(begin <= end);
    size_t a = begin + bit_ceiled_n;
    size_t b = end + bit_ceiled_n;
    push((a >> __builtin_ctz(a)));
    push((b >> __builtin_ctz(b)) - 1);
    for (; a < b; a /= 2, b /= 2 ) {
      if (a & 1) {
        lazy[a] = composition(f, lazy[a]);
        ++a;
      }
      if (b & 1) {
        --b;
        lazy[b] = composition(f, lazy[b]);
      }
    }
    return ;
  }
  void set(size_t idx, F f) {
    assert(0 <= idx && idx < n);
    push(idx + bit_ceiled_n);
    lazy[idx + bit_ceiled_n] = f;
    return ;
  }
  F get(size_t idx) {
    assert(0 <= idx && idx < n);
    push(idx + bit_ceiled_n);
    return lazy[idx + bit_ceiled_n];
  }
  size_t size(void) const { return n; } ;

  vector<F> lazy;
  const composition_fn composition;
  const F e;
  const size_t n;
  const size_t bit_ceiled_n;
  void push(size_t idx) {
    int depth = bit_width(idx);
    for (int d = depth - 1; 0 < d; --d) {
      size_t i = idx >> d;
      if (lazy[i] != e) {
        lazy[i * 2 + 0] = composition(lazy[i], lazy.at(i * 2 + 0));
        lazy[i * 2 + 1] = composition(lazy[i], lazy.at(i * 2 + 1));
        lazy[i] = e;
      }
    }
    return ;
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
    v.push_back(v.back());

    DualSegTree<lli>::composition_fn c = [&] (lli a, lli b) { return (a + b) % mod; };
    DualSegTree<lli> seg(v.size(), c, 0);
    seg.set(0, 1);

    set<int> vis;
    queue<int> q;
    for (int i = 0; i < v.size(); ++i) {
      unless (vis.count(v[i])) {
        q.push(v[i]);
        vis.insert(v[i]);
      } else {
        while (q.front() != v[i]) {
          const int j = i - vis.size();
          seg.apply(j + 1, i + 1, seg.get(j));
          q.pop();
          vis.erase(v[j]);
        }
        const int j = i - vis.size();
        seg.apply(j + 1, i + 1, seg.get(j));
        q.pop();
        q.push(v[i]);
      }
    }

    cout << seg.get(v.size() - 1) << endl;
  }

  return 0;
}
