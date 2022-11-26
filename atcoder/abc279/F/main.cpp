// github.com/Johniel/contests
// atcoder/abc279/F/main.cpp

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
  const int N = 6 * 1e5 + 1;
  static int v[N]; // ボールiは箱v[i]
  static int u[N]; // 箱iに入っているボールがu[i]

  int n, q;
  while (cin >> n >> q) {
    UnionFind uf(N); // ボール同士が同じ箱か
    iota(v, v + N, 0);
    iota(u, u + N, 0);
    int k = n - 1;
    for (int _ = 0; _ < q; ++_) {
      int op;
      cin >> op;
      if (op == 1) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        if (u[x] != -1 && u[y] != -1) {
          int a = uf.find(u[x]);
          int b = uf.find(u[y]);
          uf.unite(a, b);
          uf.find(a);
          uf.find(b);
          v[uf.find(b)] = v[uf.find(a)] = x;
        }
        if (u[x] == -1 && u[y] != -1) {
          int b = uf.find(u[y]);
          v[uf.find(b)] = x;
          u[x] = b;
        }
        u[y] = -1;
      }
      if (op == 2) {
        ++k;
        int x;
        cin >> x;
        --x;
        if (u[x] != -1) {
          uf.unite(u[x], k);
          uf.find(u[x]);
          uf.find(k);
        }
        u[x] = k;
        v[uf.find(k)] = x;
      }
      if (op == 3) {
        int x;
        cin >> x;
        --x;
        cout << v[uf.find(x)] + 1 << endl;
      }
    }
  }
  return 0;
}
