// codeforces/644div3/E/main.cpp
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

  int n;
  while (cin >> n) {
    char g[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][j] == '0') continue;
        if (i == n - 1 || j == n - 1) {
          q.push({i, j});
          g[i][j] = '@';
        }
      }
    }
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      int i = p.first;
      int j = p.second;
      for (int d = 0; d < 2; ++d) {
        int ni = i - di[d];
        int nj = j - dj[d];
        unless (0 <= ni && ni < n) continue;
        unless (0 <= nj && nj < n) continue;
        if (g[ni][nj] == '1') {
          q.push({ni, nj});
          g[ni][nj] = '@';
        }
      }
    }

    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < n; ++j) {
    //     cout << g[i][j];
    //   }
    //   cout << endl;
    // }

    cout << (count(&g[0][0], &g[n - 1][n - 1] + 1, '1') == 0 ? "YES" : "NO") << endl;
  }

  return 0;
}
