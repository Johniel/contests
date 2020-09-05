// codeforces/667div3/D/main.cpp
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


  str n;
  int sum;
  while (cin >> n >> sum) {
    const int N = 20;
    const int M = 200;
    static ull dp[N][M][2];
    fill(&dp[0][0][0], &dp[N - 1][M - 1][2 - 1] + 1, ULLONG_MAX);
    while (n.size() < 19) {
      n = "0" + n;
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n.size(); ++i) {
      for (int j = 0; j < 190; ++j) {
        for (int k = 0; k < 2; ++k) {
          if (dp[i][j][k] < ULLONG_MAX) {
            for (int add = (k ? 0 : n[i] - '0'); add <= 9; ++add) {
              setmin(dp[i + 1][j + add][k || ((n[i] - '0') < add)], dp[i][j][k] * 10 + add);
            }
          }
        }
      }
    }

    const ull x = stoll(n);
    ull mn = ULLONG_MAX;
    for (int i = 0; i <= sum; ++i) {
      setmin(mn, dp[n.size()][i][0] - x);
      setmin(mn, dp[n.size()][i][1] - x);
    }
    cout << mn << endl;
  }

  return 0;
}
