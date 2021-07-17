// atcoder/abc210/D/main.cpp
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

const int H = 1000 + 2;
const int W = 1000 + 2;
const lli inf = 1LL << 60;
lli a[H][W];

lli fn(int h, int w, lli c)
{
  static lli dp[H][W];
  fill(&dp[0][0], &dp[H - 1][W - 1] + 1, inf);

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      setmin(dp[i][j], a[i][j]);
      if (i) setmin(dp[i][j], dp[i - 1][j] + c);
      if (j) setmin(dp[i][j], dp[i][j - 1] + c);
    }
  }

  lli mn = inf;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (i) setmin(mn, dp[i - 1][j] + a[i][j] + c);
      if (j) setmin(mn, dp[i][j - 1] + a[i][j] + c);
    }
  }

  return mn;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w;
  lli c;
  while (cin >> h >> w >> c) {
    fill(&a[0][0], &a[H - 1][W - 1] + 1, inf);

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> a[i][j];
      }
    }

    lli mn = fn(h, w, c);
    for (int i = 0; i < h; ++i) {
      vec<int> b;
      for (int j = 0; j < w; ++j) {
        b.push_back(a[i][j]);
      }
      reverse(b.begin(), b.end());
      for (int j = 0; j < w; ++j) {
        a[i][j] = b[j];
      }
    }
    cout << min(mn, fn(h, w, c)) << endl;
  }

  return 0;
}
