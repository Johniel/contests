// github.com/Johniel/contests
// atcoder/abc409/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
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

constexpr lli mod = 998244353; // 1e9 + 7;

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

int main(int argc, char *argv[])
{
  int n, Q;
  while (cin >> n >> Q) {
    UnionFind uf(n + Q);
    vec<pair<int, int>> v;
    priority_queue<tuple<int, int, int>> q;

    const int N = 3000 + 3;
    static lli g[N][N];
    const lli inf = 1LL << 60;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        g[i][j] = inf;
      }
    }

    auto op1 = [&] () {
      int x, y;
      cin >> x >> y;
      for (int i = 0; i < v.size(); ++i) {
        int dx = abs(x - v[i].first);
        int dy = abs(y - v[i].second);
        int d = dx + dy;
        int j = uf.find(i);
        if (g[j][v.size()] > d) {
          g[j][v.size()] = d;
          q.push({-d, j, v.size()});
        }
      }
      v.push_back(make_pair(x, y));
      return ;
    };

    auto op2 = [&] () {
      while (q.size()) {
        auto [_, x, y] = q.top();
        unless (uf.same(x, y)) break;
        q.pop();
      }

      if (uf.size(0) == v.size()) cout << -1 << endl;
      else cout << abs(get<0>(q.top())) << endl;

      if (q.size()) {
        auto mn = get<0>(q.top());
        while (q.size()) {
          auto [d, x, y] = q.top();
          if (d != mn) break;
          uf.unite(x, y);
          q.pop();
        }
      }

      return ;
    };

    auto op3 = [&] () {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      cout << (uf.same(a, b) ? "Yes" : "No") << endl;
      return ;
    };

    for (int i = 0; i < n; ++i) op1();
    while (Q--) {
      int op;
      cin >> op;
      if (op == 1) op1();
      if (op == 2) op2();
      if (op == 3) op3();
    }
  }
  return 0;
}
