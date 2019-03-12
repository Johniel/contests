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
    s.resize(n, 1);
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
      return ;
    }

    s[a] = (s[b] = s[a] + s[b]);
    if (r[a] > r[b]) {
      p[b] = a;
    } else {
      p[a] = b;
      if(r[a] == r[b]) r[b]++;
    }
    return ;
  }
  int find(int a) {
    return (a == p[a]) ? a : p[a] = find(p[a]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  size_t size(int n) {
    return s[find(n)];
  }
private:
  vector<int> r, p, s;
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
      if (uf.same(e.first, e.second)) {
        continue;
      }

      x += (uf.size(e.first) - 1LL) * uf.size(e.first) / 2;
      x += (uf.size(e.second) - 1LL) * uf.size(e.second) / 2;

      uf.unite(e.first, e.second);

      x -= (uf.size(e.first) - 1LL) * uf.size(e.first) / 2;
    }
    reverse(u.begin(), u.end());
    each (i, u) cout << i << endl;
  }

  return 0;
}
