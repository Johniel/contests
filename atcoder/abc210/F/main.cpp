// github.com/Johniel/contests
// atcoder/abc210/F/main.cpp

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

#include "atcoder/twosat"
using namespace atcoder;

int main(int argc, char *argv[])
{
  const int M = 2 * 1e6 + 3;
  static bool prime[M];
  fill(prime, prime + M, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < M; ++i) {
    for (int j = 2; i * j < M; ++j) {
      prime[i * j] = false;
    }
  }
  vector<int> p;
  for (int i = 0; i < M; ++i) {
    if (prime[i]) p.push_back(i);
  }
  map<int, int> inv;
  for (int i = 0; i < p.size(); ++i) {
    inv[p[i]] = i;
  }

  int n;
  while (cin >> n) {
    vec<pair<int, int>> v(n);
    cin >> v;

    map<int, vec<pair<int, bool>>> m;
    for (int i = 0; i < v.size(); ++i) {
      auto fn = [&] (int x, bool flip) {
        for (lli j = 2; j * j <= x; ++j) {
          if (x % j == 0) {
            m[inv[j]].push_back(make_pair(i, flip));
            while (x % j == 0) x /= j;
          }
        }
        if (x != 1) m[inv[x]].push_back(make_pair(i, flip));
        return ;
      };
      fn(v[i].first, false);
      fn(v[i].second, true);
    }
    int base = 0;
    each (i, m) base += i.second.size();

    two_sat ts(base* 2);
    each (p, m) {
      auto [i, u] = p;
      for (int j = 0; j < u.size(); ++j) {
        // https://drken1215.hatenablog.com/entry/2023/08/06/235112
        // https://drken1215.hatenablog.com/entry/2023/08/04/021846
        auto [idx, flip] = u[j];
        {
          ts.add_clause(u[j].first, !flip, base + j, true);
        }
        if (j) {
          ts.add_clause(base + j - 1, false, u[j].first, !flip);
          ts.add_clause(base + j - 1, false, base + j, true);
        }
      }
      base += u.size();
    }
    cout << (ts.satisfiable() ? "Yes" : "No") << endl;
  }
  return 0;
}
