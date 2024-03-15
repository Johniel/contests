// github.com/Johniel/contests
// atcoder/abc320/G/main.cpp

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

namespace {
  // verified: ABBC274G,ARC031D
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

    void init(int n)
    {
      // fill(g.begin(), g.end(), array<vector<E>, N>());
      assert(n < N);
      for (int i = 0; i < n; ++i) g[i].clear();
    }

    void add_edge(int src, int dst, Cap c)
    {
      int a = g[src].size();
      int b = g[dst].size();
      g[src].push_back(E(src, dst, c, b));
      g[dst].push_back(E(dst, src, 0, a));
      return ;
    }

    bool bfs(const int src, const int dst, const int size)
    {
      const int inf = 1 << 29;
      fill(dist.begin(), dist.begin() + size, inf);
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

    Cap run(const int src, const int snk, const int size)
    {
      Cap sum = 0;
      while (bfs(src, snk, size)) {
        fill(idx.begin(), idx.begin() + size, 0);
        for (Cap f; 0 < (f = rec(src, snk, numeric_limits<Cap>::max())); sum += f) ;
      }
      return sum;
    }
  };
};

const int N = 1e7;
Dinic<int, N> dinic;

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vec<str> v(n);
    cin >> v;
    vec<int> x[100][10];
    for (int c = 0; c <= 9; ++c) {
      for (int i = 0; i < v.size(); ++i) {
        vec<int> u;
        for (int j = 0; j < v[i].size(); ++j) {
          if (c + '0' == v[i][j]) u.push_back(j);
        }
        if (u.size()) {
          for (int k = 0; x[i][c].size() <= n; ++k) {
            int y = u[k % u.size()] + (k / u.size()) * v[i].size();
            if (n * m < y) break;
            x[i][c].push_back(y);
          }
        }
      }
    }
    vec<int> y[10];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 10; ++j) {
        each (k, x[i][j]) y[j].push_back(k);
      }
    }
    for (int i = 0; i < 10; ++i) {
      sort(y[i].begin(), y[i].end());
      y[i].erase(unique(y[i].begin(), y[i].end()), y[i].end());
    }
    auto fn = [&] (const int T) {
      for (int c = 0; c <= 9; ++c) {
        int B = 0;
        map<int, int> inv;
        each (t, y[c]) {
          if (T <= t) break;
          inv[t] = B;
          ++B;
        }
        const int K = B + v.size() + 2;
        const int src = K - 1;
        const int snk = K - 2;
        dinic.init(K);
        for (int reel = 0; reel < v.size(); ++reel) {
          dinic.add_edge(reel + B, snk, 1);
        }
        vec<int> R(v.size(), 0);
        for (int reel = 0; reel < v.size(); ++reel) {
          each (t, x[reel][c]) {
            if (T <= t) break;
            dinic.add_edge(inv[t], reel + B, 1);
            ++R[reel];
          }
        }
        if (count(R.begin(), R.end(), 0)) continue;
        for (int t = 0; t < B; ++t) {
          dinic.add_edge(src, t, 1);
        }
        if (dinic.run(src, snk, K) == v.size()) return true;
      }
      return false;
    };
    int small = 0;
    int large = n * m;
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if (fn(mid)) large = mid;
      else small = mid;
    }
    if (fn(large)) cout << large - 1 << endl;
    else cout << -1 << endl;
  }
  return 0;
}
