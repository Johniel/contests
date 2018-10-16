# ARC097 D
整数を頂点とするグラフを考え、交換可能な整数同士に辺を張る。

同じ連結成分になる整数同士は好きなように並べ替えることができる。全ての連結成分で最適に並べ替えた数値を足し合わせれば答えになる。

連結成分の整数と、その整数達のインデックスでいくつ一致しているかをそれぞれカウントする。


## Codes
main.cpp
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
 
  int n, m;
  while (cin >> n >> m) {
    vector<int> v(n);
    each (i, v) {
      cin >> i;
      --i;
    }
 
    vector<pair<int, int>> e(m);
    each (i, e) {
      cin >> i.first >> i.second;
      --i.first;
      --i.second;
    }
    
    UnionFind uf(n);
    each (i, v) uf.make(i);
 
    each (i, e) {
      uf.unite(i.first, i.second);
    }
    for (int i = 0; i < n; ++i) {
      uf.find(i); 
    }
    
    set<int> p[n];
    for (int i = 0; i < n; ++i) {
      p[uf.find(i)].insert(v[i]);
    }
 
    vector<int> idx[n];
    for (int i = 0; i < n; ++i) {
      idx[uf.find(i)].push_back(i);
    }
 
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      each (j, idx[i]) {
        sum += p[i].count(j);
      }
    }
    cout << sum << endl;
  }
  
  return 0;
}
```

---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/arc097/D)
{% endraw %}
