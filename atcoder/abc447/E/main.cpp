// github.com/Johniel/contests
// atcoder/abc447/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
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

// #include <atcoder/maxflow>
// https://atcoder.jp/contests/abc193/submissions/20547089

struct RollbackUnionFind {
  // ABC334G, ABC302H

  // find: O(logN)
  // unite: O(logN)
  // undo: O(1)
  // rollback: 指定されたversionもしくは最後にsnapshotを呼び出した時のversionまでundoする。

  vector<int> rank;
  vector<int> parent;
  vector<tuple<int, int, int>> history;
  int stable;

  RollbackUnionFind(size_t n) : parent(n, -1), rank(n, 0), stable(1 << 29) {}

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    history.emplace_back(make_tuple(x, parent[x], rank[x]));
    history.emplace_back(make_tuple(y, parent[y], rank[y]));
    if (rank[x] > rank[y]) swap(x, y);
    parent[y] += parent[x];
    parent[x] = y;
    if (rank[x] == rank[y]) ++rank[y];
    return true;
  }

  int find(int x) const {
    return (parent[x] < 0) ? x : find(parent[x]);
  }

  bool same(int x, int y) const {
    return find(x) == find(y);
  }

  size_t size(int x) {
    return -parent.at(find(x));
  }

  // not verified
  int version(void) const {
    return history.size() / 2;
  }

  // not verified
  int snapshot(void) {
    return stable = version();
  }

  pair<int, int> undo(void) {
    const auto [x, px, rx] = history.back();
    history.pop_back(); parent[x] = px; rank[x] = rx;
    const auto [y, py, ry] = history.back();
    history.pop_back(); parent[y] = py; rank[y] = ry;
    return make_pair(x, y);
  }

  // not verified
  void rollback(int ver = -1) {
    if (ver == -1) ver = stable;
    assert(ver <= version());
    while (ver < version()) undo();
    return ;
  }
};
ostream& operator << (ostream &os, RollbackUnionFind uf) {
  map<int, vector<int>> m;
  for (int i = 0; i < uf.parent.size(); ++i) {
    m[uf.find(i)].emplace_back(i);
  }
  os << m;
  return os;
}

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    RollbackUnionFind uf(n);
    vec<pair<int, int>> v(m);
    cin >> v;
    each (e, v) --e.first ,--e.second;
    lli z = 0;
    reverse(v.begin(), v.end());
    vec<lli> w;
    w.push_back(1);
    for (int i = 0; i < m; ++i) {
      w.push_back((w.back() * 2) % mod);
    }
    reverse(w.begin(), w.end());
    for (int i = 0; i < v.size(); ++i) {
      if (uf.same(v[i].first, v[i].second)) continue;
      if (uf.unite(v[i].first, v[i].second) && uf.size(v[i].first) == n) {
        uf.undo();
        (z += w[i]) %= mod;
      }
    }
    cout << z << endl;
  }

  return 0;
}
