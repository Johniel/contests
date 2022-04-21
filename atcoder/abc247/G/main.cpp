// atcoder/abc247/G/main.cpp
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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

namespace min_cost_flow {
  using Cap = long long int;
  using Cost = long long int;
  const Cost inf = (1LL << 40);

  struct E {
    int src, dst;
    Cap cap, flow;
    Cost cost;
    int rev;
    E(int s, int d, Cap cap_, Cost cost_, int r) : src(s), dst(d), cap(cap_), cost(cost_), rev(r), flow(0) {}
    Cap residue(void) const { return cap - flow; }
  };
  typedef vector<E> Es;
  typedef vector<Es> G;

  // max node conut
  const int N = 320;

  pair<int, int> path[N]; // path[dst]:=(src,index of e)
  Cost dist[N];
  Cost potential[N];

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

  bool sssp(const G &g, const int src, const int snk)
  {
    const int size = g.size();
    fill(dist, dist + size, inf);
    dist[src] = 0;
    path[src] = {src, -1};
    using S = pair<Cost, int>;
    priority_queue<S, vector<S>, greater<S>> q;
    for (q.push({0, src}); q.size();) {
      const S next = q.top();
      q.pop();
      if (dist[next.second] != next.first) continue;
      if (next.second == snk) break;
      for (int i = 0; i < g[next.second].size(); ++i) {
        const E& e = g[next.second][i];
        if (e.residue() <= 0) continue;
        const Cost rcost = e.cost + (potential[e.src] - potential[e.dst]);
        if (dist[e.dst] > rcost + dist[e.src]) {
          dist[e.dst] = rcost + dist[e.src];
          q.push({dist[e.dst], e.dst});
          path[e.dst] = make_pair(e.src, i);
        }
      }
    }
    return dist[snk] != inf;
  }

  vec<lli> abc247g;
  pair<Cost, Cap> run(G g, const int src, const int snk, Cap req)
  {
    assert(src < g.size());
    assert(snk < g.size());

    const int size = g.size();
    fill(potential, potential + size, 0);
    pair<Cost, Cap> result = {0, 0};
    while (0 < req && sssp(g, src, snk)) {
      for (int i = 0; i < size; ++i) {
        potential[i] += dist[i];
      }
      Cap mn = req;
      for (int i = snk; i != path[i].first; i = path[i].first) {
        const int v = path[i].first;
        const int e = path[i].second;
        mn = min(mn, g[v][e].residue());
      }
      for (int i = snk; i != path[i].first; i = path[i].first) {
        const int v = path[i].first;
        const int e = path[i].second;
        result.first += mn * g[v][e].cost;
        g[v][e].flow += mn;
        g[g[v][e].dst][g[v][e].rev].flow -= mn;
      }
      req -= mn;
      result.second += mn;
      abc247g.push_back(result.first);
    }
    return result;
  }
};
namespace mcf = min_cost_flow;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    const int src = 304;
    const int snk = 305;
    mcf::G g(310, mcf::Es());
    for (int i = 0; i < 150; ++i) {
      const int j = i + 150;
      mcf::add_edge(g, src, i, 1, 0);
      mcf::add_edge(g, j, snk, 1, 0);
    }
    const lli inf = 1LL << 30;
    for (int i = 0; i < n; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      mcf::add_edge(g, a, b + 150, 1, inf - c);
    }
    mcf::abc247g.clear();
    mcf::run(g, src, snk, (1 << 29));
    cout << mcf::abc247g.size() << endl;
    lli z = 0;
    each (i, mcf::abc247g) {
      z += inf;
      cout << z - i << endl;
    }
  }

  return 0;
}
