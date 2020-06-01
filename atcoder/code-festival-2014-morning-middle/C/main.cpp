// atcoder/code-festival-2014-morning-middle/C/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

using M = array<array<__float128, 2>, 2>;

M operator * (M a, M b)
{
  M c;
  c[0][0] = c[1][0] = c[0][1] = c[1][1] = 0;
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  c[0][1] = c[1][0] = 1.0 - c[0][0];
  return c;
}

M f(M m, lli p)
{
  if (p == 1) return m;
  if (p == 2) return m * m;

  M n = f(m, p/2);
  n = n * n;
  if (p%2) n = n * m;
  return n;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  double p;
  lli n;
  while (cin >> p >> n) {
    M m;
    m[0][0] = 1.0 - p;
    m[0][1] = p;
    m[1][0] = p;
    m[1][1] = 1.0 - p;
    m = f(m, n);
    cout << 1.0 - (double)m[0][0] << endl;
  }

  return 0;
}
