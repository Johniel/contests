# codeforces/326div2/E

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

const int N = 100000 + 10;
vector<int> c[N];

namespace LCA {
  const int NODE = 100000 + 10;
  const int DEPTH = 18;

  int doubling[NODE][DEPTH], parent[NODE], level[NODE];

  int addLevel(int node)
  {
    return (level[node] != -1) ? level[node] : (level[node] = addLevel(parent[node]) + 1);
  }

  vector<int> C[NODE][DEPTH];
  
  void fn(vector<int>& a, vector<int>& b)
  {
    // cout << "("; each (i, a) cout << i << ", "; cout << ")"; cout << "  +  ";
    // cout << "("; each (i, b) cout << i << ", "; cout << ")"; cout << " = ";
    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    while (10 < a.size()) a.pop_back();
    // cout << "("; each (i, a) cout << i << ", "; cout << ")"; cout << endl;
    return ;
  }  

  void build(const int &node, const int root = 0)
  {
    fill(&C[0][0], &C[NODE - 1][DEPTH - 1] + 1, vector<int>());
    
    fill(level, level + node, -1);
    level[root] = 0;
    for (int i = 0; i < node; ++i) {
      level[i] = addLevel(i);
    }

    fill(&doubling[0][0], &doubling[NODE - 1][DEPTH], -1);
    for (int i = 0; i < node; ++i) {
      doubling[i][0] = parent[i];
      // fn(C[i][0], c[parent[i]]);
      fn(C[i][0], c[i]);
    }
    for(int j = 1; (1 << j) < node; ++j){
      for (int i = 0; i < node; ++i) {
        const int p = doubling[i][j - 1];
        if (p != -1) {
          doubling[i][j] = doubling[p][j - 1];
          fn(C[i][j], C[p][j - 1]);
          fn(C[i][j], C[i][j - 1]);
        }
      }
    }
    

    // for(int j = 0; (1 << j) < node; ++j){
    //   for (int i = 0; i < node; ++i) {
    //     if (C[i][j].empty()) continue;
    //     cout << i+1 << "-th, 2^" << j << endl;
    //     each (k, C[i][j]) cout << k << ' ';
    //     cout << endl;
    //   }
    // }
   

    return ;
  }
  
  vector<int> query(int a, int b)
  {
    // cout << string(50, '#') << endl;
    
    vector<int> v;
    if (level[a] < level[b]) swap(a, b);

    int lg = 1;
    while ((1 << lg) <= level[a]) ++lg;
    --lg;
    
    fn(v, c[a]);
    fn(v, c[b]);
    
    // cout << ">> " << a+1 << ' ' << b+1 << endl;
    
    for (int i = lg; 0 <= i; --i) {
      if (level[a] - (1 << i) >= level[b]) {
        fn(v, C[a][i]);
        a = doubling[a][i];
      }
    }
    
    // cout << ">> " << a+1 << ' ' << b+1 << endl;
    // cout << "ini : " ;each (i, v) cout << i << ' ' ; cout << endl;
    
    if (a == b) return v;
    for (int i = lg; 0 <= i; --i) {
      if (doubling[a][i] != -1 && doubling[a][i] != doubling[b][i]) {
        a = doubling[a][i];
        b = doubling[b][i];
        fn(v, C[a][i]);
        fn(v, C[b][i]);
      }
    }
    fn(v, c[parent[a]]);
    // return parent[a];
    return v;
  }
};

int main(int argc, char *argv[])
{
  int n, m, q;
  while (scanf("%d%d%d", &n, &m, &q) == 3) {
    vector<int> g[N];
    fill(c, c + N, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    fill(c, c + N, vector<int>());
    for (int i = 0; i < m; ++i) {
      int a;
      scanf("%d", &a);
      c[a - 1].push_back(i + 1);
    }
    
    for (int i = 0; i < N; ++i) {
      sort(c[i].begin(), c[i].end());
      while (10 < c[i].size()) c[i].pop_back();
    }

    // for (int i = 0; i < n; ++i) {
    //   cout << i+1 << ": ";
    //   each (j, c[i]) cout << j << ' ' ;
    //   cout << endl;
    // }

    function<void(int, int)> fn = [&] (int curr, int prev) {
      LCA::parent[curr] = prev;
      each (next, g[curr]) {
        if (next != prev) fn(next, curr);
      }
      return ;
    };
    const int root = 0;
    fn(root, root);
    
    LCA::build(n);
    
    while (q--) {
      int x, y, a;
      scanf("%d%d%d", &x, &y, &a);
      --x;
      --y;
      vector<int> v = LCA::query(x, y);
      const int z = min<int>(a, v.size());
      while (z < v.size()) v.pop_back();
      printf("%d", z);
      each (i, v) printf(" %d", i);
      puts("");
    }
  }
  return 0;
}
```
