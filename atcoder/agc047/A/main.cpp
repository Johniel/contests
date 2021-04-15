// atcoder/agc047/A/main.cpp
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
    vec<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      str s;
      cin >> s;
      int idx = s.find('.');
      lli x = 0;
      int _2 = 0;
      int _5 = 0;
      bool f = false;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '.') {
          f = true;
        } else {
          _2 -= f;
          _5 -= f;
          x = x * 10 + s[i] - '0';
        }
      }
      while (x % 2 == 0) {
        ++_2;
        x /= 2;
      }
      while (x % 5 == 0) {
        ++_5;
        x /= 5;
      }
      v.push_back(make_pair(_2, _5));
    }

    const int N = 80;
    static lli g[N][N];
    fill(&g[0][0], &g[N - 1][N - 1], 0);
    each (i, v) {
      ++g[i.first + N / 2][i.second + N / 2];
    }

    lli x = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (g[i][j] == 0) continue;
        for (int a = 0; a < N; ++a) {
          for (int b = 0; b < N; ++b) {
            if (0 <= i + a - N && 0 <= j + b - N) {
              if (i == a && j == b) {
                x += g[i][j] * (g[i][j] - 1);
              } else {
                x += g[i][j] * g[a][b];
              }
            }
          }
        }
      }
    }
    cout << x / 2 << endl;
  }

  return 0;
}
