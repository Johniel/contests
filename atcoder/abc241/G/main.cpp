// atcoder/abc241/G/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

namespace {

  using Cap = long long int;

  struct E {
    int src, dst;
    Cap cap, flow;
    int rev;
    E(int s, int d, Cap c, int r) : src(s), dst(d), cap(c), flow(0), rev(r) {}
    Cap residual() const { return cap - flow; }
  };

  template<int N>
  struct MaxFlow {
    array<vector<E>, N> g;
    array<bool, N> vis;
    array<pair<int, int>, N> path; // (vertex, edge index)

    void init(void)
    {
      fill(g.begin(), g.end(), vector<E>());
      return ;
    }

    void add_edge(int src, int dst, Cap c)
    {
      int a = g[src].size();
      int b = g[dst].size();
      g[src].push_back(E(src, dst, c, b));
      g[dst].push_back(E(dst, src, 0, a));
      return ;
    }

    Cap run(const int src, const int snk)
    {
      path[src] = make_pair(src, -1);
      Cap sum = 0;
      while (true) {
        fill(vis.begin(), vis.end(), false);
        vis[src] = true;
        queue<int> q;
        for (q.push(src); q.size(); q.pop()) {
          for (int i = 0; i < g[q.front()].size(); ++i) {
            const auto& e = g[q.front()][i];
            if (!vis[e.dst] && 0 < e.residual()) {
              q.push(e.dst);
              vis[e.dst] = true;
              path[e.dst] = make_pair(e.src, i);
            }
          }
        }
        if (!vis[snk]) break;
        Cap mn = (1LL << 60) + 5;
        for (int i = snk; path[i].first != i; i = path[i].first) {
          const int v = path[i].first;
          const int e = path[i].second;
          setmin(mn, g[v][e].residual());
        }
        for (int i = snk; path[i].first != i; i = path[i].first) {
          const int v = path[i].first;
          const int e = path[i].second;
          g[v][e].flow += mn;
          g[i][g[v][e].rev].flow -= mn;
        }
        sum += mn;
      }

      return sum;
    }

    pair<Cap, vec<E>> min_cut(int src, int snk)
    {
      // verified abc239 G
      Cap f = run(src, snk);
      queue<int> q;
      fill(vis.begin(), vis.end(), false);
      vis[src] = true;
      for (q.push(src); q.size(); q.pop()) {
        const int curr = q.front();
        each (e, g[curr]) {
          if (!vis[e.dst] && 0 < e.residual()) {
            q.push(e.dst);
            vis.insert(e.dst);
          }
        }
      }
      vec<E> es;
      for (int i = 0; i < N; ++i) {
        each (e, g[i]) {
          if (vis[e.src] && !vis[e.dst] && 0 <= e.cap && e.cap == e.flow) {
            es.push_back(e);
          }
        }
      }
      return make_pair(f, es);
    }
  };
}
constexpr int N = 50 + 1;
constexpr int M = N * N + N + 3;
MaxFlow<M> flow;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  const int src = M - 1;
  const int snk = M - 2;
  const int E = N - 1;
  static int cnt[N][N];
  {
    int k = 0;
    for (int i = 0; i < N; ++i) {
      cnt[i][E] = k++;
      for (int j = i + 1; j < N; ++j) {
        cnt[i][j] = k++;
      }
    }
  }

  int n, m;
  while (cin >> n >> m) {
    vec<pair<int, int>> v(m);
    cin >> v;
    each (i, v) {
      --i.first;
      --i.second;
    }
    sort(v.begin(), v.end());

    static bool vis[N][N];
    fill(&vis[0][0], &vis[N - 1][N - 1] + 1, false);
    each (i, v) vis[i.first][i.second] = true;

    vec<int> u;
    for (int k = 0; k < n; ++k) {
      int win = 0;
      for (int i = 0; i < n; ++i) {
        if (i == k || vis[i][k]) continue;
        ++win;
      }
      if (win == 0) continue;
      flow.init();
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          flow.add_edge(src, cnt[i][j], 1);
        }
      }
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (0) {
          } else if (vis[i][j]) {
            flow.add_edge(cnt[i][j], cnt[i][E], 1);
          } else if (vis[j][i]) {
            flow.add_edge(cnt[i][j], cnt[j][E], 1);
          } else {
            if (0) {
            } else if (i == k) {
              flow.add_edge(cnt[i][j], cnt[i][E], 1);
            } else if (j == k) {
              flow.add_edge(cnt[i][j], cnt[j][E], 1);
            } else {
              flow.add_edge(cnt[i][j], cnt[i][E], 1);
              flow.add_edge(cnt[i][j], cnt[j][E], 1);
            }
          }
        }
      }
      for (int i = 0; i < n; ++i) {
        if (i == k) {
          flow.add_edge(cnt[i][E], snk, win);
        } else {
          flow.add_edge(cnt[i][E], snk, win - 1);
        }
      }
      int x = flow.run(src, snk);
      const int y = n * (n - 1) / 2;
      if (x == y) u.push_back(k);
    }
    each (i, u) cout << i + 1 << ' ';
    cout << endl;
  }

  return 0;
}
