// codeforces/548div2/C/main.cpp
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

const lli mod = 1e9 + 7;

lli mod_pow(lli n, int p)
{
  if (p == 0) return 1;
  if (p == 1) return n;
  lli m = mod_pow(n, p / 2);
  (m *= m) %= mod;
  return p % 2 ? (m * n) % mod : m;
}

void gen(void)
{
  const int N = 1e5;
  cout << N << ' ' << 100 << endl;
  for (int i = 0; i < N - 1; ++i) {
    cout << i + 1 << ' ' << i + 2 << ' ' << 0 << endl;
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // gen(); return 0;

  lli n, k;
  while (cin >> n >> k) {
    bool f = false;

    UnionFind uf(n);
    for (int i = 0; i < n - 1; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      if (c == 0) {
        uf.unite(a, b);
      }
      f = f || c;
    }

    if (!f) {
      cout << 0 << endl;
      continue;
    }

    for (int i = 0; i < n; ++i) {
      uf.find(i);
    }

    lli x = 1;
    for (int i = 0; i < k; ++i) {
      (x *= n) %= mod;
    }

    set<int> vis;
    lli sum = x;
    for (int i = 0; i < n; ++i) {
      if (vis.count(uf.find(i))) continue;
      vis.insert(uf.find(i));
      sum = (sum - mod_pow(uf.size(i), k) + mod) % mod;
    }
    cout << sum << endl;
  }

  return 0;
}
