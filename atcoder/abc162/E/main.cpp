// atcoder/abc162/E/main.cpp
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

lli pow(lli n, int p)
{
  if (p == 0) return 1;
  if (p == 1) return n;
  lli m = pow(n, p / 2);
  (m *= m) %= mod;
  if (p%2) (m *= n) %= mod;
  return m;
}

int main(int argc, char *argv[])
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  const int N = 1e5 + 5;

  int n, k;
  while (cin >> n >> k) {
    static lli x[N];
    fill(x, x + N, 0);
    for (int i = k; i; --i) {
      x[i] = ::pow(k / i, n);
      for (lli j = i + i; j <= k; j += i) {
        x[i] -= x[j];
        x[i] = (x[i] + mod) % mod;
      }
    }

    lli sum = 0;
    for (int i = 0; i < N; ++i) {
      (sum += (x[i] * i) % mod) %= mod;
    }
    cout << sum << endl;
  }

  return 0;
}
