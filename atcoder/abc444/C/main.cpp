// github.com/Johniel/contests
// atcoder/abc444/C/main.cpp

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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;
    sort(a.begin(), a.end());

    map<int, int> m;
    each (i, a) ++m[i];

    vec<int> b;

    if (m.size() == 1) b.push_back(a[0]);

    if (m.size() == 1 && m[a[0]] % 2 == 0) {
      b.push_back(a[0] + a[0]);
    }

    if (2 <= m.size()) {
      const int L = a.back();
      const map<int, int> _m = m;
      if (m.count(L)) m[L] = 0;
      bool f = true;
      each (i, a) {
        int j = L - i;
        if (m[i] && m.count(j)) {
          f = f && (m[i] == m[j]);
          int mn = min(m[i], m[j]);
          if (i == j) {
            f = f && (mn % 2 == 0);
            m[i] -= mn;
          } else {
            m[i] -= mn;
            m[j] -= mn;
          }
        }
      }
      each (i, m) f = f && (i.second == 0);
      if (f) b.push_back(L);
      m = _m;
    }

    if (2 <= m.size()) {
      const int L = a.back() + a.front();
      const map<int, int> _m = m;
      if (m.count(L)) m[L] = 0;
      bool f = true;
      each (i, a) {
        int j = L - i;
        if (m[i] && m.count(j)) {
          f = f && (m[i] == m[j]);
          int mn = min(m[i], m[j]);
          if (i == j) {
            f = f && (mn % 2 == 0);
            m[i] -= mn;
          } else {
            m[i] -= mn;
            m[j] -= mn;
          }
        }
      }
      each (i, m) f = f && (i.second == 0);
      if (f) b.push_back(L);
      m = _m;
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    each (i, b) cout << i << ' '; cout << endl;
  }
  return 0;
}
