// codeforces/713div3/B/main.cpp
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
    int mn_i = 1 << 29;
    int mn_j = 1 << 29;
    int mx_i = -1;
    int mx_j = -1;
    char g[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
        if (g[i][j] == '*') {
          setmin(mn_i, i);
          setmin(mn_j, j);
          setmax(mx_i, i);
          setmax(mx_j, j);
        }
      }
    }

    if (mn_i == mx_i) {
      if (mn_i) --mn_i;
      else ++mx_i;
    }
    if (mn_j == mx_j) {
      if (mn_j) --mn_j;
      else ++mx_j;
    }

    g[mn_i][mn_j] = g[mn_i][mx_j] = g[mx_i][mn_j] = g[mx_i][mx_j] = '*';
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << g[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}
