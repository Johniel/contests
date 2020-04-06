// atcoder/abc158/F/main.cpp
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
  vector<T> dat;
  using F = function<T(T, T)>;
  F fn;
  T e;
  SegTree(int n_, T e_, F fn_) {
    e = e_;
    fn = fn_;
    n = 1;
    while (n < n_) n *= 2;
    dat.resize(2 * n - 1, e);
  }

  void update(size_t k, T a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = fn(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
    return ;
  }

  T operator [] (size_t idx) const {
    return dat[idx + n - 1];
  }

  T query(size_t a, size_t b) {
    return query(a, b, 0, 0, n);
  }

  T query(size_t a, size_t b, size_t k, size_t l, size_t r) {
    if (r <= a || b <= l) return e;
    if (a <= l && r <= b) return dat.at(k);

    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

    return fn(vl,vr);
  }
};

int main(int argc, char *argv[])
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  int n;
  while (cin >> n) {
    vec<pair<lli, lli>> v(n);
    cin >> v;
    // v.push_back(make_pair(1LL << 60, 0));
    sort(v.begin(), v.end());

    const int N = 2 * 1e5 + 5;
    static lli x[N];
    fill(x, x + N, 1);

    // SegTree<lli> seg(n+1, 1, [] (lli a, lli b) { return (a * b) % 998244353; });
    SegTree<int> rmq(n+1, -1, [] (int a, int b) { return max(a, b); });
    for (int i = 0; i <= n; ++i) {
      rmq.update(i, i);
    }

    // cout << v << endl;
    for (int i = v.size() - 1; 0 <= i; --i) {
      auto itr = upper_bound(v.begin(), v.end(), make_pair(v[i].first + v[i].second, -(1LL << 60)));
      const int j = itr - v.begin();
      int k = max(i + 1, rmq.query(i + 1, j));
      x[i] = (x[k] + x[i + 1]) % mod;
      rmq.update(i, k);
    }

    // for (int i = 0; i < n; ++i) cout << seg.query(i, i + 1) << ", "; cout << endl;
    // cout << seg.query(0, 1) << endl;
    cout << x[0] << endl;

    // cout << endl;
  }

  return 0;
}
