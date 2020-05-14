// codeforces/642div3/F/main.cpp
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

  int h, w;
  while (cin >> h >> w) {
    const int N = 100 + 3;
    static lli a[N][N];

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> a[i][j];
        a[i][j] -= i + j;
      }
    }

    const lli inf = 1LL << 60;
    static lli dp[N][N];

    auto fn = [&] (lli z) {
      if (a[0][0] < z) return inf;
      fill(&dp[0][0], &dp[N - 1][N - 1] + 1, inf);
      dp[0][0] = (a[0][0] - z);

      for (int i = 0; i < h; ++i) {
        for (int j = 0; j + 1 < w; ++j) {
          if (z <= a[i][j + 1]) {
            setmin(dp[i][j + 1], dp[i][j] + (a[i][j + 1] - z));
          }
        }
        if (i + 1 < h)
        for (int j = 0; j < w; ++j) {
          if (z <= a[i + 1][j]) {
            setmin(dp[i + 1][j], dp[i][j] + (a[i + 1][j] - z));
          }
        }
      }
      return dp[h - 1][w - 1];
    };

    lli mn = inf;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        setmin(mn, fn(a[i][j]));
      }
    }
    cout << mn << endl;
  }

  return 0;
}
