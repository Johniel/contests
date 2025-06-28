// github.com/Johniel/contests
// atcoder/abc412/D/main.cpp

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

struct UnionFind {
  vector<int> r, p;
  UnionFind(int n): r(n, 0), p(n, -1) {}
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (r[a] > r[b]) swap(a, b);
    p[b] += p[a];
    p[a] = b;
    if (r[a] == r[b]) ++r[b];
    return true;
  }
  int find(int a) {
    return (p[a] < 0) ? a : p[a] = find(p[a]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  size_t size(int n) {
    return -p.at(find(n));
  }
};

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vec<pair<int, int>> es(m);
    cin >> es;
    each (e, es) --e.first, --e.second;
    int g[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        g[i][j] = 0;
      }
    }
    each (e, es) {
      ++g[e.first][e.second];
      ++g[e.second][e.first];
    }
    const lli inf = 1 << 28;
    lli cost[1 << n];
    fill(cost, cost + (1 << n), inf);
    for (int bit = 0; bit < (1 << n); ++bit) {
      vec<int> v;
      for (int i = 0; i < n; ++i) {
        if (bit & (1 << i)) v.push_back(i);
      }
      if (v.size() < 3) continue;
      int mn = inf;
      do {
        int x = 0;
        for (int i = 0; i < v.size(); ++i) {
          const int curr = v[i];
          const int next = v[(i + 1) % v.size()];
          const int prev = v[(i - 1 + (int)(v.size())) % v.size()];
          if (!g[curr][next]) ++x;
          if (!g[prev][curr]) ++x;
          for (int c = 0; c < n; ++c) {
            if (c != prev && c != next && g[curr][c]) ++x;
          }
        }
        setmin(mn, x);
      } while (next_permutation(v.begin(), v.end()));
      cost[bit] = mn;
    }

    int z = m + n;
    lli dp[(1 << n)];
    for (int i = 0; i < (1 << n); ++i) dp[i] = cost[i];
    dp[0] = 0;
    for (int i = 0; i < (1 << n); ++i) {
      for (int j = 1; j < (1 << n); ++j) {
        unless (i & j) {
          setmin(dp[i | j], dp[i] + cost[j]);
        }
      }
    }
    cout << dp[(1 << n) - 1] / 2 << endl;
    // break;
  }
  return 0;
}
