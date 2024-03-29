// github.com/Johniel/contests
// atcoder/abc265/F/main.cpp

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

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  lli d;
  while (cin >> n >> d) {
    vec<lli> a(n), b(n);
    cin >> a >> b;

    const int N = 100 + 3;
    const int D = 1000 + 3;
    static lli dp[2][D][D];
    fill(&dp[0][0][0], &dp[2 - 1][D - 1][D - 1] + 1, 0);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
      int curr = i % 2;
      int next = (curr + 1) % 2;
      for (int j = 0; j < D; ++j) {
        for (int k = 0; k < D; ++k) {
          dp[next][j][k] = 0;
        }
      }
      for (int j = 0; j < D; ++j) {
        for (int k = 0; k < D; ++k) {
          unless (dp[curr][j][k]) continue;
          for (int x = min(a[i], b[i]) - d; x <= max(a[i], b[i]) + d; ++x) {
            if (d < j + abs(a[i] - x)) continue;
            if (d < k + abs(b[i] - x)) continue;
            (dp[next][j + abs(a[i] - x)][k + abs(b[i] - x)] += dp[curr][j][k]) %= mod;
          }
        }
      }
    }
    lli z = 0;
    for (int i = 0; i <= d; ++i) {
      for (int j = 0; j <= d; ++j) {
        (z += dp[n % 2][i][j]) %= mod;
      }
    }
    cout << z << endl;
  }

  return 0;
}
