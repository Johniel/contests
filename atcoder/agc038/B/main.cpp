// atcoder/agc038/B/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, k;
  while (cin >> n >> k) {
    vec<int> v(n);
    cin >> v;

    SegTree<int> mx(v.size(), -(1 << 29), [] (int a, int b) { return max(a, b); });
    SegTree<int> mn(v.size(), +(1 << 29), [] (int a, int b) { return min(a, b); });
    for (int i = 0; i < n; ++i) {
      mx.update(i, v[i]);
      mn.update(i, v[i]);
    }

    lli x = (n - k) + 1;

    int sorted[n];
    fill(sorted, sorted + n, 1);
    for (int i = 1; i < n; ++i) {
      if (v[i - 1] < v[i]) {
        sorted[i] = sorted[i - 1] + 1;
      }
    }
    int y = 0;
    for (int i = 0; i < n; ++i) {
      y += (k <= sorted[i]);
    }

    for (int i = 0; i + k < n; ++i) {
      if (sorted[i + k] <= k) {
        bool f = true;
        {
          int a = mn.query(i, i + k);
          int b = mn.query(i + 1, i + 1 + k);
          unless (a < b) f = false;
        }
        {
          int a = mx.query(i, i + k);
          int b = mx.query(i + 1, i + 1 + k);
          unless (a < b) f = false;
        }
        x -= f;
      }
    }

    x -= max(0, y - 1);
    cout << x << endl;
  }

  return 0;
}
