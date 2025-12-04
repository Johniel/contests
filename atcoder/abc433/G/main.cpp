// github.com/Johniel/contests
// atcoder/abc433/G/main.cpp

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

// https://yosupo.hatenablog.com/entry/2021/01/31/160215
struct SuffixAutomaton {
  struct Node {
    unordered_map<char, int> next;
    int link;
    int len;
  };
  vector<Node> nodes;
  int last;

  SuffixAutomaton() {
    nodes.push_back({{}, -1, 0});
    last = 0;
  }

  void push(str s) { for (const auto& c: s) push(c); }

  void push(char c) {
    int new_node = int(nodes.size());
    nodes.push_back({{}, -1, nodes[last].len + 1});
    int p = last;
    while (p != -1 && nodes[p].next.find(c) == nodes[p].next.end()) {
      nodes[p].next[c] = new_node;
      p = nodes[p].link;
    }
    int q = (p == -1 ? 0 : nodes[p].next[c]);
    if (p == -1 || nodes[p].len + 1 == nodes[q].len) {
      nodes[new_node].link = q;
    } else {
      int new_q = int(nodes.size());
      nodes.push_back({nodes[q].next, nodes[q].link, nodes[p].len + 1});
      nodes[q].link = new_q;
      nodes[new_node].link = new_q;

      while (p != -1 && nodes[p].next[c] == q) {
        nodes[p].next[c] = new_q;
        p = nodes[p].link;
      }
    }
    last = new_node;
  }
};

map<int, int> memo;
int rec(SuffixAutomaton& sa, int curr)
{
  if (memo.count(curr)) return memo[curr];

  int opt = -1;
  for (char c = 'a'; c <= 'z'; ++c) {
    if (sa.nodes[curr].next.count(c)) {
      int x = rec(sa, sa.nodes[curr].next[c]);
      x *= -1;
      setmax(opt, x);
    }
  }

  return memo[curr] = opt;
}

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  str s;
  while (cin >> s) {
    SuffixAutomaton sa;
    sa.push(s);
    memo.clear();
    int x = rec(sa, 0);
    cout << (0 < x ? "Alice" : "Bob") << endl;
  }
  return 0;
}
