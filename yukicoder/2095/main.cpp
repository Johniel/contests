// github.com/Johniel/contests
// yukicoder/2095/main.cpp

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

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w;
  while (cin >> h >> w) {
    const int H = 1000 + 3;
    const int W = 1000 + 3;

    static lli a[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> a[i][j];
      }
    }

    if (h == 1) {
      cout << 0 << endl;
      continue;
    }

    static lli dp[H][W];
    const lli inf = 1LL << 60;
    fill(&dp[0][0], &dp[H - 1][W - 1] + 1, inf);
    for (int j = 0; j < w; ++j) {
      dp[0][j] = 0;
    }
    for (int i = 0; i < h; ++i) {
      lli mn = inf;
      for (int j = 0; j < w; ++j) {
        lli x = dp[i][j] + a[i][j];
        setmin(mn, x);
        setmin(dp[i + 1][j], x);
      }
      for (int j = 0; j < w; ++j) {
        setmin(dp[i + 1][j], mn + a[i][j]);
      }
    }

    lli z = inf;
    for (int j = 0; j < w; ++j) {
      setmin(z, dp[h][j]);
    }
    cout << z << endl;
  }

  return 0;
}
