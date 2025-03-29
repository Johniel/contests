// github.com/Johniel/contests
// atcoder/abc399/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
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

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

namespace math {
  const int N = 2 * 1e5 + 3;

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

  lli mod_comb(int n, int k)
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
struct PrefixSum {
  vector<T> sum;
  PrefixSum(vector<T> v) {
    sum.push_back(0);
    for (int i = 0; i < v.size(); ++i) {
      sum.push_back((sum.back() + v[i] % mod) % mod);
    }
  }
  T operator () (size_t begin, size_t end) const {
    assert(begin <= end);
    return (sum[end] - sum[begin] + mod) % mod;
  }
  T operator () (size_t end) const {
    return (*this)(0, end);
  }
  size_t size(void) const { return (int)sum.size() - 1; }
};

int main(int argc, char *argv[])
{
  math::init();
  lli n, k;
  while (cin >> n >> k) {
    vec<lli> a(n);
    cin >> a;

    PrefixSum<lli> sum(a);
    lli g[n + 1][k + 1];
    for (int i = 0; i <= n; ++i) {
      for (int d = 0; d <= k; ++d) {
        g[i][d] = math::mod_pow(sum(0, i), d);
      }
    }
    lli g2[n + 1][k + 1];
    for (int i = 0; i < n + 1; ++i) {
      for (int j = 0; j < k + 1; ++j) {
        g2[i][j] = g[i][j];
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= k; ++j) {
        (g2[i + 1][j] += g2[i][j]) %= mod;
      }
    }
    // for (int i = 0; i < n+1; ++i) {
    //   for (int j = 0; j < k+1; ++j) {
    //     cout << g[i][j] << ' ';
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < n+1; ++i) {
    //   for (int j = 0; j < k+1; ++j) {
    //     cout << g2[i][j] << ' ';
    //   }
    //   cout << endl;
    // }
    // cout << endl;

    vec<PrefixSum<lli>> sum2;
    for (int i = 0; i < n + 1; ++i) {
      vec<lli> a;
      for (int j = 0; j < k + 1; ++j) {
        a.push_back(g[i][j]);
      }
      sum2.push_back(PrefixSum<lli>(a));
    }

    lli z = 0;
    for (int j = 0; j < n; ++j) {
      vec<lli> v(k+1, 0);
      v[0] = 1;
      lli p = 0;
      //for (int m = k; 0 <= m; --m) {
      for (int m = 0; m <= k; ++m) {
        const lli c = math::mod_comb(k, m);
        lli x = math::mod_pow(sum(0, j+1), m);
        // lli y = sum2[k - m](0, j + 1);
        lli y = g2[j][k - m];
        x = (x * y) % mod;
        if ((k - m) % 2) x = mod - x;
        // if (m % 2) x = mod - x;
        // cout << make_pair(j, m) << x << endl;
        //cout << j << ' ' << m << ", " << g[j + 1][m] <<" * " << y << endl;
        (z += c * x % mod) %= mod;
        (p += c * x % mod) %= mod;
      }
      for (int m = 0; m <= k; ++m) {
        // const lli c = math::mod_comb(k, m);
        // lli x = g[j + 1][m] * v[k - m] % mod;
        // if ((k - m) % 2) x = mod - x;
        // if (m % 2) x = mod - x;
        // (v[m] += x) %= mod;
        (v[k - m] += g[j + 1][k - m]) %= mod;
      }
      // cout << make_pair(j, p) << z << endl;
    }
    cout << z << endl;
    // break;
  }
  return 0;
}
