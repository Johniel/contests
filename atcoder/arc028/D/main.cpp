// github.com/Johniel/contests
// atcoder/arc028/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define makepair(a, b) make_pair(a, b)
// #define endl "\n"

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 1e9 + 7;

// from: https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
template<int MOD> struct Fp {
  long long val;
  constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
    if (val < 0) val += MOD;
  }
  constexpr int getmod() { return MOD; }
  constexpr Fp operator - () const noexcept {
    return val ? MOD - val : 0;
  }
  constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
  constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
  constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
  constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
  constexpr Fp& operator += (const Fp& r) noexcept {
    val += r.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  constexpr Fp& operator -= (const Fp& r) noexcept {
    val -= r.val;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr Fp& operator *= (const Fp& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr Fp& operator /= (const Fp& r) noexcept {
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr bool operator == (const Fp& r) const noexcept {
    return this->val == r.val;
  }
  constexpr bool operator != (const Fp& r) const noexcept {
    return this->val != r.val;
  }
  friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
    return os << x.val;
  }
  friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
    if (n == 0) return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
};
template<int MOD> istream& operator >> (istream& is, Fp<MOD>& m) { is >> m.val; m.val %= MOD; return is; }
template<int MOD> ostream& operator << (ostream& os, const Fp<MOD>& m) { os << m.val; return os; }
using mint = Fp<mod>;

int main(int argc, char *argv[])
{
  int n, m, q;
  while (cin >> n >> m >> q) {
    vec<int> a(n);
    cin >> a;
    vec<pair<int, int>> v(q);
    cin >> v;
    each (i, v) --i.first;

    const int N = 2000 + 3;
    const int M = 2000 + 3;
    static mint dp[N][M];
    fill(&dp[0][0],  &dp[N - 1][M - 1] + 1, mint(0));
    dp[0][0] = mint(1);
    for (int i = 0; i < a.size(); ++i) {
      dp[i + 1][0] = dp[i][0];
      for (int j = 1; j <= m; ++j) {
        // dp[i + 1][j]     = dp[i][j] + dp[i][j - 1] + ... + dp[i][j - a[i]]
        // dp[i + 1][j - 1] =            dp[i][j - 1] + ... + dp[i][j - a[i]] + dp[i][j - a[i] - 1]
        // dp[i + 1][j]     = dp[i][j] + (dp[i + 1][j - 1] - dp[i][j - a[i] - 1])
        // v
        // dp[i][j] = dp[i + 1][j] - (dp[i + 1][j - 1] - dp[i][j - a[i] - 1])
        if (0 <= j - a[i] - 1) {
          dp[i + 1][j] = dp[i][j] + dp[i + 1][j - 1] - dp[i][j - a[i] - 1];
        } else {
          dp[i + 1][j] = dp[i][j] + dp[i + 1][j - 1];
        }
      }
    }
    // dp[iまで見た][j個決めた]=パターン数
    // dp2[i以外を使って][j個決める]=パターン数
    static mint dp2[N][M];
    fill(&dp2[0][0],  &dp2[N - 1][M - 1] + 1, mint(0));
    for (int i = a.size() - 1; 0 <= i; --i) {
      dp2[i][0] = mint(1);
      for (int j = 1; j <= m; ++j) {
        if (0 <= j - a[i] - 1) {
          dp2[i][j] = dp[n][j] - (dp[n][j - 1] - dp2[i][j - a[i] - 1]);
        } else {
          dp2[i][j] = dp[n][j] - dp[n][j - 1];
        }
      }
    }

    each (i, v) {
      cout << dp2[i.first][m - i.second] << endl;
    }
  }
  return 0;
}
