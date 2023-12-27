// github.com/Johniel/contests
// atcoder/abc302/H/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

struct RollbackUnionFind {
  // ABC334G

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

const int N = 2 * 1e5 + 3;
vec<int> g[N];
vec<pair<int, int>> v;
int r[N];
const int C = N - 1;
size_t e[N];
void rec(int curr, int prev, RollbackUnionFind& uf, int x)
{
  const auto [a, b] = v[curr];
  bool f = false;
  pair<int, int> pa = make_pair(uf.find(a), e[uf.find(a)]);
  pair<int, int> pb = make_pair(uf.find(b), e[uf.find(b)]);
  const int y = x;
  if (!uf.same(a, b)) {
    f = true;
    x -= min(uf.size(a), e[uf.find(a)]);
    x -= min(uf.size(b), e[uf.find(b)]);
    const int tmp = e[uf.find(a)] + e[uf.find(b)] + 1;
    uf.unite(a, b);
    e[uf.find(a)] = tmp;
    x += min(uf.size(a), e[uf.find(a)]);
  } else {
    x -= min(uf.size(a), e[uf.find(a)]);
    ++e[uf.find(a)];
    x += min(uf.size(a), e[uf.find(a)]);
  }
  r[curr] = x;
  each (next, g[curr]) {
    unless (next == prev) rec(next, curr, uf, x);
  }

  if (f) {
    e[pa.first] = pa.second;
    e[pb.first] = pb.second;
    uf.undo();
  } else {
    --e[uf.find(a)];
  }
  return ;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    fill(g, g + N, vec<int>());
    v.resize(n);
    cin >> v;
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    RollbackUnionFind uf(N);
    fill(e, e + N, 0);
    rec(0, 0, uf, 0);
    for (int i = 1; i < n; ++i) {
      cout << r[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
