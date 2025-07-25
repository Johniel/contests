// github.com/Johniel/contests
// atcoder/abc411/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 998244353; // 1e9 + 7;

const int N = 3 * 1e5 + 3;

struct UnionFind {
  vector<int> r, p;
  UnionFind(int n): r(n, 0), p(n, -1) {}
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (r[a] > r[b]) swap(a, b);
    p[b] += p[a];
    p[a] = b;
    if (r[a] == r[b]) ++r[b];
    return true;
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

struct Contracting {
};

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vec<pair<int, int>> v(m);
    cin >> v;
    each (i, v) --i.first, --i.second;

    set<int> g[n];
    each (k, v) {
      g[k.first].insert(k.second);
      g[k.second].insert(k.first);
    }

    int q;
    cin >> q;
    vec<int> xs(q);
    cin >> xs;
    each (x, xs) --x;

    UnionFind uf(n);

    set<pair<int, int>> rm;
    int E = v.size() * 2;
    vec<int> rep(n);
    iota(rep.begin(), rep.end(), 0);
    each (x, xs) {
      auto [a, b] = v[x];
      a = uf.find(a);
      b = uf.find(b);
      unless (uf.same(a, b)) {
        uf.unite(a, b);
        uf.find(a);
        uf.find(b);
        int ra = rep[a];
        int rb = rep[b];
        unless (g[ra].size() > g[rb].size()) swap(ra, rb);
        vec<pair<int, int>> tmp;
        each (rc, g[rb]) {
          if (uf.same(rc, ra)) {
            E -= 2;
          } else {
            if (g[ra].count(rc)) {
              E -= 2;
              g[ra].erase(rb);
            } else {
              g[ra].insert(rc);
              g[rc].insert(ra);
            }
          }
          rm.insert(make_pair(rb, rc));
          rm.insert(make_pair(rc, rb));
        }
        each (rc, g[rb]) g[rc].erase(rb);
        g[rb].clear();
        rep[a] = rep[b] = ra;
      }
      cout << E/2 << endl;
    }
  }
  return 0;
}
