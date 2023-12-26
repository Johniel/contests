// github.com/Johniel/contests
// atcoder/abc334/G/main.cpp

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

namespace math {
  lli extgcd(lli a, lli b, lli& x, lli& y)
  {
    lli g = a;
    x = 1;
    y = 0;
    if (b != 0) {
      g = extgcd(b, a % b, y, x);
      y -= (a / b) * x;
    }
    return g;
  }

  lli mod_inverse(lli a, lli m)
  {
    lli x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
  }
};

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
  void snapshot(void) {
    stable = version();
    return ;
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

const int H = 1000 + 1;
const int W = 1000 + 1;

char g[H][W];
vec<pair<int, int>> v;
int ord[H][W];
int h, w;

lli rec(RollbackUnionFind& uf, int begin, int end, lli cc)
{
  if (end - begin == 1) {
    return (cc - 1 + mod) % mod;
  }

  int mid = begin + (end - begin) / 2;

  pair<int, int> next = make_pair(begin, mid);
  pair<int, int> merged = make_pair(mid, end);
  lli z = 0;

  for (int _ = 0; _ < 2; ++_) {
    int united = 0;
    for (int k = merged.first; k < merged.second; ++k) {
      auto [i, j] = v[k];
      for (int d = 0; d < 4; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (g[ni][nj] != '#') continue;
        pair<int, int> p = make_pair(ni, nj);
        int a = ord[i][j];
        int b = ord[ni][nj];
        unless (next.first <= b && b < next.second) {
          united += uf.unite(a, b);
        }
      }
    }
    z += rec(uf, next.first, next.second, cc - united);
    z %= mod;
    while (united--) uf.undo();
    swap(next, merged);
  }

  return z;
}

int main(int argc, char *argv[])
{

  while (cin >> h >> w) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    v.clear();
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '#') {
          ord[i][j] = v.size();
          v.emplace_back(make_pair(i, j));
        }
      }
    }

    const lli div = math::mod_inverse(v.size(), mod);
    RollbackUnionFind uf(v.size());
    lli z = rec(uf, 0, v.size(), v.size());
    cout << z * div % mod << endl;
    // break;
  }
  return 0;
}
