// github.com/Johniel/contests
// atcoder/abc431/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 998244353; // 1e9 + 7;

const int N = 1e6 + 3;

namespace math {
  lli fact[N], finv[N], inv[N];

  void init(void)
  {
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < N; i++){
      fact[i] = fact[i - 1] * i % mod;
      inv[i] = mod - inv[mod % i] * (mod / i) % mod;
      finv[i] = finv[i - 1] * inv[i] % mod;
    }
    return ;
  }

  lli mod_comb(int n, int k)  // 必要に応じてlucasの定理を使うこと
  {
    assert(n < N && k < N);
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fact[n] * (finv[k] * finv[n - k] % mod) % mod;
  }

  inline long long int nCk(int n, int k) { return mod_comb(n, k); }

  // n個の箱にm個の何かを分配する場合の数
  inline long long int nHm(int n, int m) { return nCk(n + m - 1, m); }

  // ∑{k=0...n} pCk * qC(n-k) = (p+q)Cn ※ p<k && pCk=0
  // https://manabitimes.jp/math/622
  inline long long int vandermonde_convolution(int p, int q, int n) { return nCk(p + q, n); }
};

namespace math {
  // gcd(a,b)を返す。xとyにはax+by=±gcd(a,b)を満たす数を設定する。
  lli extgcd(lli a, lli b, lli& x, lli& y)
  {
    lli g = a;
    x = 1;
    y = 0;
    if (b != 0) {
      g = extgcd(b, a % b, y, x);
      y -= (a / b) * x;
    }
    return g;
  }

  lli mod_inverse(lli a, lli m)
  {
    lli x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
  }

  lli mod_pow(lli n, lli p, lli M = mod)
  {
    if (p == 0) return 1;
    if (p == 1) return n % M;
    lli m = mod_pow(n, p / 2, M);
    m *= m;
    m %= M;
    if (p % 2) m = (m * n) % M;
    return m;
  }
};

template<typename T>
struct SegTree {
  // https://codeforces.com/blog/entry/18051
  using F = function<T(T, T)>;
  const F op;
  const T e;
  const int n;
  const int bitceiln;
  vector<T> v;
  SegTree(size_t n_, T e_, F op_) : e(e_), n(n_), op(op_), bitceiln(__bit_ceil(n)) {
    assert(op(e, e) == e);
    v.resize(2 * bitceiln, e);
  }
  SegTree(const vector<T>& v, T e_, F op_) : SegTree(v.size(), e_, op_) {
    for (size_t i = 0; i < v.size(); ++i) set(i, v[i]);
  }
  void set(size_t k, T a) {
    assert(k < n);
    for (v[k += bitceiln] = a; k >>= 1; v[k] = op(v[k * 2], v[k * 2 + 1])) ;
  }
  T get(size_t k) const { assert(k < n); return v[k + bitceiln]; }
  T operator () (void) const { return v.at(1); }
  T operator () (size_t begin, size_t end) { return query(begin, end); }
  T all_prod(void) const { return v.at(1); }
  T query(void) const { return v.at(1); }
  T prod(size_t begin, size_t end) const { return query(begin, end); }
  T query(size_t l, size_t r) {
    assert(0 <= l && l <= r && r <= n);
    T L = e, R = e;
    for (l += bitceiln, r += bitceiln; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = op(L, v[l++]);
      if (r & 1) R = op(v[--r], R);
    }
    return op(L, R);
  }
  size_t size(void) const { return n; }
};
template<typename T> istream& operator >> (istream& is, SegTree<T>& seg) { for (size_t i = 0; i < seg.size(); ++i) { T t; is >> t; seg.set(i, t); } return is; }
template<typename T> ostream& operator << (ostream& os, SegTree<T>& seg) { os << seg.v; return os; }


int main(int argc, char *argv[])
{
  math::init();

  int n;
  int d;
  while (cin >> n >> d) {
    vec<int> a(n);
    cin >> a;
    sort(a.begin(), a.end());

    lli z = 1;
    for (int i = 0; i < a.size(); ++i) {
      auto itr = lower_bound(a.begin(), a.end(), a[i] + d + 1);
      lli cand = itr - (a.begin() + i);
      // cout << cand << endl;
      (z *= cand) %= mod;
    }

    map<int, int> m;
    each (i, a) ++m[i];

    each (k, m) {
      (z *= math::mod_inverse(math::fact[k.second], mod)) %= mod;
    }

    cout << z << endl;
  }



  return 0;
}
