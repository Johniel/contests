// atcoder/typical90/056/main.cpp
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

  int n, s;
  while (cin >> n >> s) {
    vec<pair<int, int>> v(n);
    cin >> v;
    const int N = 100 + 3;
    const int S = 1e5 + 3;;
    static int dp[N][S];
    fill(&dp[0][0], &dp[N - 1][S - 1] + 1, 0);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= s; ++j) {
        if (dp[i][j] == 0) continue;
        if (j + v[i].first <= s) dp[i + 1][j + v[i].first] = +1;
        if (j + v[i].second <= s) dp[i + 1][j + v[i].second] = -1;
      }
    }
    if (dp[n][s] == 0) {
      cout << "Impossible" << endl;
      continue;
    }
    int x = n;
    int idx = s;
    str s;
    while (x) {
      if (dp[x][idx] == -1) {
        s += 'B';
        idx -= v[x - 1].second;
      } else {
        s += 'A';
        idx -= v[x - 1].first;
      }
      --x;
    }
    assert(idx == 0);
    reverse(s.begin(), s.end());
    cout << s << endl;
  }

  return 0;
}
