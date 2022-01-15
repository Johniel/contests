// atcoder/abc235/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

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
    return -p.at(find(n));
  }
private:
  vector<int> r, p;
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m, q;
  while (cin >> n >> m >> q) {
    const int N = 2 * 1e5 + 3;
    const int M = N * 2;
    static int a[M];
    static int b[M];
    static lli c[M];
    for (int i = 0; i < m; ++i) {
      cin >> a[i] >> b[i] >> c[i];
      --a[i];
      --b[i];
    }
    for (int i = 0; i < q; ++i) {
      cin >> a[i + m] >> b[i + m] >> c[i + m];
      --a[i + m];
      --b[i + m];
    }
    vec<int> v;
    for (int i = 0; i < m + q; ++i) {
      v.push_back(i);
    }
    sort(v.begin(), v.end(), [&] (auto i, auto j) { return c[i] < c[j]; });
    static bool z[N];
    fill(z, z + N, false);
    const lli inf = 1LL << 60;
    UnionFind uf(n);
    each (i, v) {
      int src = a[i];
      int dst = b[i];
      if (!uf.same(src, dst)) {
        if (m <= i) {
          z[i - m] = true;
        } else {
          uf.unite(src, dst);
        }
      }
    }
    for (int i = 0; i < q; ++i) {
      cout << (z[i] ? "Yes" : "No") << endl;
    }
  }

  return 0;
}
