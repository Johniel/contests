// github.com/Johniel/contests
// atcoder/abc274/G/main2.cpp

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

namespace {
  // verified: abc274_g
  template<typename Cap = long long int, int N=2>
  struct Dinic {
    struct E {
      int src, dst;
      Cap cap, flow;
      int rev;
      E(int s, int d, Cap c, int r) : src(s), dst(d), cap(c), flow(0), rev(r) {}
      Cap residual() const { return cap - flow; }
    };

    array<vector<E>, N> g;
    array<int, N> idx;
    array<int, N> dist;
    Dinic() {}

    void init(void)
    {
      fill(g.begin(), g.end(), array<vector<E>, N>());
    }

    void add_edge(int src, int dst, Cap c)
    {
      int a = g[src].size();
      int b = g[dst].size();
      g[src].push_back(E(src, dst, c, b));
      g[dst].push_back(E(dst, src, 0, a));
      return ;
    }

    bool bfs(const int src, const int dst)
    {
      const int inf = 1 << 29;
      fill(dist.begin(), dist.end(), inf);
      queue<int> q;
      dist[src] = 0;
      for (q.push(src); q.size(); q.pop()) {
        each (e, g[q.front()]) {
          if (0 < e.cap && dist[e.dst] == inf) {
            dist[e.dst] = dist[e.src] + 1;
            q.push(e.dst);
          }
        }
      }
      return dist[dst] != inf;
    }

    Cap rec(int curr, const int snk, Cap flow)
    {
      if (curr == snk) return flow;
      for (; idx[curr] < g[curr].size(); ++idx[curr]) {
        E& e = g[curr][idx[curr]];
        if (0 < e.cap && dist[e.src] < dist[e.dst]) {
          Cap f = rec(e.dst, snk, min(flow, e.cap));
          if (0 < f) {
            e.cap -= f;
            g[e.dst][e.rev].cap += f;
            return f;
          }
        }
      }
      return 0;
    }

    Cap run(const int src, const int snk)
    {
      Cap sum = 0;
      for (int loop = 0; bfs(src, snk); ++loop) {
        fill(idx.begin(), idx.end(), 0);
        for (Cap f; 0 < (f = rec(src, snk, numeric_limits<Cap>::max())); sum += f) ;
      }
      return sum;
    }
  };
};

int main(int argc, char *argv[])
{
  const int H = 300;
  const int W = 300;
  const int N = H * W + 2;

  int h, w;
  while (cin >> h >> w) {
    Dinic<int, N> matching;

    static char g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    const int K = 300 * 300;

    static int a[H][W];
    static int b[H][W];
    fill(&a[0][0], &a[H - 1][W - 1] + 1, -1);
    fill(&b[0][0], &b[H - 1][W - 1] + 1, -1);

    int cnt = 0;

    for (int i = 0; i < h; ++i) {
      bool prev = false;
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '.') {
          unless (prev) ++cnt;
          a[i][j] = cnt;
          prev = true;
        }
        if (g[i][j] == '#') {
          prev = false;
        }
      }
    }

    for (int j = 0; j < w; ++j) {
      bool prev = false;
      for (int i = 0; i < h; ++i) {
        if (g[i][j] == '.') {
          unless (prev) ++cnt;
          b[i][j] = cnt;
          prev = true;
        }
        if (g[i][j] == '#') {
          prev = false;
        }
      }
    }

    const int src = N - 1;
    const int dst = N - 2;

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        --a[i][j];
        --b[i][j];
      }
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (a[i][j] < 0 || b[i][j] < 0) continue;
        matching.add_edge(a[i][j], b[i][j], 1);
      }
    }

    set<int> vis;
    vis.insert(-1);
    vis.insert(-2);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        unless (vis.count(a[i][j])) {
          vis.insert(a[i][j]);
          matching.add_edge(src, a[i][j], 1);
        }
        unless (vis.count(b[i][j])) {
          vis.insert(b[i][j]);
          matching.add_edge(b[i][j], dst, 1);
        }
      }
    }
    cout << matching.run(src, dst) << endl;
  }
  return 0;
}
