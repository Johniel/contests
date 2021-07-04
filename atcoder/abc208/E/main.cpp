// atcoder/abc208/E/main.cpp
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

  lli n, k;
  while (cin >> n >> k) {
    const vec<int> p = {2, 3, 5, 7};
    vec<int> v[10];
    fill(v, v + 10, vec<int>(p.size(), 0));
    for (int i = 2; i < 10; ++i) {
      int x = i;
      for (int j = 0; j < p.size(); ++j) {
        while (x % p[j] == 0) {
          x /= p[j];
          ++v[i][j];
        }
      }
    }

    const int N = 20;
    const int M2 = 60;
    const int M3 = 38;
    const int M5 = 26;
    const int M7 = 22;

    static lli w[M2][M3][M5][M7];
    fill(&w[0][0][0][0], &w[M2 - 1][M3 - 1][M5 - 1][M7 - 1] + 1, -1);
    w[0][0][0][0] = 1;
    for (int _2 = 0; _2 < M2; ++_2) {
      for (int _3 = 0; _3 < M3; ++_3) {
        for (int _5 = 0; _5 < M5; ++_5) {
          for (int _7 = 0; _7 < M7; ++_7) {
            if (w[_2][_3][_5][_7] == -1) continue;
            if (w[_2][_3][_5][_7] * 2 <= k) w[_2 + 1][_3][_5][_7] = w[_2][_3][_5][_7] * 2;
            if (w[_2][_3][_5][_7] * 3 <= k) w[_2][_3 + 1][_5][_7] = w[_2][_3][_5][_7] * 3;
            if (w[_2][_3][_5][_7] * 5 <= k) w[_2][_3][_5 + 1][_7] = w[_2][_3][_5][_7] * 5;
            if (w[_2][_3][_5][_7] * 7 <= k) w[_2][_3][_5][_7 + 1] = w[_2][_3][_5][_7] * 7;
          }
        }
      }
    }

    static lli dp[2][2][2][2][M2][M3][M5][M7];
    fill(&dp[0][0][0][0][0][0][0][0], &dp[2 - 1][2 - 1][2 - 1][2 - 1][M2 - 1][M3 - 1][M5 - 1][M7 - 1] + 1, 0);
    dp[0][false][false][false][0][0][0][0] = 1;

    const str s = to_string(n);
    for (int i = 0; i < s.size(); ++i) {
      const int curr = i % 2;
      const int next = (curr + 1) % 2;
      for (int started = 0; started < 2; ++started) {
        for (int zero = 0; zero < 2; ++zero) {
          for (int less = 0; less < 2; ++less) {
            for (int _2 = 0; _2 < M2; ++_2) {
              for (int _3 = 0; _3 < M3; ++_3) {
                for (int _5 = 0; _5 < M5; ++_5) {
                  for (int _7 = 0; _7 < M7; ++_7) {
                    dp[next][started][less][zero][_2][_3][_5][_7] = 0;
                  }
                }
              }
            }
          }
        }
      }
      for (int started = 0; started < 2; ++started) {
        for (int zero = 0; zero < 2; ++zero) {
          for (int less = 0; less < 2; ++less) {
            for (int _2 = 0; _2 < M2; ++_2) {
              for (int _3 = 0; _3 < M3; ++_3) {
                for (int _5 = 0; _5 < M5; ++_5) {
                  for (int _7 = 0; _7 < M7; ++_7) {
                    const lli x = dp[curr][started][less][zero][_2][_3][_5][_7];
                    unless (x) continue;
                    for (int c = 0; c <= (less ? 9 : s[i] - '0'); ++c) {
                      dp[next][started || c][less || (c < s[i] - '0')][zero || (started && c == 0)][_2 + v[c][0]][_3 + v[c][1]][_5 + v[c][2]][_7 + v[c][3]] += x;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }

    lli x = 0;
    for (int less = 0; less < 2; ++less) {
      for (int _2 = 0; _2 < M2; ++_2) {
        for (int _3 = 0; _3 < M3; ++_3) {
          for (int _5 = 0; _5 < M5; ++_5) {
            for (int _7 = 0; _7 < M7; ++_7) {
              const int started = true;
              if (w[_2][_3][_5][_7] == -1) {
                x += dp[s.size() % 2][started][less][true][_2][_3][_5][_7];
              } else {
                x += dp[s.size() % 2][started][less][true][_2][_3][_5][_7];
                x += dp[s.size() % 2][started][less][false][_2][_3][_5][_7];
              }
            }
          }
        }
      }
    }
    cout << x << endl;
  }

  return 0;
}
