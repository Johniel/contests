// github.com/Johniel/contests
// atcoder/arc031/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
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

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vec<int> exp(n);
    vec<int> cost(m);
    cin >> exp >> cost;
    vec<vec<int>> v;
    for (int i = 0; i < exp.size(); ++i) {
      int k;
      cin >> k;
      vec<int> u(k);
      cin >> u;
      each (j, u) --j;
      v.push_back(u);
    }

    constexpr int N = 100;
    constexpr int M = 100;
    constexpr int K = N + M + 2;
    const int src = K - 1;
    const int snk = K - 2;

    const int Y = 10000;

    auto fn = [&] (lli x) {
      Dinic<lli, K> dinic;
      lli sum = 0;
      for (int i = 0; i < exp.size(); ++i) {
        sum += exp[i] * Y;
        dinic.add_edge(src, i, exp[i] * Y);
      }
      for (int i = 0; i < exp.size(); ++i) {
        each (j, v[i]) {
          dinic.add_edge(i, exp.size() + j, (1LL << 29) * Y);
        }
      }
      for (int j = 0; j < cost.size(); ++j) {
        dinic.add_edge(exp.size() + j, snk, cost[j] * x);
      }
      return sum <= dinic.run(src, snk);
    };

    lli small = 0;
    lli large = 1LL << 50;
    while (small + 1 < large) {
      auto mid = (small + large) / 2;
      if (fn(mid)) large = mid;
      else small = mid;
    }
    if (fn(small)) cout << small/double(Y) << endl;
    else cout << large/double(Y) << endl;
  }
  return 0;
}
