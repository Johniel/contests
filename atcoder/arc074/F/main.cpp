// github.com/Johniel/contests
// atcoder/arc074/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define makepair(a, b) make_pair(a, b)
// #define endl "\n"

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

namespace {
  using Cap = long long int;

  struct E {
    int src, dst;
    Cap cap, flow;
    int rev;
    E(int s, int d, Cap c, int r) : src(s), dst(d), cap(c), flow(0), rev(r) {}
    Cap residual() const { return cap - flow; }
  };
  ostream& operator << (ostream& os, E e)
  {
    os << "E{e(" << e.src << "," << e.dst << "),f(" << e.cap << "," << e.flow << ")," << e.rev << "}";
    return os;
  }

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
        for (q.push(src); q.size() && !vis[snk]; q.pop()) {
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

    // NOTE: 内部的にrunを実行する。
    // verified ABC239G/ABC325G
    pair<Cap, vec<E>> min_cut(int src, int snk)
    {
      Cap f = run(src, snk);
      queue<int> q;
      fill(vis.begin(), vis.end(), false);
      vis[src] = true;
      for (q.push(src); q.size(); q.pop()) {
        const int curr = q.front();
        each (e, g[curr]) {
          if (!vis[e.dst] && 0 < e.residual()) {
            q.push(e.dst);
            vis[e.dst] = true;
          }
        }
      }
      vec<E> es;
      for (int i = 0; i < N; ++i) {
        each (e, g[i]) {
          if (vis[e.src] && !vis[e.dst] && 0 < e.cap && e.cap == e.flow) {
            es.push_back(e);
          }
        }
      }
      return make_pair(f, es);
    }
  };
}
const int N = 100*100*2+100+100+5;
MaxFlow<N> flow;

int main(int argc, char *argv[])
{
  int h, w;
  while (cin >> h >> w) {
    char g[h][w];
    int name[h][w][2];
    int cnt = 0;
    const int in = 0;
    const int out = 1;
    int S;
    int T;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
        name[i][j][in] = cnt++;
        name[i][j][out] = cnt++;
        if (g[i][j] == 'S') {
          S = name[i][j][in];
          g[i][j] = 'o';
        }
        if (g[i][j] == 'T') {
          T = name[i][j][out];
          g[i][j] = 'o';
        }
      }
    }
    int nameh[h];
    for (int i = 0; i < h; ++i) nameh[i] = cnt++;
    int namew[w];
    for (int j = 0; j < w; ++j) namew[j] = cnt++;
    flow.init();
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        unless (g[i][j] == 'o') continue;
        const int x = name[i][j][in];
        const int y = name[i][j][out];
        flow.add_edge(y, nameh[i], 1 << 29);
        flow.add_edge(y, namew[j], 1 << 29);
        flow.add_edge(nameh[i], x, 1 << 29);
        flow.add_edge(namew[j], x, 1 << 29);
      }
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        flow.add_edge(name[i][j][in], name[i][j][out], 1);
        if (name[i][j][in] == S) flow.add_edge(name[i][j][in], name[i][j][out], 1 << 29);
        if (name[i][j][out] == T) flow.add_edge(name[i][j][in], name[i][j][out], 1 << 29);
      }
    }
    const int src = N - 1;
    const int snk = N - 2;
    flow.add_edge(src, S, 1 << 29);
    flow.add_edge(T, snk, 1 << 29);
    auto [z, _] = flow.min_cut(src, snk);
    if (z < h * w) cout << z << endl;
    else cout << -1 << endl;
  }
  return 0;
}
