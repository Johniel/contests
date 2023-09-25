// github.com/Johniel/contests
// codeforces/899div2/C/main.cpp

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
  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;

    const int N = 2 * 1e5 + 3;
    static lli dp[N][2];
    const lli inf = 1LL << 60;
    for (int i = 0; i <= n + 1; ++i) {
      dp[i][0] = dp[i][1] = -inf;
    }
    for (int i = 1; i <= n; ++i) {
      dp[i][(i % 2) ^ 1] = a.at(i - 1);
    }

    // dp[いまどこ][ズレているかどうか]
    for (int i = n; 0 < i; --i) {
      if (i % 2 == 1) {
        if (i + 1 <= n) {
          setmax(dp[i][0], dp[i + 1][1] + a.at(i - 1));
        }
        if (i + 2 <= n) {
          setmax(dp[i][1], dp[i + 2][0]);
          setmax(dp[i][0], dp[i + 2][0] + a.at(i - 1));
        }
      }
      if (i % 2 == 0) {
        if (i + 1 <= n) {
          setmax(dp[i][1], dp[i + 1][0] + a.at(i - 1));
        }
        if (i + 2 <= n) {
          setmax(dp[i][0], dp[i + 2][1]);
          setmax(dp[i][1], dp[i + 2][1] + a.at(i - 1));
        }
      }
      if (i + 2 <= n) {
        setmax(dp[i][0], dp[i + 2][0]);
        setmax(dp[i][1], dp[i + 2][1]);
      }
    }

    if (0) {
      for (int j = 0; j < 2; ++j) {
        for (int i = 0; i <= n; ++i) {
          if (dp[i][j] == -inf) printf("  _ ");
          else printf("%3lld ", dp[i][j]);
        }
        printf("\n");
      }
    }

    lli mx = 0;
    for (int i = 1; i <= n; ++i) {
      setmax(mx, dp[i][0]);
    }
    cout << mx << endl;
  }

  return 0;
}
