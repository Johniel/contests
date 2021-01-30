// atcoder/abc190/E/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    vec<int> g[n];
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    int k;
    cin >> k;
    vec<int> c(k);
    cin >> c;
    each (i, c) --i;

    const int K = 17 + 1;
    const int N = 1e5 + 5;
    static int d[K][N];
    const int inf = 1 << 28;
    fill(&d[0][0], &d[K - 1][N - 1], inf);

    for (int i = 0; i < k; ++i) {
      const int src = c[i];
      queue<int> q;
      d[i][src] = 0;
      for (q.push(src); q.size(); q.pop()) {
        int curr = q.front();
        each (next, g[curr]) {
          if (d[i][next] == inf) {
            d[i][next] = d[i][curr] + 1;
            q.push(next);
          }
        }
      }
    }

    const int BIT = 1 << K;
    static int dp[BIT][K];
    fill(&dp[0][0], &dp[BIT - 1][K - 1] + 1, inf);
    dp[0][0] = 0;
    for (int i = 0; i < k; ++i) {
      dp[1 << i][i] = 1;
    }
    for (int bit = 0; bit < (1 << k); ++bit) {
      for (int i = 0; i < k; ++i) {
        unless (bit & (1 << i)) continue;
        if (dp[bit][i] == inf) continue;
        for (int j = 0; j < k; ++j) {
          if (i != j) {
            setmin(dp[bit | (1 << j)][j], dp[bit][i] + d[i][c[j]]);
          }
        }
      }
    }
    int mn = inf;
    for (int i = 0; i < k; ++i) {
      setmin(mn, dp[(1 << k) - 1][i]);
    }
    cout << (mn == inf ? -1 : mn) << endl;
  }

  return 0;
}
