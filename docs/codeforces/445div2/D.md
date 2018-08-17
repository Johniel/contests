# codeforces/445div2/D

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

  int n;
  while (cin >> n) {
    const int N = 'z' - 'a' + 1;
    set<int> g[N];
    set<int> used;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j + 1 < s.size(); ++j) {
        int src = s[j] - 'a';
        int dst = s[j + 1] - 'a';
        g[src].insert(dst);
      }
      each (c, s) used.insert(c - 'a');
    }

    bool f = false;
    for (int i = 0; i < N; ++i) {
      if (1 < g[i].size()) {
        f = true;
      }
    }
    if (f) {
      cout << "NO" << endl;
      continue;
    }

    int deg[N];
    fill(deg, deg + N, 0);
    for (int i = 0; i < N; ++i) {
      if (g[i].size()) ++deg[*g[i].begin()];
    }

    set<int> vis;
    string s;
    function<void(int)> rec = [&] (int curr) {
      vis.insert(curr);
      s += 'a' + curr;
      each (next, g[curr]) {
        if (vis.count(next)) throw "";
        rec(next);
      }
      return true;
    };

    each (i, used) {
      if (deg[i] == 0) {
        try {
          rec(i);
        } catch (const char* e) {
          s = "NO";
          break;
        }
      }
    }
    cout << (s.size() != used.size() ? "NO" : s) << endl;
  }
  
  return 0;
}
```
