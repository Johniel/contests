// atcoder/abc126/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

const int inf = 1 << 29;

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
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
      uf.make(i);
    }

    for (int i = 0; i < m; ++i) {
      int x, y, z;
      cin >> x >> y >> z;
      --x;
      --y;
      uf.unite(x, y);
    }
    for (int i = 0; i < n; ++i) {
      uf.find(i);
    }
    set<int> s;
    for (int i = 0; i < n; ++i) {
      s.insert(uf.find(i));
    }
    cout << s.size() << endl;
  }

  return 0;
}
