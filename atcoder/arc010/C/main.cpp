// atcoder/arc010/C/main.cpp
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
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  int n, m;
  lli y, z;
  while (cin >> n >> m >> y >> z) {
    map<char, lli> score;
    for (int i = 0; i < m; ++i) {
      char c;
      lli x;
      cin >> c >> x;
      score[c] = x;
    }

    str s;
    cin >> s;

    map<char, int> idx;
    each (c, s) {
      if (idx.count(c) == 0) {
        int size = idx.size();
        idx[c] = size;
      }
    }

    const lli inf = 1LL << 60;
    const int C = 11;
    const int BIT = 1 << C;
    static lli dp[2][BIT][C];
    fill(&dp[0][0][0], &dp[2 - 1][BIT - 1][C - 1] + 1, -inf);
    dp[0][0][m] = 0;

    for (int i = 0; i < s.size(); ++i) {
      const int curr = i % 2;
      const int next = (curr + 1) % 2;
      for (int j = 0; j < BIT; ++j) {
        for (int k = 0; k < C; ++k) {
          dp[next][j][k] = -inf;
        }
      }

      for (int bit = 0; bit < (1 << m); ++bit) {
        for (int prev = 0; prev < C; ++prev) {
          const int j = idx[s[i]];
          const int b = (bit | (1 << j));
          if (prev == j) {
            setmax(dp[next][b][j], dp[curr][bit][prev] + y + score[s[i]]);
          } else {
            setmax(dp[next][b][j], dp[curr][bit][prev] + score[s[i]]);
          }
          setmax(dp[next][bit][prev], dp[curr][bit][prev]);
        }
      }
    }

    lli mx = -inf;
    for (int bit = 0; bit < (1 << m) - 1; ++bit) {
      for (int j = 0; j < C; ++j) {
        setmax(mx, dp[s.size() % 2][bit][j]);
      }
    }

    const int B = (1 << m) - 1;
    for (int j = 0; j < C; ++j) {
      setmax(mx, dp[s.size() % 2][B][j] + z);
    }

    cout << mx << endl;
  }


  return 0;
}
