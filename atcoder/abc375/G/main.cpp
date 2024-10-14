// github.com/Johniel/contests
// atcoder/abc375/G/main.cpp

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

struct UnionFind {
  vector<int> r, p;
  UnionFind(int n): r(n, 0), p(n, -1) {}
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (r[a] > r[b]) swap(a, b);
    p[b] += p[a];
    p[a] = b;
    if (r[a] == r[b]) ++r[b];
    return true;
  }
  int find(int a) {
    return (p[a] < 0) ? a : p[a] = find(p[a]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  size_t size(int n) {
    return -p.at(find(n));
  }
};


struct LowLink {
  // 橋: ABC266F
  // 関節点: ARC045D
  using graph = vector<vector<int>>;
  vector<bool> vis;
  vector<int> ord, low;
  vector<pair<int, int>> bs; // bridges
  vector<int> as; // articulation points
  graph g;
  void run(const graph& g_)
  {
    g = g_;
    const int n = g.size();
    vis.resize(n, false);
    ord.resize(n, 0);
    low.resize(n, 0);
    int k = 0;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) k = rec(i, k, -1);
    }
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
  }
  int rec(int curr, int k, int prev)
  {
    vis[curr] = true;
    ord[curr] = k++;
    low[curr] = ord[curr];
    bool f = false;
    int cnt = 0;
    for (auto &next: g[curr]) {
      if (next == prev) continue;
      if (vis[next]) { // 後退辺
        low[curr] = min(low[curr], ord[next]);
      } else {
        ++cnt;
        k = rec(next, k, curr);
        low[curr] = min(low[curr], low[next]);
        f = f || (prev != -1 && ord[curr] <= low[next]);
        if (ord[curr] < low[next]) {
          bs.push_back({min(curr, next), max(curr, next)});
        }
      }
    }
    if (prev == -1 && 2 <= cnt) f = true;
    if (f) as.push_back(curr);
    return k;
  }
};

// 橋を除いた部分グラフ
// ARC039D
vector<vector<int>> two_edge_connected_components(const vector<vector<int>>& graph)
{
  LowLink ll;
  ll.run(graph);
  set<pair<int, int>> bridges(ll.bs.begin(), ll.bs.end());
  const int n = graph.size();
  UnionFind uf(n);
  for (int i = 0; i < graph.size(); ++i) {
    for (int k = 0; k < graph[i].size(); ++k) {
      int j = graph[i][k];
      pair<int, int> a = make_pair(i, j);
      pair<int, int> b = make_pair(j, i);
      unless (bridges.count(a) || bridges.count(b)) {
        uf.unite(i, j);
      }
    }
  }
  for (int i = 0; i < n; ++i) uf.find(i);
  vector<vector<int>> component;
  map<int, int> c;
  for (int i = 0; i < n; ++i) {
    int x = uf.find(i);
    if (!c.count(x)) {
      c[x] = c.size();
      component.push_back(vector<int>());
    }
    component[c[x]].push_back(i);
  }
  return component;
}

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    const int M = 2 * 1e5 + 3;
    int a[M], b[M];
    lli c[M];
    const int N = 2 * 1e5 + 3;
    vec<pair<int, lli>> g[N];
    for (int i = 0; i < m; ++i) {
      cin >> a[i] >> b[i] >> c[i];
      --a[i];
      --b[i];
      g[a[i]].push_back(make_pair(b[i], c[i]));
      g[b[i]].push_back(make_pair(a[i], c[i]));
    }

    const lli inf = 1LL << 60;
    auto sssp = [&] (const int src, vec<lli>& cost) {
      cost.resize(n, inf);
      cost[src] = 0;
      priority_queue<pair<lli, int>> q;
      q.push(make_pair(cost[src], src));
      while (q.size()) {
        auto [d, curr] = q.top();
        q.pop();
        d = abs(d);
        if (cost[curr] != d) continue;
        each (e, g[curr]) {
          auto [next, w] = e;
          if (cost[next] > d + w) {
            cost[next] = d + w;
            q.push(make_pair(-cost[next], next));
          }
        }
      }
      return ;
    };
    vec<lli> dist1, dist2;
    sssp(0, dist1);
    sssp(n - 1, dist2);

    LowLink::graph sp(n);
    for (int i = 0; i < m; ++i) {
      if (dist1[n - 1] == dist1[a[i]] + c[i] + dist2[b[i]] ||
          dist1[n - 1] == dist1[b[i]] + c[i] + dist2[a[i]]) {
        sp[a[i]].push_back(b[i]);
        sp[b[i]].push_back(a[i]);
      }
    }

    LowLink ll;
    ll.run(sp);
    sort(ll.bs.begin(), ll.bs.end());
    for (int i = 0; i < m; ++i) {
      pair<int, int> e1 = make_pair(a[i], b[i]);
      pair<int, int> e2 = make_pair(b[i], a[i]);
      bool f = false;
      if (binary_search(ll.bs.begin(), ll.bs.end(), e1)) f = true;
      if (binary_search(ll.bs.begin(), ll.bs.end(), e2)) f = true;
      cout << (f ? "Yes" : "No") << endl;
    }
  }
  return 0;
}
