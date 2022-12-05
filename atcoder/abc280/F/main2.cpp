// github.com/Johniel/contests
// atcoder/abc280/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

template<typename Weight>
struct WeightedUnionFind {
  // abc280F,
  vector<int> r;
  vector<int> p;
  vector<Weight> dw;

  WeightedUnionFind(int n)
  {
    r.resize(n, 0);
    p.resize(n, -1);
    dw.resize(n, 0);
  }

  int find(int x)
  {
    if (p[x] < 0) return x;
    int y = find(p[x]);
    dw[x] += dw[p[x]];
    return p[x] = y;
  }

  // weight(y) = weight(x) + w
  bool unite(int x, int y, Weight w)
  {
    w = w + weight(x) - weight(y);
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (r[x] < r[y]) {
      swap(x, y);
      w = -w;
    }
    p[y] = x;
    dw[y] = w;
    if (r[x] == r[y]) ++r[y];
    return true;
  }

  Weight weight(int x) { find(x); return dw[x]; }
  // weight(x) - weight(x) if same(x, y)
  Weight diff(int src, int dst) { assert(same(src, dst)); return weight(dst) - weight(src); }
  size_t size(int x) { return -p.at(find(x)); }
  bool same(int x, int y) { return find(x) == find(y); }
};

int main(int argc, char *argv[])
{
  const int N = 2 * 1e5 + 3;
  int n, m, q;
  while (cin >> n >> m >> q) {
    vec<pair<int, lli>> g[N];
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back(make_pair(b, +c));
      g[b].push_back(make_pair(a, -c));
    }
    WeightedUnionFind<lli> uf(n);
    vec<int> v;
    for (int i = 0; i < n; ++i) {
      each (e, g[i]) {
        int j = e.first;
        lli w = e.second;
        if (uf.same(i, j)) {
          if (uf.diff(i, j) != w) v.push_back(i);
        } else {
          uf.unite(i, j, w);
        }
      }
    }
    for (int i = 0; i < n; ++i) uf.find(i);
    set<int> cycle;
    each (i, v) cycle.insert(uf.find(i));
    while (q--) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      if (!uf.same(a, b)) {
        cout << "nan" << endl;
        continue;
      }
      if (cycle.count(uf.find(a))) {
        cout << "inf" << endl;
        continue;
      }
      cout << uf.diff(a, b) << endl;
    }
  }
  return 0;
}
