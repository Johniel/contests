// atcoder/abc232/F/main.cpp
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

  int n;
  lli x, y;
  while (cin >> n >> x >> y) {
    vec<int> a(n), b(n);
    cin >> a >> b;
    const int N = 18 + 1;
    const int BIT = 1 << N;
    static lli dp[N][BIT];
    const lli inf = 1LL << 60;
    fill(&dp[0][0], &dp[N - 1][BIT - 1] + 1, inf);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int bit = 0; bit < (1 << n); ++bit) {
        int z = 0;
        for (int j = 0; j < n; ++j) {
          if (bit & (1 << j)) continue;
          lli d = abs(a[i] - b[j]);
          setmin(dp[i + 1][bit | (1 << j)], dp[i][bit] + x * d + y * z);
          ++z;
        }
      }
    }
    cout << dp[n][(1 << n) - 1] << endl;
  }

  return 0;
}
