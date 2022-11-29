// github.com/Johniel/contests
// atcoder/abc199/F/main.cpp

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

template<typename T>
struct Matrix {
  vector<vector<T>> val;
  Matrix() {}
  Matrix(int h, int w) { val.resize(h, vector<T>(w)); }
  size_t h(void) const { return val.size(); }
  size_t w(void) const { return val.empty() ? 0 : val[0].size(); }
  Matrix<T> e(void) const {
    Matrix<T> m;
    m.val = val;
    for (int i = 0; i < h(); ++i) {
      for (int j = 0; j < w(); ++j) {
        m.val[i][j] = (i == j);
      }
    }
    return m;
  }
};

template<typename T>
istream& operator >> (istream& is, Matrix<T>& m)
{
  for (int i = 0; i < m.h(); ++i) {
    for (int j = 0; j < m.w(); ++j) {
      is >> m.val[i][j];
    }
  }
  return is;
}

template<typename T> ostream& operator << (ostream& os, const Matrix<T>& m) { os << m.val; return os; }

template<typename T>
Matrix<T> operator * (const Matrix<T>& a, const Matrix<T>& b)
{
  assert(a.w() == b.h());
  Matrix<T> c(a.h(), b.w());
  for (int k = 0; k < a.w(); ++k) {
    for (int i = 0; i < a.h(); ++i) {
      for (int j = 0; j < b.w(); ++j) {
        c.val[i][j] += a.val[i][k] * b.val[k][j];
      }
    }
  }
  return c;
}

template<typename T>
Matrix<T> pow(Matrix<T> m, long long int p)
{
  if (p == 0) return m.e();
  if (p == 1) return m;
  Matrix<T> n = pow(m, p / 2);
  n = n * n;
  if (p % 2) n = n * m;
  return n;
}

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
  int n, m, k;
  while (cin >> n >> m >> k) {
    Matrix<mint> a(n, 1);
    cin >> a;
    vec<int> g[n];
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    Matrix<mint> x(n, n);
    for (int i = 0; i < n; ++i) {
      x.val[i][i] = mint(1);
      each (j, g[i]) {
        x.val[i][i] -= mint(1) / mint(m * 2); // 1/mで半分に減る
        x.val[i][j] += mint(1) / mint(m * 2); // 1/mで半分あげる
      }
    }
    a = pow(x, k) * a;
    for (int i = 0; i < n; ++i) {
      cout << a.val[i][0] << endl;
    }
  }
  return 0;
}
