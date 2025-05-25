// github.com/Johniel/contests
// atcoder/abc407/G/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

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

namespace min_cost_flow {
  using Cap = long long int;
  using Cost = long long int;

  struct E {
    int src, dst;
    Cap cap, flow;
    Cost cost;
    int rev;
    E(int s, int d, Cap cap_, Cost cost_, int r) : src(s), dst(d), cap(cap_), cost(cost_), rev(r), flow(0) {}
    Cap residue(void) const { return cap - flow; }
  };
  using G = vector<vector<E>>;

  void add_edge(G& g, const int src, const int dst, const Cap cap, const Cost cost)
  {
    assert(src < g.size());
    assert(dst < g.size());
    const int s = g[src].size();
    const int d = g[dst].size();
    g[src].push_back(E(src, dst, cap, +cost, d));
    g[dst].push_back(E(dst, src, 0,   -cost, s));
    return ;
  }

  const int N = 2000 + 30;
  // 負のコストを消すためにoffsetを使う可能性を忘ない
  const Cost offset = 2000000000000;

  pair<int, int> path[N]; // path[dst]:={src,index of e}
  Cost dist[N];
  Cost potential[N];

  bool sssp(const G &g, const int src, const int snk)
  {
    const Cost inf = (1LL << 60);
    const int size = g.size();
    fill(dist, dist + size, inf);
    dist[src] = 0;
    path[src] = make_pair(src, -1);
    using S = pair<Cost, int>;
    priority_queue<S, vector<S>, greater<S>> q;
    for (q.push({0, src}); q.size(); ) {
      const auto [cost, curr] = q.top();
      q.pop();
      if (dist[curr] != cost) continue;
      if (curr == snk) break;
      for (size_t i = 0; i < g[curr].size(); ++i) {
        const E& e = g[curr][i];
        if (e.residue() <= 0) continue;
        const Cost rcost = e.cost + (potential[e.src] - potential[e.dst]);
        if (dist[e.dst] > rcost + dist[e.src]) {
          dist[e.dst] = rcost + dist[e.src];
          q.push(make_pair(dist[e.dst], e.dst));
          path[e.dst] = make_pair(e.src, i);
        }
      }
    }
    return dist[snk] != inf;
  }

  vector<pair<Cost, Cap>> run(G& g, const int src, const int snk, Cap req)
  {
    assert(src < g.size());
    assert(snk < g.size());
    vector<pair<Cost, Cap>> slope;
    const int size = g.size();
    fill(potential, potential + size, 0);
    Cost cost = 0;
    Cap flow = 0;
    slope.push_back(make_pair(cost, flow));
    while (0 < req && sssp(g, src, snk)) {
      for (int i = 0; i < size; ++i) {
        potential[i] += dist[i];
      }
      Cap mn = req;
      for (int i = snk; i != path[i].first; i = path[i].first) {
        auto [v, e] = path[i];
        mn = min(mn, g[v][e].residue());
      }
      for (int i = snk; i != path[i].first; i = path[i].first) {
        auto [v, e] = path[i];
        cost += mn * g[v][e].cost;
        g[v][e].flow += mn;
        g[g[v][e].dst][g[v][e].rev].flow -= mn;
      }
      req -= mn;
      flow += mn;
      slope.push_back(make_pair(cost, flow));
    }
    return slope;
  }
};
namespace mcf = min_cost_flow;


int main(int argc, char *argv[])
{
  int h, w;
  while (cin >> h >> w) {
    lli a[h][w];
    int name[h][w];
    int cnt = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> a[i][j];
        name[i][j] = cnt++;
      }
    }

    int color[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        color[i][j] = (i + j) % 2;
      }
    }

    const int N = h * w + 2;
    const int src = N - 1;
    const int snk = N - 2;
    min_cost_flow::G g(N);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (color[i][j]) {
          min_cost_flow::add_edge(g, name[i][j], snk, 1, 0);
        } else {
          min_cost_flow::add_edge(g, src, name[i][j], 1, 0);
          for (int d = 0; d < 4; ++d) {
            constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
            constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
            const int ni = i + di[d];
            const int nj = j + dj[d];
            unless (0 <= ni && ni < h) continue;
            unless (0 <= nj && nj < w) continue;
            min_cost_flow::add_edge(g, name[i][j], name[ni][nj], 1, a[i][j] + a[ni][nj] + min_cost_flow::offset);
          }
        }
      }
    }
    lli z = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        z += a[i][j];
      }
    }
    auto v = min_cost_flow::run(g, src, snk, 1LL << 60);
    lli mx = -(1LL << 62);
    for (int i = 0; i < v.size(); ++i) {
      lli x = z - (v[i].first - v[i].second * min_cost_flow::offset);
      setmax<lli>(mx, x);
    }
    cout << mx << endl;
  }
  return 0;
}
