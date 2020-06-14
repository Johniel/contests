// atcoder/abc170/E/main.cpp
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
// SegTree<int> rmq(a.size(), -(1 << 29), [] (int a, int b) { return max(a, b); });
const int N = 2 * 1e5 + 5;
const lli inf = 1LL << 60;
SegTree<lli> rmq(N, +inf, [] (lli a, lli b) { return min(a, b); });

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, Y;
  while (cin >> n >> Y) {
    static lli a[N];
    static lli b[N];
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
      --b[i];
    }

    for (int i = 0; i < N; ++i) {
      rmq.update(i, inf);
    }

    static priority_queue<pair<lli, lli>> q[N];
    for (int i = 0; i < N; ++i) {
      while (q[i].size()) q[i].pop();
    }

    for (int i = 0; i < n; ++i) {
      q[b[i]].push({a[i], i});
    }
    for (int i = 0; i < N; ++i) {
      if (q[i].size()) rmq.update(i, q[i].top().first);
    }

    for (int t = 1; t <= Y; ++t) {
      int c, d;
      cin >> c >> d;
      --c;
      --d;

      const int e = b[c];
      b[c] = d;

      q[d].push({a[c], c});

      while (q[e].size() && b[q[e].top().second] != e) {
        q[e].pop();
      }
      while (q[d].size() && b[q[d].top().second] != d) {
        q[d].pop();
      }

      if (q[e].size()) {
        rmq.update(e, q[e].top().first);
      } else {
        rmq.update(e, inf);
      }

      if (q[d].size()) {
        rmq.update(d, q[d].top().first);
      } else {
        rmq.update(d, inf);
      }

      cout << rmq.query(0, N) << endl;
    }
  }

  return 0;
}
