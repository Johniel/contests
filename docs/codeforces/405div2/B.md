# codeforces/405div2/B

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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  while (cin >> n >> m) {
    vector<int> g[n];
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    bool f = true;
    set<int> vis;
    for (int src = 0; src < n; ++src) {
      if (vis.count(src)) continue;
      vis.insert(src);
      queue<int> q;
      lli e = 0;
      lli v = 0;
      for (q.push(src); q.size(); q.pop()) {
        ++v;
        each (next, g[q.front()]) {
          ++e;
          if (vis.count(next) == 0) {
            vis.insert(next);
            q.push(next);
          }
        }
      }
      e /= 2;
      f = f && (v * (v - 1) / 2 == e);
    }
    cout << (f ? "YES" : "NO") << endl;
  }
  
  return 0;
}
```
