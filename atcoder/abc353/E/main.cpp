// github.com/Johniel/contests
// atcoder/abc353/E/main.cpp

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

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

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
  // O(|S|),w個insertする
  void insert(const string& s, const int m = 1) {
    assert(1 <= m);
    int curr = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      curr = nodes[curr].count(s[i]) ? nodes[curr][s[i]] : nodes[curr][s[i]] = make_node();
      children[curr] += m;
    }
    accept[curr] += m;
    return ;
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
};

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<str> v(n);
    cin >> v;
    lli z = 0;
    PrefixTree tree;
    each (s, v) {
      vec<int> u = tree.count(s);
      for (int i = 0; i < u.size(); ++i) {
        z += u[i];
      }
      tree.insert(s);
    }
    cout << z << endl;
  }
  return 0;
}
