// atcoder/abc234/G/main.cpp
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
constexpr lli mod = 998244353;

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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;
    const lli inf = 1LL << 60;

    SegTree<lli> rmq_mx(n, -inf, [] (auto x, auto y) { return max(x, y); });
    SegTree<lli> rmq_mn(n, +inf, [] (auto x, auto y) { return min(x, y); });
    for (int i = 0; i < n; ++i) {
      rmq_mx.update(i, a[i]);
      rmq_mn.update(i, a[i]);
    }

    const int N = 3 * 1e5 + 3;
    static lli dp[N];
    fill(dp, dp + N, 0);
    dp[0] = 1;
    stack<pair<lli, lli>> smx, smn;
    lli mx = 0, mn = 0;
    for (int i = 0; i <= a.size(); ++i) {
      if (i) {
        {
          pair<lli, lli> p = {a[i - 1], dp[i - 1]};
          while (smx.size() && smx.top().first < p.first) {
            pair<lli, lli> q = smx.top();
            smx.pop();
            mx = (mx - q.first * q.second % mod + mod) % mod;
            (p.second += q.second) %= mod;
          }
          (mx += p.first * p.second) %= mod;
          smx.push(p);
        }
        {
          pair<lli, lli> p = {a[i - 1], dp[i - 1]};
          while (smn.size() && smn.top().first > p.first) {
            pair<lli, lli> q = smn.top();
            smn.pop();
            mn = (mn - q.first * q.second % mod + mod) % mod;
            (p.second += q.second) %= mod;
          }
          (mn += p.first * p.second) %= mod;
          smn.push(p);
        }
      }
      (dp[i] += (mx - mn + mod) % mod) %= mod;
    }
    cout << dp[n] << endl;
  }

  return 0;
}
