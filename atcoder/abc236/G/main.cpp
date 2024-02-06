// github.com/Johniel/contests
// atcoder/abc236/G/main.cpp

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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

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
  Matrix<T> c(a.h(), b.w(), 1e9 + 3);
  for (int k = 0; k < a.w(); ++k) {
    for (int i = 0; i < a.h(); ++i) {
      for (int j = 0; j < b.w(); ++j) {
        setmin(c.val[i][j], max(a.val[i][k], b.val[k][j]));
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
  int n, t, l;
  while (cin >> n >> t >> l) {
    const int N = 100;
    Matrix<int> m(N, N);
    const int inf = 1e9 + 3;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        m.val[i][j] = inf;
      }
    }
    for (int _ = 0; _ < t; ++_) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      m.val[a][b] = _ + 1;
    }
    auto x = pow(m, l);
    vec<int> v(n, -1);
    for (int i = 0; i < n; ++i) {
      if (x.val[0][i] < inf) v[i] = x.val[0][i];
    }
    each (i, v) cout << i << ' '; cout << endl;
  }

  return 0;
}
