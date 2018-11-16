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

struct E {
  int src, dst, cost;
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<pair<lli, lli>> v(n);
    cin >> v;

    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
      a.push_back(i);
      b.push_back(i);
    }

    sort(a.begin(), a.end(), [&] (int i, int j) { return v[i].first < v[j].first; });
    sort(b.begin(), b.end(), [&] (int i, int j) { return v[i].second < v[j].second; });

    vector<E> es;
    for (int i = 0; i + 1 < n; ++i) {
      int x = a[i];
      int y = a[i + 1];
      auto c = abs(v[x].first - v[y].first);
      es.push_back(E{x, y, c});
      es.push_back(E{y, x, c});
    }
    for (int i = 0; i + 1 < n; ++i) {
      int x = b[i];
      int y = b[i + 1];
      auto c = abs(v[x].second - v[y].second);
      es.push_back(E{x, y, c});
      es.push_back(E{y, x, c});
    }

    sort(es.begin(), es.end(), [] (auto i, auto j) { return i.cost < j.cost; });

    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
      uf.make(i);
    }

    lli sum = 0;
    each (e, es) {
      if (!uf.isSameSet(e.src, e.dst)) {
        uf.unite(e.src, e.dst);
        sum += e.cost;
      }
    }
    cout << sum << endl;
  }

  return 0;
}
