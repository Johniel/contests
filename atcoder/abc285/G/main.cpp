// github.com/Johniel/contests
// atcoder/abc285/G/main.cpp

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
          if (0 < e.residual() && dist[e.dst] == inf) {
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
        if (0 < e.residual() && dist[e.src] < dist[e.dst]) {
          Cap f = rec(e.dst, snk, min(flow, e.residual()));
          if (0 < f) {
            e.flow += f;
            g[e.dst][e.rev].flow -= f;
            return f;
          }
        }
      }
      return 0;
    }

    Cap run(const int src, const int snk)
    {
      Cap sum = 0;
      while (bfs(src, snk)) {
        fill(idx.begin(), idx.end(), 0);
        for (Cap f; 0 < (f = rec(src, snk, numeric_limits<Cap>::max())); sum += f) ;
      }
      return sum;
    }
  };
};

namespace {
  // ABC285G
  template<typename Cap = long long int, int N=2>
  struct DinicLowerBound {
    const int S;
    const int T;
    Cap sum_mn;
    Dinic<Cap, N+2> dinic;

    DinicLowerBound() : S(N), T(N + 1), sum_mn(0) {}

    void add_edge(int src, int dst, Cap mn, Cap mx)
    {
      assert(0 <= mn);
      assert(mn <= mx);

      sum_mn += mn;

      dinic.add_edge(src, dst, mx - mn);
      dinic.add_edge(S, dst, mn);
      dinic.add_edge(src, T, mn);
      return ;
    }

    void add_edge(int src, int dst, Cap mx)
    {
      return add_edge(src, dst, 0, mx);
    }

    Cap run(int src, int snk)
    {
      Cap a = dinic.run(S, T);
      Cap b = dinic.run(src, T);
      Cap c = dinic.run(S, snk);
      Cap d = dinic.run(src, snk);
      return a + c == sum_mn && a + b == sum_mn ? b + d : -1;
    }
  };
};

int main(int argc, char *argv[])
{
  constexpr int H = 300 + 2;
  constexpr int W = 300 + 2;
  constexpr int N = H*W*2+3;

  int h, w;
  while (cin >> h >> w) {

    static int no[H][W];
    int cnt = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        no[i][j] = cnt++;
      }
    }

    static char g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    const int src = N - 1;
    const int snk = N - 2;
    DinicLowerBound<int, N> dinic;

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        int a = no[i][j];
        if ((i + j) % 2) {
          dinic.add_edge(a, snk, (g[i][j] == '2'), 1);
        } else {
          dinic.add_edge(src, a, (g[i][j] == '2'), 1);
          for (int d = 0; d < 4; ++d) {
            int ni = i + di[d];
            int nj = j + dj[d];
            unless (0 <= ni && ni < h) continue;
            unless (0 <= nj && nj < w) continue;
            int b = no[ni][nj];
            if (g[i][j] == '1' || g[ni][nj] == '1') continue;
            // if (g[i][j] == '?' && g[ni][nj] == '?') continue;
            dinic.add_edge(a, b, 1);
          }
        }
      }
    }
    int x = dinic.run(src, snk);
    cout << (x != -1 ? "Yes" : "No") << endl;
  }

  return 0;
}
