// atcoder/abc132/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

const int N = 1e5 + 5;
vector<int> g[N];

int bfs(int src, int dst)
{
  static int cost[N][3];
  static bool vis[N][3];
  fill(&cost[0][0], &cost[N - 1][3 - 1] + 1, -3);
  fill(&vis[0][0], &vis[N - 1][3 - 1] + 1, false);
  vis[src][0] = true;
  cost[src][0] = 0;

  queue<pair<int, int>> q;
  for (q.push({src, 0}); q.size(); q.pop()) {
    pair<int, int> p = q.front();
    const int curr = p.first;
    const int x = p.second;
    const int y = (x + 1) % 3;
    each (next, g[curr]) {
      if (vis[next][y]) continue;
      vis[next][y] = true;
      cost[next][y] = cost[curr][x] + 1;
      q.push({next, y});
    }
  }

  return cost[dst][0] / 3;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vector<int>());
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
    }
    int s, t;
    cin >> s >> t;
    cout << bfs(s - 1, t - 1) << endl;
  }
  return 0;
}
