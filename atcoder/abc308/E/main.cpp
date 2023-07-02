// github.com/Johniel/contests
// atcoder/abc308/E/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    str s;
    vec<int> a(n);
    cin >> a >> s;
    const int N = 2 * 1e5 + 3;
    const int STATE = 4;
    const int B = 1 << 4;
    static lli dp[N][STATE][B];
    fill(&dp[0][0][0], &dp[N - 1][STATE - 1][B - 1] + 1, 0);
    const int M = 0;
    const int E = 1;
    const int X = 2;
    const int INI = 3;
    dp[0][INI][0] = 1;
    for (int i = 0; i < s.size(); ++i) {
      for (int bit = 0; bit < B; ++bit) {
        dp[i + 1][INI][bit] += dp[i][INI][bit];
        dp[i + 1][M][bit] += dp[i][M][bit];
        dp[i + 1][E][bit] += dp[i][E][bit];
        dp[i + 1][X][bit] += dp[i][X][bit];
      }
      if (s[i] == 'M') {
        for (int bit = 0; bit < B; ++bit) {
          dp[i + 1][M][bit | (1 << a[i])] += dp[i][INI][bit];
        }
      }
      if (s[i] == 'E') {
        for (int bit = 0; bit < B; ++bit) {
          dp[i + 1][E][bit | (1 << a[i])] += dp[i][M][bit];
        }
      }
      if (s[i] == 'X') {
        for (int bit = 0; bit < B; ++bit) {
          dp[i + 1][X][bit | (1 << a[i])] += dp[i][E][bit];
        }
      }
    }
    lli z = 0;
    for (int bit = 0; bit < B; ++bit) {
      int mex = 0;
      for (int j = 0; j < STATE; ++j) {
        if (bit & (1 << j)) {
          ++mex;
        } else {
          break;
        }
      }
      z += dp[n][X][bit] * mex;
    }
    cout << z << endl;
  }
  return 0;
}
