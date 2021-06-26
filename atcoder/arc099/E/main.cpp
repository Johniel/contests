// atcoder/abc099/E/main.cpp
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

const int N = 700 + 3;
vec<int> g[N];
int color[N];
int o = 0;
int z = 0;
void rec(int curr, int prev, int c)
{
  color[curr] = c;
  z += (c == 0);
  o += (c == 1);
  each (next, g[curr]) {
    if (next == prev) continue;
    if (color[next] == c) throw "";
    if (color[next] != -1) continue;
    rec(next, curr, c ^ 1);
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vec<int>());
    fill(color, color + N, -1);
    static bool h[N][N];
    fill(&h[0][0], &h[N - 1][N - 1] + 1, false);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      h[a][b] = h[b][a] = true;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        unless (h[i][j]) {
          g[i].push_back(j);
          g[j].push_back(i);
        }
      }
    }
    try {
      vec<pair<int, int>> v;
      for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
          z = o = 0;
          rec(i, i, 0);
          v.push_back(make_pair(z, o));
        }
      }
      static bool dp[N][N];
      fill(&dp[0][0], &dp[N - 1][N - 1] + 1, false);
      dp[0][0] = true;
      for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < N; ++j) {
          if (j + v[i].first)  dp[i + 1][j + v[i].first]  |= dp[i][j];
          if (j + v[i].second) dp[i + 1][j + v[i].second] |= dp[i][j];
        }
      }
      int mn = 1 << 29;
      for (int i = 0; i < N; ++i) {
        if (dp[v.size()][i]) {
          int j = n - i;
          setmin(mn, i * (i - 1) / 2 + j * (j - 1) / 2);
        }
      }
      cout << mn << endl;
    } catch (const char* e) {
      cout << - 1 << endl;
    }
  }

  return 0;
}
