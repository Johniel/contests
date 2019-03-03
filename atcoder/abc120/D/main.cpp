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

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  lli size(int x) {
    return -data[root(x)];
  }
  bool isSameSet(int x, int y) {
    return findSet(x, y);
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, m;
  while (cin >> n >> m) {
    vector<pair<int, int>> v(m);
    cin >> v;
    reverse(v.begin(), v.end());

    UnionFind uf(n + 1);

    vector<lli> u;
    lli x = (n - 1) * n / 2;
    each (e, v) {
      u.push_back(x);
      if (uf.isSameSet(e.first, e.second)) {
        continue;
      }
      
      x += (uf.size(e.first) - 1) * uf.size(e.first) / 2;
      x += (uf.size(e.second) - 1) * uf.size(e.second) / 2;

      uf.unite(e.first, e.second);

      x -= (uf.size(e.first) - 1) * uf.size(e.first) / 2;
    }
    reverse(u.begin(), u.end());
    each (i, u) cout << i << endl;
  }

  return 0;
}
