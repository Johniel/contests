// github.com/Johniel/contests
// codeforces/e139/C/main.cpp

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  int w;
  while (cin >> w) {

    const int h = 2;
    const int N = 2 * 1e5 + 3;
    static char g[h][N];

    int b = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
        if (g[i][j] == 'B') ++b;
      }
    }
    g[0][w] = g[1][w] = 'W';


    static int dp[h][N];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j <= w; ++j) {
        dp[i][j] = (g[i][j] == 'B');
      }
    }

    bool f = true;
    for (int j = 0; j < w; ++j) {
      if (g[0][j] == 'B' && g[1][j] == 'B') {
        if (g[0][j + 1] == 'B') setmax(dp[0][j + 1], dp[1][j] + 2);
        if (g[1][j + 1] == 'B') setmax(dp[1][j + 1], dp[0][j] + 2);
        int x = dp[0][j];
        int y = dp[1][j];
        setmax(dp[0][j], y + 1);
        setmax(dp[1][j], x + 1);
      }
      if (g[0][j] == 'B' && g[1][j] == 'W') {
        if (g[0][j + 1] == 'B') setmax(dp[0][j + 1], dp[0][j] + 1);
      }
      if (g[0][j] == 'W' && g[1][j] == 'B') {
        if (g[1][j + 1] == 'B') setmax(dp[1][j + 1], dp[1][j] + 1);
      }
      if (g[0][j] == 'W' && g[1][j] == 'W') f = false;
    }
    int mx = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        setmax(mx, dp[i][j]);
      }
    }
    cout << ((f && b == mx) ? "YES" : "NO") << endl;
  }

  return 0;
}
