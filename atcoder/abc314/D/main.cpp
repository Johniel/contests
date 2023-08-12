// github.com/Johniel/contests
// atcoder/abc314/D/main.cpp

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

int main(int argc, char *argv[])
{
  int n;
  str s;
  int q;
  while (cin >> n >> s >> q) {
    const int N = 5 * 1e5 + 3;
    static int updated[N];
    fill(updated, updated + N, 0);

    SegTree<int> seg(N, 0, [] (auto a, auto b) {
      if (a == b) return a;
      if (b == 0) return a;
      return b;
    });

    for (int _ = 1; _ <= q; ++_) {
      int t;
      int idx;
      char c;
      cin >> t;
      if (t == 1) {
        cin >> idx >> c;
        --idx;
        s[idx] = c;
        updated[idx] = _;
      }
      if (t == 2) {
        cin >> idx >> c;
        seg.update(_, (1 << 0));
      }
      if (t == 3) {
        cin >> idx >> c;
        seg.update(_, (1 << 1));
      }
    }
    // cout << seg << endl;
    // for (int i = 0; i < s.size(); ++i) {
    //   int x = seg.query(updated[i] + 1, q + 1);
    //   cout << s[i] << ' ' << x << ' ' << updated[i] << endl;
    // }
    for (int i = 0; i < s.size(); ++i) {
      int x = seg.query(updated[i] + 1, N);
      if ('A' <= s[i] && s[i] <= 'Z') {
        if (x & (1 << 0)) cout << (char)('a' + (s[i] - 'A'));
        else cout << s[i];
      }
      if ('a' <= s[i] && s[i] <= 'z') {
        if (x & (1 << 1)) cout << (char)('A' + (s[i] - 'a'));
        else cout << s[i];
      }
    }
    cout << endl;
    // break;
  }
  return 0;
}
