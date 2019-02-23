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

class UnionFind {
public:
  vector<int> rank, p;
  UnionFind(int size)
  {
    rank.resize(size, -1);
    p.resize(size, -1);
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
    const int N = n + 5;
    UnionFind uf(N);
    for (int i = 0; i < N; ++i) {
      uf.make(i);
    }

    vector<pair<int, int>> v(n - 1);
    cin >> v;

    map<int, vector<int>> m;
    for (int i = 0; i < N; ++i) {
      m[i].push_back(i);
    }
    
    each (i, v) {
      int x = uf.find(i.first);
      int y = uf.find(i.second);
      uf.unite(i.first, i.second);
      int z = uf.find(i.first);
      int w = z == y ? x : y;
      m[z].insert(m[z].end(), m[w].begin(), m[w].end());
    }

    int x = 0;
    each (i, m) {
      if (m[x].size() < i.second.size()) x = i.first;
    }
    each (i, m[x]) cout << i << ' ' ;
    cout << endl;
  }
  
  return 0;
}
