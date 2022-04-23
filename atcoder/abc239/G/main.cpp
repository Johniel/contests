// atcoder/abc239/G/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
//#define endl "\n"

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
    os << "E{(" << e.src << "," << e.dst << "),(" << e.cap << "," << e.flow << ")," << e.rev << "}";
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
MaxFlow<300> g;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    g.init();
    vec<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      v.push_back({a, b});
    }

    vec<int> c(n);
    cin >> c;

    int in[n];
    int out[n];
    int cnt = 0;
    map<int, int> rev;
    for (int i = 0; i < n; ++i) {
      in[i] = cnt++;
      out[i] = cnt++;
      rev[in[i]] = i;
    }
    const lli inf = 1LL << 50;

    for (int i = 0; i < n; ++i) {
      g.add_edge(in[i], out[i], (c[i] ? c[i] : inf));
    }
    each (e, v) {
      g.add_edge(out[e.first], in[e.second], inf);
      g.add_edge(out[e.second], in[e.first], inf);
    }
    pair<lli, vec<E>> cut = g.min_cut(in[0], out[n - 1]);
    cout << cut.first << endl;
    cout << cut.second.size() << endl;
    each (e, cut.second) cout << rev[e.src] + 1 << ' ';
    cout << endl;
  }
  return 0;
}
