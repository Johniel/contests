// atcoder/arc027/C/main.cpp
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

  int x, y, n;
  while (cin >> x >> y >> n) {
    vec<pair<int, int>> v(n);
    cin >> v;

    const int N = 300 + 3;
    static lli dp[N][N][N];
    fill(&dp[0][0][0], &dp[N - 1][N - 1][N - 1] + 1, -(1LL << 60));
    dp[0][x][y] = 0;

    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j <= x; ++j) {
        for (int k = 0; k <= y; ++k) {
          if (dp[i][j][k] < 0) continue;
          setmax(dp[i + 1][j][k], dp[i][j][k]);
          if (j && v[i].first <= j + k) {
            int z = min(k, v[i].first - 1);
            setmax(dp[i + 1][j - (v[i].first - z)][k - z], dp[i][j][k] + v[i].second);
          }
        }
      }
    }
    cout << *max_element(&dp[0][0][0], &dp[N - 1][N - 1][N - 1] + 1) << endl;
  }

  return 0;
}
