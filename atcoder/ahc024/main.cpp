// github.com/Johniel/contests
// atcoder/ahc024/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
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
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

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
      if (r[a] == r[b]) ++r[b];
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

const int H = 50 + 2;
const int W = 50 + 2;
const int N = H * W;
int name[H][W];

void solve(void)
{
  int size, color;
  unless (cin >> size >> color) return ;

  auto make_adj = [&] (int g[H][W]) {
    set<pair<int, int>> adj;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        for (int d = 0; d < 4; ++d) {
          const int ni = i + di[d];
          const int nj = j + dj[d];
          unless (0 <= ni && ni < H) continue;
          unless (0 <= nj && nj < W) continue;
          if (g[i][j] != g[ni][nj]) {
            int mn = min(g[i][j], g[ni][nj]);
            int mx = max(g[i][j], g[ni][nj]);
            adj.insert(make_pair(mn, mx));
          }
        }
      }
    }
    return adj;
  };

  static int g[H][W];
  fill(&g[0][0], &g[H - 1][W - 1] + 1, 0);
  for (int i = 1; i < 50 + 1; ++i) {
    for (int j = 1; j < 50 + 1; ++j) {
      cin >> g[i][j];
    }
  }
  static int f[H][W];
  copy(&g[0][0], &g[H - 1][W - 1] + 1, &f[0][0]);

  const set<pair<int, int>> adj_origin = make_adj(g);

  auto validate = [&] (void) {
    if (adj_origin != make_adj(f)) return false;

    UnionFind uf(N);
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        for (int d = 0; d < 4; ++d) {
          const int ni = i + di[d];
          const int nj = j + dj[d];
          unless (0 <= ni && ni < H) continue;
          unless (0 <= nj && nj < W) continue;
          if (f[i][j] == f[ni][nj]) {
            uf.unite(name[i][j], name[ni][nj]);
          }
        }
      }
    }
    map<int, int> freq;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        ++freq[f[i][j]];
      }
    }

    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (uf.size(name[i][j]) != freq[f[i][j]]) return false;
      }
    }
    return true;
  };

  vec<pair<int, int>> v;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      v.push_back(make_pair(i, j));
    }
  }

  for (int _ = 0; _ < 3; ++_) {
    clog << _ << "-th itr" << endl;
    each (pos, v) {
      auto [i, j] = pos;
      const int d = _ % 2;
      // const int d = 0;
      const int ni = i + di[d];
      const int nj = j + dj[d];
      unless (0 <= ni && ni < H) continue;
      unless (0 <= nj && nj < W) continue;
      if (ni == H - 1 || nj == W - 1 || ni == 0 || nj == 0) continue;
      if (f[i][j] == f[ni][nj]) continue;
      f[ni][nj] = f[i][j];
      if (validate()) {
        g[ni][nj] = g[i][j];
      } else {
        f[ni][nj] = g[ni][nj];
      }
    }
  }

  for (int i = 1; i < 50 + 1; ++i) {
    for (int j = 1; j < 50 + 1; ++j) {
      cout << g[i][j] << ' ';
    }
    cout << endl;
  }

  return ;
}


int main(int argc, char *argv[])
{
  {
    int cnt = 0;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        name[i][j] = cnt++;
      }
    }
  }
  for (int _ = 0; _ < 150; ++_) solve();
  return 0;
}
