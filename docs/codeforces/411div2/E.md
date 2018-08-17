# codeforces/411div2/E

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
    vector<int> ice[n];
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      for (int j = 0; j < x; ++j) {
        int y;
        cin >> y;
        ice[i].push_back(y);
      }
    }
    vector<int> g[n];
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    map<int, int> color;
    set<int> used;
    function<void(int, int)> rec = [&] (int curr, int prev) {

      used.clear();
      each (i, ice[curr]) {
        if (color.count(i)) used.insert(color[i]);
      }
      int cnt = 1;
      each (i, ice[curr]) {
        if (color.count(i)) continue;
        while (used.count(cnt)) ++cnt;
        color[i] = cnt++;
      }

      each (next, g[curr]) {
        if (next != prev) rec(next, curr);
      }
      return ;
    };

    rec(0, -1);
    for (int i = 1; i <= m; ++i) {
      color[i] = max(color[i], 1);
    }

    int mx = 0;
    each (c, color) mx = max(mx, c.second);
    cout << mx << endl;
    each (c, color) cout << c.second << ' '; cout << endl;
  }

  return 0;
}
```
