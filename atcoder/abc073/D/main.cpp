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

constexpr int N = 1e5 + 5;

const int D = log2(N) + 1;
int parent[N][D];
int depth[N];

vector<pair<int, lli>> g[N];

void dfs(int v, int p, int d)
{
  parent[0][v] = p;
  depth[v] = d;
  each (u, g[v]) {
    if (u.first != p) dfs(u.first, v, d + 1);
  }
}
void init(int root, int V)
{
  dfs(root, -1, 0);
  for (int k = 0; k < D; ++k) {
    for (int v = 0; v < V; ++v) {
      if (parent[k][v] < 0) parent[k][v] = -1;
      else parent[k + 1][v] = parent[k][parent[k][v]];
    }
  }
}

int lca(int u, int v)
{
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < D; ++k) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
    }
    if (u == v) return u;
    for (int k = D - 1; 0 <= k; --k) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
  }
  return parent[0][u];
}

lli dist[N];
void rec(int curr, int prev)
{
  each (e, g[curr]) {
    int next = e.first;
    if (next != prev) {
      dist[next] = dist[curr] + e.second;
      rec(next, curr);
    }
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<pair<int, lli>>());
    fill(dist, dist + N, 0);
    for (int i = 0; i < n - 1; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back(make_pair(b, c));
      g[b].push_back(make_pair(a, c));
    }

    int q, k;
    cin >> q >> k;
    --k;

    dist[k] = 0;
    rec(k, k);
    init(k, n);

    while (q--) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      // int z = query(x, y);
      int z = lca(x, y);

      cout << dist[x] + dist[y] << endl;
    }
  }

  return 0;
}
