// atcoder/abc244/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m, k, s, t, x;
  while (cin >> n >> m >> k >> s >> t >> x) {
    --s;
    --t;
    --x;
    const int N = 2000 + 3;
    vec<int> g[N];

    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    static lli dp[N][N][2]; // dp[長さ][今どこ][偶奇]:=パターン数
    fill(&dp[0][0][0], &dp[N - 1][N - 1][2 - 1] + 1, 0);
    dp[0][s][0] = 1;
    for (int len = 0; len + 1 < N; ++len) {
      for (int curr = 0; curr < n; ++curr) {
        for (int i = 0; i < 2; ++i) {
          each (next, g[curr]) {
            const int j = (i + (next == x)) % 2;
            (dp[len + 1][next][j] += dp[len][curr][i]) %= mod;
          }
        }
      }
    }

    cout << dp[k][t][0] << endl;
  }

  return 0;
}
