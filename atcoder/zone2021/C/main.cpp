// atcoder/zone2021/C/main.cpp
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

  int n;
  while (cin >> n) {
    int a[n];
    int b[n];
    int c[n];
    int d[n];
    int e[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
    }

    const int N = 3000 + 3;
    const int BIT = (1 << 5);
    static bool dp[N][4][BIT];

    auto fn = [&] (int mn) {
      fill(&dp[0][0][0], &dp[N - 1][4 - 1][BIT - 1] + 1, false);
      dp[0][0][0] = true;

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
          for (int bit = 0; bit < BIT; ++bit) {
            dp[i + 1][j][bit] |= dp[i][j][bit];

            int x = 0;
            if (mn <= a[i]) x |= (1 << 0);
            if (mn <= b[i]) x |= (1 << 1);
            if (mn <= c[i]) x |= (1 << 2);
            if (mn <= d[i]) x |= (1 << 3);
            if (mn <= e[i]) x |= (1 << 4);
            dp[i + 1][j + 1][bit | x] |= dp[i][j][bit];
            dp[i + 1][3][bit] |= dp[i][3][bit];
          }
        }
      }
      return dp[n][3][BIT - 1];
    };

    int small = 0;
    int large = 1e9 + 1;
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if (fn(mid)) small = mid;
      else large = mid;
    }

    if (fn(large)) cout << large << endl;
    else if (fn(small)) cout << small << endl;
    else cout << 0 << endl;
  }

  return 0;
}
