// github.com/Johniel/contests
// atcoder/abc410/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

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

constexpr lli mod = 998244353; // 1e9 + 7;

int main(int argc, char *argv[])
{
  { int _; scanf("%d", &_); }
  int h, w;
  while (scanf("%d %d\n", &h, &w) == 2) {
    vec<vec<int>> a(min(h, w), vec<int>(max(h, w)));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        char c;
        scanf("%c", &c);
        const bool r = (h > w);
        if (r) a[j][i] = (c == '#' ? +1 : -1);
        else a[i][j] = (c == '#' ? +1 : -1);
      }
      scanf("\n");
    }

    lli z = 0;
    // vec<int> v(a[0].size(), 0);
    const int M = 3 * 1e5 + 3;
    static lli v[M];
    // fill(v, v + M, 0);
    for (int x = 0; x < a.size(); ++x) {
      // fill(v.begin(), v.end(), 0);
      const int s = a[0].size();
      fill(v, v + s, 0);
      vec<int> u;
      for (int y = x; y < a.size(); ++y) {
        for (int k = 0; k < s; ++k) v[k] += a[y][k];
        // unordered_map<int, int> m;
        static int m[M * 2] = {0, };
        m[0 + M] = 1;
        int p = 0;
        vec<int> u;
        for (int k = 0; k < s; ++k) {
          p += v[k];
          z += m[p + M];
          ++m[p + M];
          u.push_back(p + M);
        }
        each (i, u) m[i] = 0;
      }
    }
    printf("%lld\n", z);
  }
  return 0;
}
