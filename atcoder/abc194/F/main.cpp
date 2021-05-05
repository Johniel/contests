// atcoder/abc194/F/main.cpp
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

  str s;
  int kind;
  while (cin >> s >> kind) {
    const int N = 2 * 1e5 + 5;
    const int M = 18;
    static lli dp[N][2][2][M];
    fill(&dp[0][0][0][0], &dp[N - 1][2 - 1][2 - 1][M - 1] + 1, 0);
    dp[0][false][true][0] = 1;

    map<char, int> m;
    str t = "0123456789ABCDEF";
    for (int i = 0; i < t.size(); ++i) {
      m[t[i]] = i;
    }

    set<char> vis;

    for (int i = 0; i < s.size(); ++i) {
      for (int less = 0; less < 2; ++less) {
        for (int prefix = 0; prefix < 2; ++prefix) {
          for (int k = 0; k <= kind; ++k) {
            const lli curr = dp[i][less][prefix][k];
            if (curr == 0) continue;
            if (less) {
              (dp[i + 1][less][prefix][k] += curr * k) %= mod;
              unless (prefix) {
                (dp[i + 1][less][prefix][k + 1] += curr * (16 - k)) %= mod;
              } else {
                (dp[i + 1][less][true][k] += curr) %= mod;
                (dp[i + 1][less][false][k + 1] += curr * (15 - k)) %= mod;
              }
            } else {
              for (int p = 0; p < m[s[i]]; ++p) {
                if (i == 0 && p == 0) {
                  (dp[i + 1][true][true][0] += curr) %= mod;
                } else {
                  (dp[i + 1][true][false][vis.size() + 1 - vis.count(t[p])] += curr) %= mod;
                }
              }
            }
          }
        }
      }
      const int prev = vis.size();
      vis.insert(s[i]);
      if (i) {
        dp[i + 1][false][false][vis.size()] += dp[i][false][false][prev];
      } else {
        dp[i + 1][false][false][vis.size()] += dp[i][false][true][prev];
      }
    }

    lli x = 0;
    x += dp[s.size()][true][false][kind];
    x += dp[s.size()][false][false][kind];
    cout << x % mod << endl;
  }
  return 0;
}
