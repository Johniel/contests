// codeforces/710div3/B/main.cpp
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

  int _;
  cin >> _;

  int n, k;
  str s;
  while (cin >> n >> k >> s) {
    int src = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '*') {
        src = i;
        break;
      }
    }
    int dst = src;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '*') dst = i;
    }

    if (src == dst) {
      cout << 1 << endl;
      continue;
    }

    const int N = 53;
    static int dp[N][N];
    const int inf = 1 << 29;
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, inf);
    dp[src + 1][src] = 1;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < s.size(); ++j) {
        if (s[i] == '*') {
          if (i - j <= k) setmin(dp[i + 1][i], dp[i][j] + 1);
          setmin(dp[i + 1][j], dp[i][j]);
        } else {
          setmin(dp[i + 1][j], dp[i][j]);
        }
      }
    }
    cout << dp[s.size()][dst] << endl;
  }

  return 0;
}
