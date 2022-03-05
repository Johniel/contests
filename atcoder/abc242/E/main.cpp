// atcoder/abc242/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int n;
  str s;
  while (cin >> n >> s) {
    const int N = 1e6 + 3;
    const int M = 3;
    static lli dp[N][M][M];
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j < M; ++j) {
        for (int k = 0; k < M; ++k) {
          dp[i][j][k] = 0;
        }
      }
    }
    const int L = 0;
    const int EQ = 1;
    const int G = 2;
    dp[0][EQ][EQ] = 1;
    for (int i = 0; i < (s.size() + 1) / 2; ++i) {
      const int j = s.size() - i - 1;

      // if (j >= (s.size()+1)/2) cout << i << "th " << s[i] << ' ' << s[j] << endl;
      // else cout << i << "th " << s[i] << " _" << endl;

      for (int pref = 0; pref < 2; ++pref) {
        for (int suff = 0; suff < 3; ++suff) {
          for (char c = 'A'; c <= ((pref == L) ? 'Z' : s[i]); ++c) {

            int a = pref;
            if (a == EQ) {
              if (s[i] > c) a = L;
              // if (s[i] < c) a = G;
              if (s[i] < c) assert(false);
            }

            int b = suff;
            if (j >= (s.size()+1)/2) {
              if (s[j] > c) b = L;
              if (s[j] < c) b = G;
            }
            // cout << i+1 << ' ' << a << ' ' << b << " += " << dp[i][pref][suff] << endl;
            (dp[i + 1][a][b] += dp[i][pref][suff]) %= mod;
          }
        }
      }
    }
    lli z = 0;
    for (int a = 0; a < 3; ++a) {
      for (int b = 0; b < 3; ++b) {
        const int i = (s.size() + 1) / 2;
        if (a == L || (a == EQ && b == EQ) || (a == EQ && b == L)) {
          // cout << make_pair(a, b) << ' ' << dp[(s.size() + 1) / 2][a][b] << endl;
          (z += dp[i][a][b]) %= mod;
        }
      }
    }
    cout << z << endl;
    // break;
  }

  return 0;
}
