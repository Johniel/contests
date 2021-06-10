// atcoder/abc201/F/main.cpp
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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

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
    assert(a < b);
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

template<typename T>
struct PrefixSum {
  vector<T> sum;
  PrefixSum(vector<T> v) {
    sum.push_back(0);
    for (int i = 0; i < v.size(); ++i) {
      sum.push_back(sum.back() + v[i]);
    }
  }
  T operator () (size_t begin, size_t end) const {
    assert(begin <= end);
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<lli> p(n);
    cin >> p;
    each (i, p) --i;
    vec<lli> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 0; i < n; ++i) {
      setmin(b[i], a[i]);
      setmin(c[i], a[i]);
    }
    map<int, int> idx;
    for (int i = 0; i < n; ++i) {
      idx[p[i]] = i;
    }
    // cout << idx << endl;
    PrefixSum<lli> sum_a(a);
    PrefixSum<lli> sum_b(b);
    PrefixSum<lli> sum_c(c);
    const lli inf = 1LL << 60;
    SegTree<lli> seg(n, inf, [] (auto i, auto j) { return min(i, j); });
    lli dp[n];
    fill(dp, dp + n, inf);
    for (int i = 0; i < n; ++i) {
      dp[i] = min(sum_b(0, i), seg(0, idx[i]) + sum_a(0, i));
      // cout << sum_b(0, i) << ' ' << seg(0, p[i]) << '+' << sum_a(0, i) << endl;
      seg.update(idx[i], dp[i] - sum_a(0, i + 1));
      // for (int j = 0; j < n; ++j) cout << dp[j] << ' '; cout << endl;
      // for (int j = 0; j < n; ++j) cout << seg(j) << ' '; cout << endl;
    }
    lli mn = inf;
    for (int i = 0; i < n; ++i) {
      setmin(mn, dp[i] + sum_c(i + 1, n));
    }
    cout << mn << endl;
    // cout << endl;
    // if (n == 6) break;
  }

  return 0;
}
