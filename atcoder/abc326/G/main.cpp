// github.com/Johniel/contests
// atcoder/abc326/G/main.cpp

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

const int N = 50; // skil
const int M = 50; // achievement
const int L = 5; // level

const int V = N * L + M + 5;
MaxFlow<V> g;

int main(int argc, char *argv[])
{
  const int lv = 5;
  int skill, achi;
  while (cin >> skill >> achi) {
    vec<lli> c(skill);
    vec<lli> a(achi);
    cin >> c >> a;
    lli l[achi][skill];
    for (int i = 0; i < achi; ++i) {
      for (int j = 0; j < skill; ++j) {
        cin >> l[i][j];
        --l[i][j];
      }
    }

    auto fa = [&] (int a) { return lv * skill + a; };
    auto fn = [&] (int s, int l) { return lv * s + l; };

    g.init();
    const lli inf = 1LL << 50;
    const int src = V - 1;
    const int dst = V - 2;
    for (int i = 0; i < skill; ++i) {
      for (int j = 0; j < lv; ++j) {
        if (j) g.add_edge(src, fn(i, j), c[i]);
      }
    }
    for (int i = 0; i < achi; ++i) {
      for (int j = 0; j < skill; ++j) {
        // g.add_edge(fn(j, l[i][j]), fa(i), inf);
        for (int k = 0; k <= l[i][j]; ++k) {
          g.add_edge(fn(j, k), fa(i), inf);
        }
      }
      g.add_edge(fa(i), dst, a[i]);
    }

    auto p = g.min_cut(src, dst);
    // cout << p.first << endl;
    cout << accumulate(a.begin(), a.end(), 0LL) - p.first << endl;



    // for (int i = 0; i < g.g.size(); ++i) {
    //   if (g.g[i].empty()) continue;
    //   each (e, g.g[i]) if (e.cap && e.flow) cout << e << ' '; cout << endl;
    // }

  }
  return 0;
}
