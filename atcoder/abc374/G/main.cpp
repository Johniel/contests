// github.com/Johniel/contests
// atcoder/abc374/G/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

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

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

namespace SCC {
  // https://atcoder.jp/contests/typical90/tasks/typical90_u

  const int N = 2000;
  bool vis[N];

  void rec(vec<int> graph[N], int curr, int ord[], int &cnt)
  {
    vis[curr] = true;
    for (auto& next : graph[curr]) {
      unless (vis[next]) rec(graph, next, ord, cnt);
    }
    ord[--cnt] = curr;
    return ;
  }

  vector<int> g[N];
  vector<int> h[N];
  void init(const int size)
  {
    fill(g, g + size, vector<int>());
  }

  int ord[N];
  int scc[N];
  vector<vector<int>> detect_scc(const int size)
  {
    int cnt, prev = size - 1;
    vector<vector<int>> ret;
    fill(ord, ord + size, -1);
    fill(scc, scc + size, -1);
    fill(h, h + size, vector<int>());
    for (int curr = 0; curr < size; ++curr) {
      for (const auto& next : g[curr]) {
        h[next].push_back(curr);
      }
    }
    cnt = size;
    fill(vis, vis + N, false);
    for (int i = 0; i < size; ++i) {
      unless (vis[i]) rec(g, i, ord, cnt);
    }
    cnt = size;
    fill(vis, vis + N, false);
    for (int i = 0; i < size; ++i) {
      unless (vis[ord[i]]) {
        rec(h, ord[i], scc, cnt);
        int j = prev;
        vector<int> T;
        for (j = prev; 0 <= j && scc[j] != -1; --j) T.push_back(scc[j]);
        prev = j;
        ret.push_back(T);
      }
    }
    return ret;
  }
};

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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<str> v(n);
    cin >> v;
    SCC::init(n);
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v.size(); ++j) {
        if (i == j) continue;
        if (v[i][1] == v[j][0]) {
          SCC::g[i].push_back(j);
        }
      }
    }
    vec<vec<int>> scc = SCC::detect_scc(n);
    sort(scc.begin(), scc.end());
    map<int, int> rename;
    for (int i = 0; i < scc.size(); ++i) {
      each (j, scc[i]) {
        rename[j] = i;
      }
    }

    set<pair<int, int>> vis;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v.size(); ++j) {
        if (v[i][1] == v[j][0]) {
          int a = rename[i];
          int b = rename[j];
          if (a != b) vis.insert(make_pair(a, b));
        }
      }
    }

    const int M = 26*26+3;
    static bool reach[M][M];
    fill(&reach[0][0], &reach[M - 1][M - 1] + 1, false);
    each (k, vis) {
      reach[k.first][k.second] = true;
    }
    for (int k = 0; k < v.size(); ++k) {
      for (int i = 0; i < v.size(); ++i) {
        unless (reach[i][k]) continue;
        for (int j = 0; j < v.size(); ++j) {
          reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
        }
      }
    }
    vis.clear();
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < M; ++j) {
        if (reach[i][j]) vis.insert(make_pair(i, j));
      }
    }
    MaxFlow<1400> g;
    const int src = 1400 - 1;
    const int snk = 1400 - 2;
    const int base = 700;
    each (k, vis) {
      g.add_edge(k.first, k.second + base, 1);
    }
    for (int i = 0; i < scc.size(); ++i) {
      g.add_edge(src, i, 1);
      g.add_edge(i + base, snk, 1);
    }
    int matched = g.run(src, snk);
    cout << (int)scc.size() - matched << endl;
  }
  return 0;
}
