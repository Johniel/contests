// github.com/Johniel/contests
// atcoder/abc298/F/main.cpp

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
template<typename T> istream& operator >> (istream& is, SegTree<T>& seg) { for (int i = 0; i < seg.n; ++i) { T t; is >> t; seg.update(i, t); } return is; }
template<typename T> ostream& operator << (ostream& os, SegTree<T>& seg) { vector<T> v; for (int i = 0; i < seg.n; ++i) v.push_back(seg[i]); os << v; return os; }

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    const int N = 2 * 1e5 + 3;
    static int h[N];
    static int w[N];
    static lli v[N];
    for (int i = 0; i < n; ++i) {
      cin >> h[i] >> w[i] >> v[i];
    }
    {
      vec<int> v;
      for (int i = 0; i < n; ++i) {
        v.push_back(h[i]);
      }
      sort(v.begin(), v.end());
      v.erase(unique(v.begin(), v.end()), v.end());
      map<int, int> m;
      for (int i = 0; i < v.size(); ++i) m[v[i]] = i;
      for (int i = 0; i < n; ++i) h[i] = m[h[i]];
    }
    {
      vec<int> v;
      for (int i = 0; i < n; ++i) {
        v.push_back(w[i]);
      }
      sort(v.begin(), v.end());
      v.erase(unique(v.begin(), v.end()), v.end());
      map<int, int> m;
      for (int i = 0; i < v.size(); ++i) m[v[i]] = i;
      for (int i = 0; i < n; ++i) w[i] = m[w[i]];
    }

    map<pair<int, int>, lli> m;
    for (int i = 0; i < n; ++i) {
      m[make_pair(h[i], w[i])] = v[i];
    }

    static lli sum_h[N];
    static lli sum_w[N];
    fill(sum_h, sum_h + N, 0);
    fill(sum_w, sum_w + N, 0);

    for (int i = 0; i < n; ++i) {
      sum_w[h[i]] += v[i];
      sum_h[w[i]] += v[i];
    }

    lli z = 0;
    for (int i = 0; i < N; ++i) {
      setmax(z, sum_w[i]);
      setmax(z, sum_h[i]);
    }

    for (int i = 0; i < n; ++i) {
      setmax(z, sum_w[h[i]] + sum_h[w[i]] - v[i]);
    }

    SegTree<lli> mxh(N, 0, [] (auto x, auto y) { return max(x, y); });
    SegTree<lli> mxw(N, 0, [] (auto x, auto y) { return max(x, y); });
    for (int i = 0; i < n; ++i) {
      mxh.update(i, sum_h[i]);
      mxw.update(i, sum_w[i]);
    }
    map<int, vec<int>> mh, mw;
    for (int i = 0; i < n; ++i) {
      mh[h[i]].push_back(w[i]);
      mw[w[i]].push_back(h[i]);
    }

    each (k, mh) {
      map<int, lli> tmp;
      each (i, k.second) {
        tmp[i] = mxh[i];
        mxh.update(i, 0);
      }
      setmax(z, sum_w[k.first] + mxh.query(0, N));
      each (i, k.second) {
        mxh.update(i, tmp[i]);
      }
    }

    cout << z << endl;
  }
  return 0;
}
