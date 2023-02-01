// github.com/Johniel/contests
// atcoder/abc287/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

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
    assert(a <= b);
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

#include "atcoder/string"
using namespace atcoder;

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<str> v(n);
    cin >> v;
    str s;
    vec<int> a;
    each (i, v) {
      a.push_back(s.size());
      s += i;
      s += '$';
    }

    vec<int> sa = suffix_array(s);
    // cout << "sa:" << sa << endl;
    // each (i, sa) cout << s.substr(i) << endl;
    vec<int> h = lcp_array(s, sa);
    // cout << "LCP:" << h << endl;

    SegTree<int> seg(h.size(), 1 << 29, [] (auto x, auto y) { return min(x, y); });
    for (int i = 0; i < h.size(); ++i) {
      seg.update(i, h[i]);
    }
    // for (int i = 0; i < h.size(); ++i) cout << make_pair(i, seg(i, i + 1)) << ' '; cout << endl;

    map<int, int> m;
    for (int i = 0; i < sa.size(); ++i) {
      m[sa[i]] = i;
    }
    // cout << m << endl;

    vec<pair<int, int>> b;
    for (int i = 0; i < a.size(); ++i) {
      b.push_back(make_pair(m[a[i]], i));
      // cout << s.substr(sa[m[a[i]]]) << endl;
    }
    sort(b.begin(), b.end());

    // cout << "b:" << b << endl;

    vec<int> u(v.size(), -1);
    for (int i = 0; i < b.size(); ++i) {
      if (i) {
        int k = b[i].first;
        int j = b[i - 1].first;
        unless (k < j) swap(k, j);
        // cout << i << ' ' << make_pair(k, j) << ' ' << seg(k, j) << endl;
        int x = min(v[b[i].second].size(), v[b[i - 1].second].size());
        setmax(u[b[i].second], min<int>(x, seg(k, j)));
      }
      if (i + 1 < b.size()) {
        int k = b[i].first;
        int j = b[i + 1].first;
        unless (k < j) swap(k, j);
        // cout << i << ' ' << make_pair(k, j) << endl;
        int x = min(v[b[i].second].size(), v[b[i + 1].second].size());
        setmax(u[b[i].second], min<int>(x, seg(k, j)));
      }
    }
    for (int i = 0; i < u.size(); ++i) {
      setmin<int>(u[i], v[i].size());
      cout << u[i] << endl;
    }
    cout << endl;
    // break;
  }
  return 0;
}
