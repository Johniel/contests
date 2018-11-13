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

const int N = 3 * 1e5 + 10;
vector<int> g[N];
vector<int> h[N];
lli dist[N];
int parent[N];
bool vis[N];
const lli inf = 1LL << 60;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  while (cin >> n >> m >> k) {
    fill(g, g + N, vector<int>());
    fill(h, h + N, vector<int>());
    fill(dist, dist + N, inf);
    fill(vis, vis + N, false);
    fill(parent, parent + N, -1);

    map<pair<int, int>, lli> cost;
    map<pair<int, int>, int> name;

    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);

      auto x = make_pair(a, b);
      auto y = make_pair(b, a);
      cost[x] = cost[y] = c;
      name[x] = name[y] =  i;
    }

    priority_queue<pair<lli, int>> q;
    dist[0] = 0;
    q.push({0, 0});

    while (q.size()) {
      auto p = q.top();
      q.pop();
      auto C = -1 * p.first;
      auto curr = p.second;
      if (dist[curr] != C) continue;
      each (next, g[curr]) {
        auto e = make_pair(curr, next);
        if (dist[next] > dist[curr] + cost[e]) {
          dist[next] = dist[curr] + cost[e];
          q.push({-dist[next], next});
          parent[next] = curr;
        }
      }
    }

    for (int i = 0; i < N; ++i) {
      if (parent[i] != -1) {
        h[parent[i]].push_back(i);
      }
    }

    vector<int> u;
    {
      queue<int> q;
      vis[0] = true;
      for (q.push(0); q.size(); q.pop()) {
        int curr = q.front();
        each (next, h[curr]) {
          if (vis[next]) continue;
          q.push(next);
          vis[next] = true;
          auto e = make_pair(curr, next);
          u.push_back(name[e]);
        }
      }
    }

    while (k < u.size()) u.pop_back();
    cout << u.size() << endl;
    each (i, u) cout << i + 1 << ' '; cout << endl;
  }

  return 0;
}
