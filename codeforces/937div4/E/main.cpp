// github.com/Johniel/contests
// codeforces/937div4/E/main.cpp

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

int main(int argc, char *argv[])
{
  { int _; scanf("%d\n", &_); }
  int n;
  const int N = 2 * 1e5 + 3;
  static char s[N];
  while (scanf("%d\n%s\n", &n, s) == 2) {
    int mn = n;
    static map<char, int> m[N];
    for (int k = 1; k <= n; ++k) {
      if (n % k == 0) {
        for (int i = 0; i <= k; ++i) m[i].clear();
        const int x = n / k;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
          ++m[i % k][s[i]];
          setmax<int>(mx, m[i % k].size());
          if (2 < mx) break;
        }
        if (2 < mx) continue;
        static char t[N];
        int tsize = 0;
        for (int i = 0; i < k; ++i) {
          if (m[i].size() == 1) {
            t[tsize] = m[i].begin()->first;
          } else {
            if (m[i].begin()->second < m[i].rbegin()->second) {
              t[tsize] = m[i].rbegin()->first;
            } else {
              t[tsize] = m[i].begin()->first;
            }
          }
          ++tsize;
        }
        int diff = 0;
        for (int i = 0; i < n; ++i) {
          diff += (s[i] != t[i % tsize]);
          if (1 < diff) break;
        }
        if (diff <= 1) {
          setmin(mn, k);
          break;
        }
      }
    }
    printf("%d\n", mn);
  }
  return 0;
}
