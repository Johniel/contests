// github.com/Johniel/contests
// atcoder/abc474/E/main.cpp

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

struct PrefixTree {
  vector<map<char, int>> nodes;
  vector<int> accept;
  vector<int> children;
  PrefixTree() { make_node(); }
  int make_node(void) {
    nodes.push_back(map<char, int>());
    accept.push_back(0);
    children.push_back(0);
    return nodes.size() - 1;
  }
  // O(|S|),sをm個insertする
  void _insert(const string& s, const int m) {
    int curr = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      curr = nodes[curr].count(s[i]) ? nodes[curr][s[i]] : nodes[curr][s[i]] = make_node();
      children[curr] += m;
    }
    accept[curr] += m;
    return ;
  }
  void insert(const string& s, const int m = 1) {
    assert(0 <= m);
    if (m) _insert(s, m);
  }
  void erase(const string& s, const int m = -1) {
    assert(m <= 0);
    if (m) _insert(s, m);
  }
  // O(|S|),sのprefixに一致する文字列がいくつinsertされているか長さ別に答える。
  vector<int> count(const string& s) {
    int curr = 0;
    vector<int> v;
    for (size_t i = 0; i < s.size(); ++i) {
      if (nodes[curr].count(s[i]) == 0) break;
      curr = nodes[curr][s[i]];
      v.push_back(children[curr]);
    }
    while (v.size() < s.size()) v.push_back(0);
    return v;
  }
  // NOT VERIFIED
  // O(|S|),sに一致する文字列がいくつinsertされているか数える。
  int match(const string& s) {
    int curr = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      if (nodes[curr].count(s[i]) == 0) return 0;
      curr = nodes[curr][s[i]];
    }
    return accept[curr];
  }

  struct iterator {
    int node_idx;
    const PrefixTree* tree;
    iterator(const PrefixTree* t, int idx) : tree(t), node_idx(idx) {}
    void next(const char& c) {
      auto itr = tree->nodes[node_idx].find(c);
      if (itr != tree->nodes[node_idx].end()) {
        node_idx = itr->second;
      } else {
        node_idx = -1;
      }
    }
    int children(void) {
      assert(node_idx != -1);
      return tree->children[node_idx];
    }
    int accept(void) {
      assert(node_idx != -1);
      return tree->accept[node_idx];
    }
    bool operator == (iterator other) {
      return other.node_idx == node_idx && tree == other.tree;
    }
  };
  iterator begin(void) const { return iterator(this, 0); }
  iterator end(void) const { return iterator(this, -1); }
};

int main(int argc, char *argv[])
{
  int n, m, k;
  while (cin >> n >> m >> k) {
    str t;
    vec<str> v(n);
    cin >> t >> v;

    PrefixTree tree;
    for (int i = 0; i < v.size(); ++i) {
      tree.insert(v[i]);
    }

    int q;
    cin >> q;
    while (q--) {
      int i, prob;
      cin >> i >> prob;
      --i;
      --prob;
      tree.erase(v[i]);
      if (v[i][prob] == 'x') v[i][prob] = 'o';
      else v[i][prob] = 'x';
      tree.insert(v[i]);
      {
        int match = 0;
        str s;
        bool f = false;
        PrefixTree::iterator itr = tree.begin();
        int idx = 0;
        for (int j = 0; j < t.size(); ++j) {
          s += t[j];
          auto itr2 = itr;
          itr2.next(s.back());
          unless (itr2 == tree.end() || match + itr2.children() <= m) {
            itr = itr2;
          } else {
            while (idx < s.size()) {
              if (v[i][idx] == s[idx]) ++idx;
              else break;
            }
            if (idx == s.size()) {
              f = true;
              break;
            } else {
              idx = max(0, idx - 1);
            }
            if (s.back() == 'o') s.back() = 'x';
            else s.back() = 'o';
            itr.next(s.back());
            if (itr == tree.end()) break;
            if (!(itr2 == tree.end())) match += itr2.children();
          }
        }
        cout << (f ? "Yes" : "No") << '\n';
      }
    }
  }
  return 0;
}
