// atcoder/abc004/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }
template<typename T> inline pair<T, T> reverse(pair<T, T> p) { return make_pair(p.second, p.first); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;

constexpr lli mod = 1e9 + 7;

namespace graph {
  struct E {
    int src, dst, cost, cap, rev;
    E(int _src, int _dst, int _cost, int _cap, int _rev)
      : src(_src), dst(_dst), cost(_cost), cap(_cap), rev(_rev) {}
  };

  const int V = 1000 + 5;
  vector<E> g[V];
  int cost[V], h[V], prevv[V], preve[V];

  const int inf = (1 << 28);


  void init(void)
  {
    fill(g, g + V, vector<E>());
    return ;
  }

  void add_edge(int src, int dst, int cost, int cap)
  {
    g[src].push_back(E(src, dst,  cost, cap, (int)g[dst].size()));
    g[dst].push_back(E(dst, src, -cost,   0, (int)g[src].size() - 1));
    return ;
  }

  int min_cost_flow(int src, int snk, int req)
  {
    int ret = 0;
    fill(h, h + V, 0);
    while (0 < req) {
      priority_queue<pair<int, int>> q;
      fill(cost, cost + V, inf);
      cost[src] = 0;
      for (q.push(make_pair(-0, src)); q.size(); ) {
        pair<int, int> p = q.top();
        q.pop();
        int v = p.second;
        int c = -p.first;
        if (cost[v] < c) continue;
        for (int i = 0; i < g[v].size(); ++i) {
          E& e = g[v][i];
          int d = cost[v] + e.cost + h[e.src] - h[e.dst];
          if (0 < e.cap && d < cost[e.dst]) {
            cost[e.dst] = d;
            prevv[e.dst] = v;
            preve[e.dst] = i;
            q.push(make_pair(-cost[e.dst], e.dst));
          }
        }
      }
      if (cost[snk] == inf) break;
      for (int i = 0; i < V; ++i) {
        h[i] += cost[i];
      }
      int d = req;
      for (int v = snk; v != src; v = prevv[v]) {
        d = min(d, g[prevv[v]][preve[v]].cap);
      }
      req -= d;
      ret += d * h[snk];
      for (int v = snk; v != src; v = prevv[v]) {
        E& e = g[prevv[v]][preve[v]];
        e.cap -= d;
        g[v][e.rev].cap += d;
      }
    }
    return ret;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int r, g, b;
  while (cin >> r >> g >> b) {
    graph::init();

    const int x = -100 + 500;
    const int y =    0 + 500;
    const int z = +100 + 500;

    const int src = graph::V - 1;
    const int dst = graph::V - 2;

    for (int i = -500; i <= 500; ++i) {
      const int j = i + 500;

      graph::add_edge(x, j, abs(x - j), 1 << 29);
      graph::add_edge(y, j, abs(y - j), 1 << 29);
      graph::add_edge(z, j, abs(z - j), 1 << 29);

      graph::add_edge(j, dst, 0, 1);
    }

    graph::add_edge(src, x, 0, r);
    graph::add_edge(src, y, 0, g);
    graph::add_edge(src, z, 0, b);

    cout << graph::min_cost_flow(src, dst, r + g + b) << endl;
  }

  return 0;
}
