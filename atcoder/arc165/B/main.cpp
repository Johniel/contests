// github.com/Johniel/contests
// atcoder/arc165/B/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
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

template<typename T> ostream& operator << (ostream& os, deque<T>& q) {
  os << "#deque{";
  for (int i = 0; i < q.size(); ++i) os << q[i] << ",";
  os << "}";
  return os;
}

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T>
class ordered_set : public tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> {};
// find_by_order(k),order_of_key(k)
template<typename T> ostream& operator << (ostream& os, ordered_set<T>& s) { os << "&{"; for (int i = 0; i < s.size(); ++i) { os << *s.find_by_order(i) << ","; } os << "}"; return os; }

vec<int> fn1(const int n, const int k, vec<int> a)
{
  bool f = false;
  ordered_set<int> s;
  pair<int, int> mx = make_pair(n - k - 1, n - k - 1);

  for (int i = 0, j = 0; i + k <= a.size(); ++i) {
    if (i) s.erase(a[i - 1]);
    while (j < a.size() && s.size() < k) {
      s.insert(a[j]);
      int ord = s.order_of_key(a[j]);
      if(s.size() != ord + 1) {
        setmax(mx, make_pair(i + ord, i));
        s.clear();
        i = j - 1;
        break;
      }
      ++j;
    }
    if (s.size() == k) { f = true; break; }
  }

  if (!f) {
    sort(a.begin() + mx.second, a.begin() + mx.second + k);
  }
  return a;
}

template <typename T, typename S>
bool chmax(T &a, S b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
using namespace std;

typedef long long ll;

vec<int> fn2(const int n, const int k, vec<int> a)
{
  vec<int> b(n - 1);
    rep(i, 0, n - 1) b[i] = (a[i] > a[i + 1]);
    vector<int> bs(n);
    rep(i, 0, n - 1) { bs[i + 1] = bs[i] + b[i]; }
    rep(i, 0, bs.size() - k + 1) {
        if (bs[i] == bs[i + k - 1]) {
            return a;
        }
    }
    int nw = bs.back();
    int nx = 1e9;
    for (int i = bs.size() - 1; i >= 0; i--) {
        if (bs[i] != nw) {
            nx = 1;
            nw = bs[i];
            bs[i] = nx;
        } else {
            nx++;
            bs[i] = nx;
        }
    }
    int ind = -1, mx = -1;
    rep(i, 0, n - k + 1) {
        if (chmax(mx, i + bs[i])) {
            ind = i;
        }
    }
    vector<int> c = a;
    sort(a.begin() + ind, a.begin() + ind + k);
    sort(c.begin() + n - k, c.end());
    if (a < c) a = c;
    return a;
}

vec<int> fn3(const int n, const int k, vec<int> a)
{
  if (n == k) {
    sort(a.begin(), a.end());
    return a;
  }
    {
      int cnt = 1;
      int mx = 0;
      for (int i = 0; i + 1 < a.size(); ++i) {
        if (a[i] < a[i + 1]) ++cnt;
        else cnt = 1;
        setmax(mx, cnt);
      }
      if (k <= mx) {
        // each (i, a) cout << i << ' '; cout << endl;
        return a;
      }
    }

    const int inf = (1 << 28);
    SegTree<int> seg(a.size(), inf, [] (auto a, auto b) { return min(a, b); });
    for (int i = 0; i < a.size(); ++i) {
      seg.update(i, a[i]);
    }

    int z = n - k;
    // cout << a[n - k - 1] << "<" << seg(n - k, n - 1) << endl;
    if (a[n - k - 1] < seg(n - k, n - 1)) {
      --z;
    }
    {
      int i = n - k - 1;
      int j = 1;
      while (z && i) {
        int d = abs(i - (n - k));
        int y = seg(n - k, n - j - 1);
        if (y == inf && 0 <= j) break;
        // cout << i << ": " << make_pair(n - k, n - j - 1) << " (" << a[i - 1] << "<" << a[i] << ") (" << a[n-k-1] << "<" << y << ")" << ' ' << make_pair(z, a[z]) << endl;
        if (a[i - 1] < a[i]) {
          if (a[n - k - 1] < y) z = i - 1;
          --i;
          ++j;
        } else {
          break;
        }
      }
    }
    // cout << "z:=" << z << ' ' << a[z] << endl; each (i, a) cout << i << ' '; cout << endl;
    sort(a.begin() + z, a.begin() + z + k);
    return a;
}

uint32_t xorshift(void)
{
  // https://shindannin.hatenadiary.com/entry/2021/03/06/115415
  static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t;

  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

int main(int argc, char *argv[])
{
  for (int _ = 0;0; ++_) {
    const int n = xorshift() % 9 + 5;
    vec<int> a;
    for (int _ = 0; _ < n; ++_) {
      a.push_back(xorshift());
    }
    vec<int> b = a;
    sort(b.begin(), b.end());
    map<int, int> rename;
    for (int i = 0; i < b.size(); ++i) {
      rename[b[i]] = i;
    }
    const int k = xorshift() % n + 1;
    each (i, a) i = rename[i] + 1;
    vec<int> x = fn3(n, k, a);
    vec<int> y = fn2(n, k, a);
    cout << "#" << _ << ' ' << n << ' ' << k << endl;
    cout << a << endl;
    cout << x << endl;
    cout << y << endl;
    cout << endl;
    assert(x == y);
  }

  int n, k;
  while (cin >> n >> k) {
    vec<int> a(n);
    cin >> a;
    a = fn3(n, k, a);
    each (i, a) cout << i << ' '; cout << endl;
  }
  return 0;
}
