// github.com/Johniel/contests
// atcoder/abc445/F/main.cpp

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

template<typename T>
struct Matrix {
  vector<vector<T>> val;
  Matrix() {}
  Matrix(int h, int w) { val.resize(h, vector<T>(w)); }
  Matrix(int h, int w, T e) { val.resize(h, vector<T>(w, e)); }
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
  Matrix<T> c(a.h(), b.w(), 1LL << 60);
  for (int k = 0; k < a.w(); ++k) {
    for (int i = 0; i < a.h(); ++i) {
      for (int j = 0; j < b.w(); ++j) {
        // c.val[i][j] += a.val[i][k] * b.val[k][j];
        setmin(c.val[i][j], a.val[i][k] + b.val[k][j]);
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

int main(int argc, char *argv[])
{
  int n;
  lli k;
  while (cin >> n >> k) {
    Matrix<lli> m(n, n, 1LL << 60);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> m.val[i][j];
      }
    }
    Matrix<lli> x = pow(m, k);
    for (int i = 0; i < n; ++i) {
      cout << x.val[i][i] << endl;
      // lli z = 0;
      // for (int j = 0; j < n; ++j) {
      //   z += x.val[i][j];
      // }
      // cout << z << endl;
    }
  }
  return 0;
}
