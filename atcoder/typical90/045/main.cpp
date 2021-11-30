// atcoder/typical90/045/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, k;
  while (cin >> n >> k) {
    vec<pair<lli, lli>> v(n);
    cin >> v;

    const int K = 15 + 1;
    const int BIT = 1 << K;

    static lli mx[BIT];
    fill(mx, mx + BIT, 0);
    for (int bit = 0; bit < (1 << n); ++bit) {
      vec<pair<lli, lli>> u;
      for (int i = 0; i < n; ++i) {
        if (bit & (1 << i)) u.push_back(v[i]);
      }
      for (int a = 0; a < u.size(); ++a) {
        for (int b = a + 1; b < u.size(); ++b) {
          lli x = u[a].first - u[b].first;
          lli y = u[a].second - u[b].second;
          setmax(mx[bit], x * x + y * y);
        }
      }
    }

    static lli dp[K][BIT];
    const lli inf = 1LL << 60;
    fill(&dp[0][0], &dp[K - 1][BIT - 1] + 1, inf);
    dp[0][0] = 0;
    for (int i = 0; i < k; ++i) {
      for (int bit = 0; bit < (1 << n); ++bit) {
        const int rev = ((1 << n) - 1) ^ bit;
        for (int A = rev; 0 <= A; --A) {
          A = A & rev;
          if (A == 0) continue;
          int B = rev - A;
          if (__builtin_popcount(A) == 1) {
            setmin(dp[i + 1][bit | A], dp[i][bit]);
          } else {
            setmin(dp[i + 1][bit | A], max(dp[i][bit], mx[A]));
          }
        }
      }
    }

    cout << dp[k][(1 << n) - 1] << endl;
  }

  return 0;
}
