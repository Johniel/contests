// github.com/Johniel/contests
// codeforces/e179/E/main.cpp

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

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n, q;
  str s;
  while (cin >> n >> q >> s) {
    map<pair<char, char>, set<int>> m;
    for (int i = 0; i < q; ++i) {
      char a, b;
      cin >> a >> b;
      m[make_pair(a, b)].insert(i);
    }
    each (c, s) {
      // b, a
      // b, c, a
      // c, a
      // c, b, a
      // c, b
      if (c == 'a') continue;
      pair<char, char> ba = make_pair('b', 'a');
      pair<char, char> bc = make_pair('b', 'c');
      pair<char, char> ca = make_pair('c', 'a');
      pair<char, char> cb = make_pair('c', 'b');
      if (c == 'b') {
        if (m[ba].size()) {
          m[ba].erase(m[ba].begin());
          c = 'a';
          continue;
        }
        if (m[bc].size()) {
          int x = *m[bc].begin();
          auto itr = m[ca].lower_bound(x);
          if (itr != m[ca].end()) {
            m[bc].erase(x);
            m[ca].erase(itr);
            c = 'a';
            continue;
          }
        }
      }
      if (c == 'c') {
        if (m[ca].size()) {
          m[ca].erase(m[ca].begin());
          c = 'a';
          continue;
        }
        if (m[cb].size()) {
          int x = *m[cb].begin();
          auto itr = m[ba].lower_bound(x);
          if (itr != m[ba].end()) {
            m[cb].erase(x);
            m[ba].erase(itr);
            c = 'a';
            continue;
          }
        }
        if (m[cb].size()) {
          m[cb].erase(m[cb].begin());
          c = 'b';
          continue;
        }
      }
    }
    cout << s << endl;
  }
  return 0;
}
