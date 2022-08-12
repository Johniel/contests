// https://github.com/johniel/atcoder/abc262/F/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

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

vec<int> fn1(vec<pair<int, int>> a, int k)
{
  const int inf = (1 << 29);
  const int n = a.size();
  SegTree<pair<int, int>> seg(n, {inf, 0}, [] (auto x, auto y) { return min(x, y); });
  for (int i = 0; i < a.size(); ++i) {
    seg.update(i, {a[i].first, i});
  }
  SegTree<int> cost(n, 0, [] (auto x, auto y) { return x + y; });
  for (int i = 0; i < a.size(); ++i) {
    cost.update(i, a[i].second);
  }
  vec<int> v;
  const int x = k;
  for (int i = 0; v.size() + x < a.size() && i < a.size(); ) {
    int small = i;
    int large = n;
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if (cost(i, mid) <= k) small = mid;
      else large = mid;
    }
    const int j = large;
    auto p = seg(i, j);
    v.push_back(p.first);
    k -= cost(i, p.second);
    i = p.second + 1;
    assert(0 <= k);
  }
  return v;
}

vec<int> fn2(vec<pair<int, int>> a, int k)
{
  const int n = a.size();
  pair<int, int> mn = {1 << 29, n};
  for (int i = a.size() - 1, j = 0; 0 <= i && j < k; --i, ++j) {
    setmin(mn, {a[i].first, i});
  }
  vec<pair<int, int>> b;
  for (int j = n - 1; mn.second <= j; --j) {
    b.push_back(a.back());
    a.pop_back();
  }
  reverse(b.begin(), b.end());
  each (i, b) i.second = 0;
  k -= b.size();
  each (i, a) b.push_back(i);
  return fn1(b, k);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, k;
  while (cin >> n >> k) {
    vec<int> a(n);
    cin >> a;
    vec<pair<int, int>> v;
    for (int i = 0; i < a.size(); ++i) {
      v.push_back({a[i], 1});
    }
    vec<int> x = fn1(v, k);
    vec<int> y = fn2(v, k);
    a = min(x, y);
    each (i, a) cout << i << ' '; cout << endl;
  }

  return 0;
}
