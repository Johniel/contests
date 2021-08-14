// atcoder/abc207/F/main.cpp
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

const int N = 2000 + 5;

vec<int> g[N];

const int M = 4;
lli dp[N][N][M];
int sz[N];
const int C = 1;
const int P = 2;
const int F = 0;
void rec(int curr, int prev)
{
  lli x[N][M] = {};
  x[0][0] = x[1][2] = 1;
  sz[curr] = 1;

  each (next, g[curr]) {
    if (next == prev) continue;
    rec(next, curr);
    lli y[N][M] = {};
    for (int i = 0; i <= sz[curr]; ++i) {
      for (int j = 0; j <= sz[next]; ++j) {
        (y[i + j + 1][P] += x[i][P] * dp[next][j][F]) %= mod;
        (y[i + j][P] += x[i][P] * (dp[next][j][C] + dp[next][j][P])) %= mod;
        (y[i + j][C] += x[i][C] * (dp[next][j][F] + dp[next][j][P] + dp[next][j][C])) %= mod;
        (y[i + j + 1][C] += x[i][F] * dp[next][j][P]) %= mod;
        (y[i + j][F] += x[i][F] * (dp[next][j][F] + dp[next][j][C])) %= mod;
      }
    }
    sz[curr] += sz[next];
    swap(x, y);
  }
  for (int i = 0; i < N; ++i) {
    dp[curr][i][P] = x[i][P];
    dp[curr][i][C] = x[i][C];
    dp[curr][i][F] = x[i][F];
  }

  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    fill(&dp[0][0][0], &dp[N - 1][N - 1][4 - 1] + 1, 0);
    fill(g, g + N, vec<int>());
    fill(sz, sz + N, 0);
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    rec(0, 0);
    for (int i = 0; i <= n; ++i) {
      cout << (dp[0][i][F] + dp[0][i][P] + dp[0][i][C]) % mod << endl;
    }
  }

  return 0;
}
