// codeforces/582div3/G/main.cpp
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
      int a, b;
      lli c;
    };
    vector<E> es(n - 1);
    each (i, es) {
      cin >> i.a >> i.b >> i.c;
      --i.a;
      --i.b;
    }
    vector<int> v(m);
    cin >> v;

    sort(es.begin(), es.end(), [] (auto a, auto b) {
      return a.c < b.c;
    });

    UnionFind uf(n);
    const int N = 2 * 1e5 + 5;
    static lli y[N];
    fill(y, y + N, 0);
    lli z = 0;
    each (e, es) {
      const lli a = uf.size(e.a);
      z -= a * (a - 1) / 2;
      const lli b = uf.size(e.b);
      z -= b * (b - 1) / 2;

      uf.unite(e.a, e.b);

      const lli c = uf.size(e.a);
      z += c * (c - 1) / 2;
      y[e.c] = z;
    }

    for (int i = 1; i < N; ++i) {
      if (y[i] == 0) y[i] = y[i - 1];
    }
    each (i, v) cout << y[i] << ' ';
    cout << endl;
  }

  return 0;
}
