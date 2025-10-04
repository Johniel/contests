// github.com/Johniel/contests
// atcoder/ahc054/main.cpp

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

uint32_t xorshift(void)
{
  // https://shindannin.hatenadiary.com/entry/2021/03/06/115415
  static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t;

  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

pair<int, int> rot45(pair<int, int> p)
{
  return make_pair(p.first + p.second, p.first - p.second);
}

pair<int, int> rot90(pair<int, int> p)
{
  return rot45(rot45(p));
}

pair<int, int> flipw(pair<int, int> p)
{
  p.second *= -1;
  return p;
}

int n;
pair<int, int> aa;
pair<int, int> p0;
constexpr int H = 45;
constexpr int W = 45;
bool visible[H][W];
int no[H][W];

constexpr char treant = '%';
constexpr char tree = 'T';

constexpr array<int, 4> di({-1, +1, 0, 0});
constexpr array<int, 4> dj({0, 0, -1, +1});

struct Grid {
  char g[H][W];
  Grid() { fill(&g[0][0], &g[H - 1][W - 1] + 1, tree); }
  char& at(int i, int j) { return g[i][j]; }
  bool reachable(void) const {
    UnionFind uf(n * n);
    int e = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        e += (g[i][j] == '.');
        for (int d = 0; d < 4; ++d) {
          const int ni = i + di[d];
          const int nj = j + dj[d];
          unless (0 <= ni && ni < n) continue;
          unless (0 <= nj && nj < n) continue;
          if (g[i][j] == '.' && g[ni][nj] == '.') uf.unite(no[i][j], no[ni][nj]);
        }
      }
    }
    return uf.same(no[aa.first][aa.second], no[p0.first][p0.second]) && uf.size(no[aa.first][aa.second]) == e;
  }
  void rand(void) {
    {
      vec<pair<int, int>> u;
      u.push_back(make_pair(0, -1));
      u.push_back(make_pair(0, +2));

      u.push_back(make_pair(-1, 0));
      u.push_back(make_pair(+1, 0));

      u.push_back(make_pair(-1, +1));
      u.push_back(make_pair(+1, +2));
      u.push_back(make_pair(+3, +1));

      each (dij, u) {
        const int ti = aa.first + dij.first;
        const int tj = aa.second + dij.second;
        if (make_pair(ti, tj) == aa) continue;
        if (make_pair(ti, tj) == p0) continue;
        if (visible[ti][tj]) continue;
        if (g[ti][tj] != '.') continue;
        g[ti][tj] = treant;
        unless (reachable()) g[ti][tj] = '.';
      }
    }

    {
      for (int _ = 0; _ < n + n; ++_) {
        const int i = xorshift() % (n - 2) + 1;
        const int j = xorshift() % (n - 2) + 1;

        unless (g[i][j] == '.') continue;
        unless (g[i - 1][j] == '.') continue;
        unless (g[i][j - 1] == '.') continue;

        unless (g[i - 1][j - 1] == '.' ) continue;
        unless (g[i][j + 1] == '.' ) continue;
        unless (g[i + 1][j] == '.' ) continue;

        g[i][j] = g[i - 1][j] = g[i][j - 1] = '@';
        g[i - 1][j - 1] = g[i][j + 1] = g[i + 1][j] = treant;
        unless (reachable()) {
          g[i][j] = g[i - 1][j] = g[i][j - 1] = '.';
          g[i - 1][j - 1] = g[i][j + 1] = g[i + 1][j] = '.';
        }
      }
    }

    for (int _ = 0; _ < n * n / 2; ++_) {
      const int ti = xorshift() % n;
      const int tj = xorshift() % n;
      if (make_pair(ti, tj) == aa) continue;
      if (make_pair(ti, tj) == p0) continue;
      if (visible[ti][tj]) continue;
      if (g[ti][tj] != '.') continue;
      g[ti][tj] = treant;
      unless (reachable()) g[ti][tj] = '.';
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cerr << g[i][j];
      }
      cerr << endl;
    }
    cerr << endl;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][j] == '@') g[i][j] = '.';
      }
    }

    return ;
  }
  ostream& show(ostream& os) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (0) ;
        else if (p0 == make_pair(i, j)) os << 'S';
        else if (aa == make_pair(i, j)) os << 'A';
        else os << at(i, j);
      }
      os << endl;
    }
    return os;
  }
  int dist(void) {
    int d[H][W];
    fill(&d[0][0], &d[H - 1][W - 1] + 1, -1);
    d[p0.first][p0.second] = 0;
    queue<pair<int, int>> q;
    for (q.push(p0); q.size(); q.pop()) {
      auto [i, j] = q.front();
      for (int dir = 0; dir < 4; ++dir) {
        const int ni = i + di[dir];
        const int nj = j + dj[dir];
        unless (0 <= ni && ni < n) continue;
        unless (0 <= nj && nj < n) continue;
        if (g[ni][nj] != '.') continue;
        if (d[ni][nj] != -1) continue;
        d[ni][nj] = d[i][j] + 1;
        q.push(make_pair(ni, nj));
        if (make_pair(ni, nj) == aa) return d[aa.first][aa.second];
      }
    }
    return d[aa.first][aa.second];
  }
};

void to_visible(void)
{
  int m;
  cin >> m;
  while (m--) {
    int i, j;
    cin >> i >> j;
    visible[i][j] = true;
  }
  return ;
}

int main(int argc, char *argv[])
{
  fill(&visible[0][0], &visible[H - 1][W - 1] + 1, false);
  cin >> n >> aa;
  p0 = make_pair(0, n / 2);
  Grid ini;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> ini.g[i][j];
    }
  }
  for (int i = 0, cnt = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      no[i][j] = cnt++;
    }
  }

  assert(ini.reachable());
  Grid best = ini;
  best.rand();
  int dist = best.dist();
  best.show(cerr);
  cerr << dist << endl;

  // for (int _ = 0; _ < 100; ++_) {
  //   Grid grid = ini;
  //   grid.rand();
  //   int d = grid.dist();
  //   if (dist < d) {
  //     best = grid;
  //     dist = d;
  //   }
  // }
  // best.show(cerr);
  // cerr << dist << endl;

  vec<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (best.at(i, j) == treant) v.push_back(make_pair(i, j));
    }
  }
  cout << v.size();
  each (k, v) cout << ' ' << k.first << ' ' << k.second;
  cout << endl;

  pair<int, int> p;
  while (p != aa) {
    cin >> p;
    to_visible();
    cout << 0 << endl;
  }

  return 0;
}
