# codeforces/395div2/C

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

const int inf = 1 << 28;

class UnionFind {
public:
  vector<int> rank, p;
  UnionFind(int size)
  {
    rank.resize(size, -inf);
    p.resize(size, -inf);
  }
  void make(int a)
  {
    rank[a] = 0;
    p[a] = a;
  }
  void unite(int a, int b)
  {
    link(find(a), find(b));
  }
  int find(int a)
  {
    return (a == p[a]) ? a : p[a] = find(p[a]);
  }
  bool isSameSet(int a, int b)
  {
    return find(a) == find(b);
  }
  void link (int a, int b)
  {
    if (rank[a] > rank[b]) {
      p[b] = a;
    } else {
      p[a] = b;
      if(rank[a] == rank[b]) rank[b]++;
    }
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<pair<int, int>> es;
    int c[n];
    vector<int> g[n];
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      es.push_back(make_pair(a, b));
      g[a].push_back(b);
      g[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
      cin >> c[i];
    }
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
      uf.make(i);
    }
    each (e, es) {
      if (c[e.first] == c[e.second]) {
        uf.unite(e.first, e.second);
      }
    }
    for (int i = 0; i < n; ++i) {
      uf.find(i);
    }
    set<int> r;
    for (int i = 0; i < n; ++i) {
      r.insert(uf.find(i));
    }
    int z = -1;
    for (int i = 0; i < n; ++i) {
      set<int> x;
      x.insert(uf.find(i));
      each (j, g[i]) {
        x.insert(uf.find(j));
      }
      if (r == x) {
        z = i;
        break;
      }
    }
    if (z == -1) cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      cout << z + 1 << endl;
    }
  }
  
  return 0;
}
```
