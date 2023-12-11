// github.com/Johniel/contests
// atcoder/arc039/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
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

struct UnionFind {
  vector<int> r, p;
  UnionFind(int n) {
    r.resize(n, 0);
    p.resize(n, -1);
  }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return ;
    if (r[a] > r[b]) {
      p[a] += p[b];
      p[b] = a;
    } else {
      p[b] += p[a];
      p[a] = b;
      if (r[a] == r[b]) ++r[b];
    }
    return ;
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
// 橋だけhttps://atcoder.jp/contests/abc266/tasks/abc266_fでverify
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
    return ;
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

// ARC039D
vector<vector<int>> biconnected_component(const vector<vector<int>>& graph)
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

const int N = 1e5 + 3;
namespace LCA {
  int parent[N];

  const int LOG2N = log2(N) + 1;
  int T[N][LOG2N], L[N];

  int addLevel(int node)
  {
    if (L[node] != -1) return L[node];
    else return L[node] = addLevel(parent[node]) + 1;
  }

  // ! keep parent[root] = root
  void build(int n)
  {
    const int root = 0;
    fill(L, L + n, -1);
    L[root] = 0;
    for (int i = 0; i < n; ++i) {
      L[i] = addLevel(i);
    }

    fill(&T[0][0], &T[N - 1][LOG2N], -1);
    for (int i = 0; i < n; ++i) {
      T[i][0] = parent[i];
    }
    for (int j = 1; (1 << j) < n; ++j) {
      for (int i = 0; i < n; ++i) {
        if (T[i][j - 1] != -1) {
          T[i][j] = T[T[i][j - 1]][j - 1];
        }
      }
    }
    return ;
  }

  int query(int a, int b)
  {
    if (L[a] < L[b]) swap(a, b);

    int lg = 1;
    while ((1 << lg) <= L[a]) ++lg;
    --lg;

    for (int i = lg; 0 <= i; --i) {
      if (L[a] - (1 << i) >= L[b]) {
        a = T[a][i];
      }
    }

    if (a == b) return a;
    for (int i = lg; 0 <= i; --i) {
      if (T[a][i] != -1 && T[a][i] != T[b][i]) {
        a = T[a][i];
        b = T[b][i];
      }
    }
    return parent[a];
  }
};

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vec<vec<int>> g(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vec<vec<int>> bc = biconnected_component(g);
    map<int, int> rename;
    for (int i = 0; i < bc.size(); ++i) {
      each (j, bc[i]) rename[j] = i;
    }

    vec<vec<int>> u(bc.size());
    {
      set<pair<int, int>> vis;
      for (int i = 0; i < n; ++i) {
        each (j, g[i]) {
          int a = rename[i];
          int b = rename[j];
          pair<int, int> x = make_pair(a, b);
          pair<int, int> y = make_pair(b, a);
          if (a != b && !vis.count(x)) {
            vis.insert(x);
            vis.insert(y);
            u[a].push_back(b);
            u[b].push_back(a);
          }
        }
      }
    }
    fill(LCA::parent, LCA::parent + N, -1);
    function<void(int, int)> rec = [&] (int curr, int prev) {
      LCA::parent[curr] = prev;
      each (next, u[curr]) {
        if (next != prev && LCA::parent[next] == -1) rec(next, curr);
      }
      return ;
    };
    rec(0, 0);
    LCA::build(bc.size());

    int q;
    cin >> q;
    while (q--) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      --c;
      a = rename[a];
      b = rename[b];
      c = rename[c];

      int ab = LCA::query(a, b);
      int bc = LCA::query(b, c);
      int ac = LCA::query(a, c);

      if (a == b || b == c) {
        cout << "OK" << endl;
        continue;
      }
      if (ab == bc && ac == b) {
        cout << "OK" << endl;
        continue;
      }
      if (ab == ac && bc == b) {
        cout << "OK" << endl;
        continue;
      }
      if (ab == b && bc == ac) {
        cout << "OK" << endl;
        continue;
      }
      cout << "NG" << endl;
    }
    // cout << endl;
  }
  return 0;
}
