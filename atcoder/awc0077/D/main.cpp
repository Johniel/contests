// github.com/Johniel/contests
// atcoder/awc0077/D/main.cpp

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

int main(int argc, char *argv[])
{
  int n, m, k;
  while (cin >> n >> m >> k) {
    vec<lli> f(n);
    cin >> f;
    vec<pair<int, lli>> g[n];
    for (int i = 0; i < m; ++i) {
      int u, v, t;
      cin >> u >> v >> t;
      --u;
      --v;
      g[u].push_back(make_pair(v, t));
      g[v].push_back(make_pair(u, t));
    }
    const int N = 100000 + 3;
    const int K = 5 + 3;
    static lli cost[N][K];
    const lli inf = (1LL << 60);
    fill(&cost[0][0], &cost[N - 1][K - 1] + 1, inf);
    priority_queue<tuple<lli, int, int>> q;
    q.push(make_tuple(0, 0, f[0]));
    cost[0][f[0]] = 0;
    while (q.size()) {
      auto [c, curr, ff] = q.top();
      q.pop();
      c = abs(c);
      if (cost[curr][ff] != c) continue;
      each (e, g[curr]) {
        auto [next, t] = e;
        if (cost[next][ff] > cost[curr][ff] + (ff * t)) {
          cost[next][ff] = cost[curr][ff] + (ff * t);
          q.push(make_tuple(-cost[next][ff], next, ff));
        }
        if (cost[next][f[curr]] > cost[curr][ff] + (f[curr] * t)) {
          cost[next][f[curr]] = cost[curr][ff] + (f[curr] * t);
          q.push(make_tuple(-cost[next][f[curr]], next, f[curr]));
        }
      }
    }
    lli z = inf;
    for (int j = 0; j <= k; ++j) {
      setmin(z, cost[n - 1][j]);
    }
    if (z == inf) cout << -1 << endl;
    else cout << z << endl;
  }
  return 0;
}
