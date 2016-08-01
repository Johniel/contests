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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ',';
  os << ")";
  return os;
}

struct UnionFind {
  vector<int> r, p, s;
  UnionFind(int n)
  {
    r.resize(n, 1);
    s.resize(n, 1);
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }
  void unite(int a, int b)
  {
    a = find(a);
    b = find(b);
    int c = link(a, b);
    if (a != b) s[c] = (s[a] + s[b]);
  }
  int find(int a)
  {
    return (a == p[a]) ? a : p[a] = find(p[a]);
  }
  bool isSameSet(int a, int b)
  {
    return find(a) == find(b);
  }
  int link (int a, int b)
  {
    int c;
    if (r[a] > r[b]) {
      c = (p[b] = a);
    } else {
      c = (p[a] = b);
      if(r[a] == r[b]) r[b]++;
    }
    return c;
  }
  int size(int a)
  {
    return s[find(a)];
  }
};

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      v.push_back(make_pair(a, b));
    }
    int q;
    cin >> q;
    vector<tuple<int, int, int>> qs;
    for (int i = 0; i < q; ++i) {
      int x, y, z;
      cin >> x >> y >> z;
      --x;
      --y;
      --z;
      qs.push_back(make_tuple(x, y, z));
    }

    vector<int> small(q, 0);
    vector<int> large(q, m + 1);
    map<int, vector<int>> mid;
    for (int i = 0; i < q; ++i) {
      mid[(small[i] + large[i]) / 2].push_back(i);
    }

    auto f = [&] (void) {
      for (int i = 0; i < q; ++i) {
        if (small[i] + 1 < large[i]) return true;
      }
      return false;
    };
    
    while (f()) {
      UnionFind uf(n);
      map<int, vector<int>> next;
      for (int i = 0; i < m; ++i) {
        uf.unite(v[i].first, v[i].second);
        unless (mid.count(i + 1)) continue;
        each (q_idx, mid[i + 1]) {
          int x, y, z;
          tie(x, y, z) = qs[q_idx];
          const int size = uf.isSameSet(x, y) ? uf.size(x) : uf.size(x) + uf.size(y);
          if (size > z) {
            large[q_idx] = i + 1;
          } else {
            small[q_idx] = i + 1;
          }
          next[(small[q_idx] + large[q_idx]) / 2].push_back(q_idx);
        }
      }
      mid = move(next);
    }

    for (int i = 0; i < q; ++i) {
      cout << large[i] << endl;
    }
  }
  return 0;
}
