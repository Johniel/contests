// github.com/Johniel/contests
// yukicoder/2780/main.cpp

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

namespace {
  // https://atcoder.jp/contests/typical90/tasks/typical90_u

  const int N = 1e5 + 3;
  bool vis[N];

  void rec(vec<int> graph[N], int curr, int ord[], int &cnt)
  {
    vis[curr] = true;
    for (auto& next : graph[curr]) {
      unless (vis[next]) rec(graph, next, ord, cnt);
    }
    ord[--cnt] = curr;
    return ;
  }

  vector<int> g[N];
  vector<int> h[N];
  void init(const int size)
  {
    fill(g, g + size, vector<int>());
  }

  int ord[N];
  int scc[N];
  vector<vector<int>> detect_scc(const int size)
  {
    int cnt, prev = size - 1;
    vector<vector<int>> ret;
    fill(ord, ord + size, -1);
    fill(scc, scc + size, -1);
    fill(h, h + size, vector<int>());
    for (int curr = 0; curr < size; ++curr) {
      for (const auto& next : g[curr]) {
        h[next].push_back(curr);
      }
    }
    cnt = size;
    fill(vis, vis + N, false);
    for (int i = 0; i < size; ++i) {
      unless (vis[i]) rec(g, i, ord, cnt);
    }
    cnt = size;
    fill(vis, vis + N, false);
    for (int i = 0; i < size; ++i) {
      unless (vis[ord[i]]) {
        rec(h, ord[i], scc, cnt);
        int j = prev;
        vector<int> T;
        for (j = prev; 0 <= j && scc[j] != -1; --j) T.push_back(scc[j]);
        prev = j;
        ret.push_back(T);
      }
    }
    return ret;
  }
};

using Graph = vector<vector<int>>;
bool visit(const Graph &g, int curr, vector<int> &order, vector<int> &color)
{
  constexpr int CLOSED = 1;
  constexpr int VISITED = 2;
  color[curr] = CLOSED;
  each (next, g[curr]) {
    if (color[next] == VISITED) continue;
    if (color[next] == CLOSED) return false;
    if (!visit(g, next, order, color)) return false;
  }
    order.push_back(curr);
  color[curr] = VISITED;
  return true;
}
// verified Codeforces Round #847 C
bool toporogical_sort(const Graph &g, vector<int> &order)
{
  const int size = g.size();
  vector<int> color(size, 0);
  for (int i = 0; i < size; ++i) {
    if (!color[i] && !visit(g, i, order, color)) {
      return false;
    }
  }
  reverse(order.begin(), order.end());
  return true;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    init(n);
    vec<pair<int, int>> es;
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;
      for (int j = 0; j < m; ++j) {
        int x;
        cin >> x;
        --x;
        g[i].push_back(x);
        es.push_back(make_pair(i, x));
      }
    }
    auto v = detect_scc(n);
    map<int, int> m;
    for (int i = 0; i < v.size(); ++i) {
      each (j, v[i]) m[j] = i;
    }
    decltype(es) u;
    each (e, es) {
      e.first = m[e.first];
      e.second = m[e.second];
      if (e.first != e.second) u.push_back(e);
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());

    Graph tg(v.size());
    each (i, u) {
      tg[i.first].push_back(i.second);
    }
    vec<int> ord;
    bool f = toporogical_sort(tg, ord);

    f = f && (ord[0] == m[0]);
    for (int i = 0; i + 1 < ord.size(); ++i) {
      f = f && binary_search(u.begin(), u.end(), make_pair(ord[i], ord[i + 1]));
    }
    cout << (f ? "Yes" : "No") << endl;
  }
  return 0;
}
