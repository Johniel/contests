// github.com/Johniel/contests
// codeforces/944div4/H/main.cpp

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


// https://codeforces.com/blog/entry/129364
// 解説がそもそもatcoder libraryで書かれている。
namespace atcoder {
  namespace internal {

    template <class E> struct csr {
      std::vector<int> start;
      std::vector<E> elist;
      csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
          start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
          start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
          elist[counter[e.first]++] = e.second;
        }
      }
    };

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
    struct scc_graph {
    public:
      scc_graph(int n) : _n(n) {}

      int num_vertices() { return _n; }

      void add_edge(int from, int to) { edges.push_back({from, {to}}); }

      // @return pair of (# of scc, scc id)
      std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
          low[v] = ord[v] = now_ord++;
          visited.push_back(v);
          for (int i = g.start[v]; i < g.start[v + 1]; i++) {
            auto to = g.elist[i].to;
            if (ord[to] == -1) {
              self(self, to);
              low[v] = std::min(low[v], low[to]);
            } else {
              low[v] = std::min(low[v], ord[to]);
            }
          }
          if (low[v] == ord[v]) {
            while (true) {
              int u = visited.back();
              visited.pop_back();
              ord[u] = _n;
              ids[u] = group_num;
              if (u == v) break;
            }
            group_num++;
          }
        };
        for (int i = 0; i < _n; i++) {
          if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
          x = group_num - 1 - x;
        }
        return {group_num, ids};
      }

      std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
          groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
          groups[ids.second[i]].push_back(i);
        }
        return groups;
      }

    private:
      int _n;
      struct edge {
        int to;
      };
      std::vector<std::pair<int, edge>> edges;
    };

  }  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

// Reference:
// B. Aspvall, M. Plass, and R. Tarjan,
// A Linear-Time Algorithm for Testing the Truth of Certain Quantified Boolean
// Formulas
  struct two_sat {
  public:
    two_sat() : _n(0), scc(0) {}
    two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

    void add_clause(int i, bool f, int j, bool g) {
      assert(0 <= i && i < _n);
      assert(0 <= j && j < _n);
      scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
      scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
      auto id = scc.scc_ids().second;
      for (int i = 0; i < _n; i++) {
        if (id[2 * i] == id[2 * i + 1]) return false;
        _answer[i] = id[2 * i] < id[2 * i + 1];
      }
      return true;
    }
    std::vector<bool> answer() { return _answer; }

  private:
    int _n;
    std::vector<bool> _answer;
    internal::scc_graph scc;
  };

}  // namespace atcoder

using namespace atcoder;

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n;
  while (cin >> n) {
    int a[3][n];
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
      }
    }
    two_sat ts(n);
    for (int j = 0; j < n; ++j) {
      for (int x = 0; x < 3; ++x) {
        int y = (x + 1) % 3;
        int X = abs(a[x][j]) - 1;
        int Y = abs(a[y][j]) - 1;
        ts.add_clause(X, 0 < a[x][j], Y, 0 < a[y][j]);
      }
    }
    cout << (ts.satisfiable() ? "Yes" : "No") << endl;
  }
  return 0;
}
