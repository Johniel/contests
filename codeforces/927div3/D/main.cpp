// github.com/Johniel/contests
// codeforces/927div3/D/main.cpp

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  { int _; cin >> _;}
  int n;
  char suit;
  while (cin >> n >> suit) {
    vec<str> v(2 * n);
    cin >> v;
    map<char, vec<char>> m;
    each (i, v) {
      m[i[1]].push_back(i[0]);
    }
    each (i, m) {
      sort(i.second.rbegin(), i.second.rend());
    }
    vec<str> u;
    str s = "CDHS";
    each (c, s) {
      if (c == suit) continue;
      while (2 <= m[c].size()) {
        str t;
        t += m[c].back();
        t += c;
        t += ' ';
        m[c].pop_back();
        t += m[c].back();
        t += c;
        t += ' ';
        m[c].pop_back();
        u.push_back(t);
      }
    }
    each (c, s) {
      if (c == suit) continue;
      while (m[c].size() && m[suit].size()) {
        str t;
        t += m[c].back();
        t += c;
        t += ' ';
        m[c].pop_back();
        t += m[suit].back();
        t += suit;
        t += ' ';
        m[suit].pop_back();
        u.push_back(t);
      }
    }
    each (c, s) {
      while (2 <= m[c].size()) {
        str t;
        t += m[c].back();
        t += c;
        t += ' ';
        m[c].pop_back();
        t += m[c].back();
        t += c;
        t += ' ';
        m[c].pop_back();
        u.push_back(t);
      }
    }
    if (u.size() == n) each (i, u) cout << i << "\n";
    else cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
