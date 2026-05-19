// github.com/Johniel/contests
// atcoder/awc0071/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& v) { os << "("; for (const auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, const set<T>& s) { os << "set{"; for (const auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, const map<K, V>& m) { os << "map{"; for (const auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (const auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, const deque<T>& q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
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

constexpr lli mod = 998244353; // 1e9 + 7;

struct HopcroftKarp {
  vector<vector<int>> graph;
  vector<int> dist;
  vector<int> match;
  vector<bool> used;
  vector<bool> vis;

  HopcroftKarp(int left, int right) : graph(left), match(right, -1), used(left) {}

  // 0 <= src < left
  // 0 <= dst < right
  void add_edge(int src, int dst) {
    assert(src < graph.size());
    assert(dst < match.size());
    graph[src].push_back(dst);
    return ;
  }

  void bfs(void) {
    dist.assign(graph.size(), -1);
    queue<int> q;
    for (size_t i = 0; i < graph.size(); ++i) {
      if (!used[i]) {
        q.push(i);
        dist[i] = 0;
      }
    }
    for (; q.size(); q.pop()) {
      const int curr = q.front();
      for (const int next: graph[curr]) {
        int c = match[next];
        if (0 <= c && dist[c] == -1) {
          dist[c] = dist[curr] + 1;
          q.push(c);
        }
      }
    }
    return ;
  }

  bool rec(int curr) {
    vis[curr] = true;
    for (const int next: graph[curr]) {
      int c = match[next];
      if (c < 0 || (!vis[c] && dist[c] == dist[curr] + 1 && rec(c))) {
        match[next] = curr;
        used[curr] = true;
        return true;
      }
    }
    return false;
  }

  int bipartite_matching(void) {
    int ret = 0;
    vis.resize(graph.size());
    while (true) {
      bfs();
      fill(vis.begin(), vis.end(), false);
      int aug = 0;
      for (size_t i = 0; i < graph.size(); ++i) {
        if (!used[i] && rec(i)) ++aug;
      }
      if (aug == 0) break;
      ret += aug;
    }
    return ret;
  }
};

constexpr int N = 1e5;
vec<int> g[N];
void rec(int curr, int p, vec<int>& c)
{
  c[curr] = p;
  each (next, g[curr]) {
    if (c[next] == -1) rec(next, p ^ 1, c);
  }
  return ;
}

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    fill(g, g + n, vec<int>());
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vec<int> color(n, -1);
    for (int i = 0; i < n; ++i) {
      if (color[i] == -1) rec(i, 0, color);
    }
    vec<int> rename(n);
    int _0 = 0;
    int _1 = 0;
    for (int i = 0; i < n; ++i) {
      if (color[i] == 0) rename[i] = _0++;
      if (color[i] == 1) rename[i] = _1++;
    }
    HopcroftKarp hk(_0, _1);
    for (int i = 0; i < n; ++i) {
      if (color[i] == 0) {
        each (j, g[i]) hk.add_edge(rename[i], rename[j]);
      }
    }
    cout << hk.bipartite_matching() << endl;
  }
  return 0;
}
