// github.com/Johniel/contests
// atcoder/arc045/D/main.cpp

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
  vector<int> representatives(void) {
    vector<int> v;
    for (int i = 0; i < r.size(); ++i) {
      if (i == find(i)) v.push_back(i);
    }
    return v;
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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<pair<int, int>> v(2 * n + 1);
    cin >> v;

    map<int, vec<pair<int, int>>> x, y;
    for (int i = 0; i < v.size(); ++i) {
      const auto& [a, b] = v[i];
      x[a].push_back(make_pair(b, i));
      y[b].push_back(make_pair(a, i));
    }
    each (i, x) sort(i.second.begin(), i.second.end());
    each (i, y) sort(i.second.begin(), i.second.end());

    LowLink::graph g(v.size());
    UnionFind uf(v.size());
    auto fn = [&] (const decltype(x)& m) {
      each (k, m) {
        const auto& v = k.second;
        for (int i = 0; i < v.size(); ++i) {
          for (int j = i + 1, _ = 0; j < v.size() && _ < 2; ++j, ++_) {
            const int x = v[i].second;
            const int y = v[j].second;
            g[x].push_back(y);
            g[y].push_back(x);
            uf.unite(x, y);
          }
        }
      }
      return ;
    };
    fn(x);
    fn(y);
    LowLink ll;
    ll.run(g);

    vec<bool> r(v.size(), false);
    {
      int x = 0;
      each (i, uf.representatives()) x += (uf.size(i) % 2);
      if (x == 1) {
        for (int i = 0; i < v.size(); ++i) {
          r[i] = (uf.size(i) % 2);
        }
      }
    }
    {
      vec<int> sz(v.size(), 0);
      function<int(int, int)> rec = [&] (int curr, int prev) {
        sz[curr] = 1;
        const bool isa = binary_search(ll.as.begin(), ll.as.end(), curr);
        each (next, g[curr]) {
          if (next == prev || sz[next]) continue;
          sz[curr] += rec(next, curr);
          if (sz[next] % 2 && isa && (ll.ord[curr] <= ll.low[next])) r[curr] = false;
        }
        return sz[curr];
      };
      for (int i = 0; i < v.size(); ++i) {
        if (!sz[i] && r[i]) rec(i, i);
      }
    }

    for (int i = 0; i < v.size(); ++i) cout << (r[i] ? "OK" : "NG") << endl;
    // cout << endl;
  }
  return 0;
}
