# atcoder/agc001/C

## Codes
```cpp
#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

const int N = 2000 + 10;
vector<int> g[N];

int diameter(const int root = 0)
{
  function<int(int)> bfs = [&] (int src) {
    queue<int> q;
    map<int, int> cost;
    cost[root] = 0;
    for (q.push(root); q.size(); q.pop()) {
      int curr = q.front();
      each (next, g[curr]) {
        if (!cost.count(next)) {
          cost[next] = cost[curr] + 1;
          q.push(next);
        }
      }
    }
    pair<int, int> x = *max_element(
      cost.begin(),
      cost.end(),
      [] (pair<int, int> a, pair<int, int> b) { return a.second < b.second; })
    ;
    return x.first;
  };
  return bfs(bfs(root));
}

set<int> reachable(int src, int k, int p = -1)
{
  set<int> vis;
  if (p != -1) vis.insert(p);
  function<void(int, int)> rec = [&] (int curr, int depth) {
    vis.insert(curr);
    each (next, g[curr]) {
      if (!vis.count(next) && depth) rec(next, depth - 1);
    }
    return ;
  };
  rec(src, k);
  return vis;
}

int main(int argc, char *argv[])
{
  int n, k;
  while (cin >> n >> k) {
    fill(g, g + N, vector<int>());
    vector<pair<int, int>> es;
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
      es.push_back(make_pair(a, b));
    }
    int mn = 1 << 29;
    if (k % 2) {
      each (e, es) {
        set<int> a = reachable(e.first, k / 2, e.second);
        set<int> b = reachable(e.second, k / 2, e.first);
        int m = n;
        for (int i = 0; i < n; ++i) {
          m -= a.count(i) | b.count(i);
        }
        mn = min<int>(mn, m);
      }
    } else {
      for (int i = 0; i < n; ++i) {
        set<int> x = reachable(i, k / 2);
        mn = min<int>(mn, n - x.size());
      }
    }
    cout << mn << endl;
  }
  return 0;
}
```
