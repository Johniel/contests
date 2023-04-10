// github.com/Johniel/contests
// atcoder/abc295/G/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

struct UnionFind {
  vector<int> r, p;
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
};

const int N = 2 * 1e5 + 3;
vec<int> g[N];
int parent[N];
int mn[N];
int rec(int curr, int prev)
{
  mn[curr] = curr;
  each (next, g[curr]) {
    if (next == prev) continue;
    setmin(mn[curr], rec(next, curr));
  }
  return mn[curr];
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<int> p(n - 1);
    cin >> p;
    each (i, p) --i;
    for (int i = 0; i < p.size(); ++i) {
      g[p[i]].push_back(i + 1);
      parent[i + 1] = p[i];
    }
    static int deg[N];
    fill(deg, deg + N, 0);
    for (int i = 0; i < n; ++i) {
      each (j, g[i]) ++deg[j];
    }
    int root;
    for (int i = 0; i < n; ++i) {
      if (deg[i] == 0) {
        root = i;
        break;
      }
    }
    rec(root, root);
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
      uf.r[i] = -mn[i];
    }

    int q;
    cin >> q;
    while (q--) {
      int op;
      cin >> op;
      if (op == 1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        // 辺a->bを追加する。ただし路b->aは存在する。
        a = uf.find(a);
        b = uf.find(b);
        while (a != b) {
          uf.unite(a, b);
          a = uf.find(parent[a]);
        }
      }
      if (op == 2) {
        int x;
        cin >> x;
        --x;
        x = uf.find(x);
        cout << abs(uf.r[x]) + 1 << endl;
      }
    }
  }
  return 0;
}
