// atcoder/abc040/D/main.cpp
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

class UnionFind {
public:
  UnionFind(int n) {
    r.resize(n, 0);
    p.resize(n, -1);
  }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return ;
    if (r[a] > r[b]) {
      p[a] += p[b];
      p[b] = a;
    } else {
      p[b] += p[a];
      p[a] = b;
      if(r[a] == r[b]) r[b]++;
    }
    return ;
  }
  int find(int a) {
    return (p[a] < 0) ? a : p[a] = find(p[a]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  size_t size(int n) {
    return -p[find(n)];
  }
private:
  vector<int> r, p;
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    using E = struct {
      int a, b, y;
    };
    vector<E> es(m);
    each (i, es) {
      cin >> i.a >> i.b >> i.y;
      --i.a;
      --i.b;
    }
    sort(begin(es), end(es), [] (auto i, auto j) { return i.y > j.y; });

    int q;
    cin >> q;
    using C = struct {
      int idx, node, y;
    };
    vector<C> v(q);
    for (int i = 0; i < v.size(); ++i) {
      v[i].idx = i;
      cin >> v[i].node >> v[i].y;
      --v[i].node;
    }
    sort(begin(v), end(v), [] (auto i, auto j) { return i.y > j.y; });

    UnionFind uf(n);
    map<int, int> m;
    int j = 0;
    each (i, v) {
      while (j < es.size() && es[j].y > i.y) {
        uf.unite(es[j].a, es[j].b);
        ++j;
      }
      m[i.idx] = uf.size(i.node);
    }
    for (int i = 0; i < m.size(); ++i) {
      cout << m[i] << endl;
    }
  }

  return 0;
}
