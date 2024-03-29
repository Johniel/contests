// atcoder/typical90/023/main.cpp
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

  int h, w;
  while (cin >> h >> w) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    str t;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        t += g[i][j];
      }
    }

    const int H = 24;
    const int W = 24;
    const int N = H * W + 3;

    const int X = 1 << 25;
    static int idx[X];
    fill(idx, idx + X, -1);
    int cnt = 0;
    static int v[X];

    static lli dp[2][X];
    fill(&dp[0][0], &dp[2 - 1][X - 1] + 1, 0);
    dp[0][0] = 1;


    idx[cnt] = 0;
    v[0] = cnt;
    ++cnt;

    int mx = 0;
    for (int i = 0; i < h * w; ++i) {
      const int curr = i % 2;
      const int next = (i + 1) % 2;
      for (int j = 0; j < cnt; ++j) {
        dp[next][j] = 0;
      }
      const int size = cnt;
      for (int j = 0; j < size; ++j) {
        if (dp[curr][j] == 0) continue;
        const int bit = v[j];
        {
          int k = (bit >> 1);
          if (idx[k] == -1) {
            v[cnt] = k;
            idx[k] = cnt;
            ++cnt;
          }
          (dp[next][idx[k]] += dp[curr][j]) %= mod;
        }
        {
          bool f = (t[i] == '.');

          if (i % w == 0) {
            f = f && ((bit & 2) == 0);
            f = f && ((bit & 4) == 0);
          } else if (i % w == w - 1) {
            f = f && ((bit & 1) == 0);
            f = f && ((bit & 2) == 0);
            f = f && ((bit & (1 << w)) == 0);
          } else {
            f = f && ((bit & 1) == 0);
            f = f && ((bit & 2) == 0);
            f = f && ((bit & 4) == 0);
            f = f && ((bit & (1 << w)) == 0);
          }
          if (f) {
            int k = (bit >> 1) | (1 << w);
            if (idx[k] == -1) {
              v[cnt] = k;
              idx[k] = cnt;
              ++cnt;
            }
            (dp[next][idx[k]] += dp[curr][j]) %= mod;
          }
        }
      }
    }

    lli z = 0;
    for (int i = 0; i < X; ++i) {
      (z += dp[h * w % 2][i]) %= mod;
    }
    cout << z << endl;
  }

  return 0;
}
