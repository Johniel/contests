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

class PersistentUnionFind {
public:
  PersistentUnionFind(int n)
  {
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i) {
      parent.push_back(make_pair(i, 1 << 29));
    }
  }
  inline int find(int n)
  {
    return find(n, version);
  }
  inline int find(int n, int t)
  {
    if (parent[n].second <= t) {
      return find(parent[n].first, t);
    } else {
      return n;
    }
  }
  inline void unite(int a, int b)
  {
    a = find(a, version);
    b = find(b, version);
    ++version;
    if (a == b) return ;
    if (rank[a] > rank[b]) {
      parent[b] = make_pair(a, version);
    } else {
      parent[a] = make_pair(b, version);
      rank[b] += (rank[a] == rank[b]);
    }
  }
  inline bool isSameSet(int a, int b)
  {
      return isSameSet(a, b, version);
  }
  inline bool isSameSet(int a, int b, int t)
  {
      return find(a, t) == find(b, t);
  }
  int version = 0;
  vector<int> rank;
  vector<pair<int, int>> parent;
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  while (cin >> n >> m && n) {
    PersistentUnionFind uf(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      uf.unite(a, b);
    }

    int q;
    cin >> q;
    while (q--) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      if (!uf.isSameSet(a, b)) {
        cout << -1 << endl;
        continue;
      }
      int small = 0;
      int large = uf.version + 1;
      while (small + 1 < large) {
        int mid = (small + large) / 2;
        if (uf.isSameSet(a, b, mid)) large = mid;
        else small = mid;
      }
      cout << large << endl;
    }
  }
  
  return 0;
}
