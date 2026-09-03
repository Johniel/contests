// github.com/Johniel/contests
// atcoder/awc0149/E/main.cpp

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
    vec<pair<int, lli>> g[n];
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back(make_pair(b, c));
      g[b].push_back(make_pair(a, c));
    }
    vec<int> c(k);
    cin >> c;
    each (i, c) --i;

    const lli inf = (1LL << 60);
    vec<lli> cost[20];

    c.push_back(n - 1);
    c.push_back(0);
    for (int i = 0; i < c.size(); ++i) {
      auto sssp = [&] () {
        const int src = c[i];
        cost[i].resize(n, inf);
        cost[i][src] = 0;
        priority_queue<pair<lli, int>> q;
        q.push(make_pair(0, src));
        while (q.size()) {
          auto [c, curr] = q.top();
          q.pop();
          c = abs(c);
          if (cost[i][curr] != c) continue;
          each (e, g[curr]) {
            auto [next, w] = e;
            if (cost[i][next] > cost[i][curr] + w) {
              cost[i][next] = cost[i][curr] + w;
              q.push(make_pair(-cost[i][next], next));
            }
          }
        }
        return ;
      };
      sssp();
    }

    const int N = 17;
    const int B = (1 << N);
    static lli dp[B][N];
    fill(&dp[0][0], &dp[B - 1][N - 1] + 1, inf);
    dp[1 << (c.size() - 1)][c.size() - 1] = 0;
    for (int bit = 0; bit < (1 << c.size()); ++bit) {
      for (int i = 0; i < c.size(); ++i) {
        unless (bit & (1 << i)) continue;
        for (int j = 0; j < c.size(); ++j) {
          setmin(dp[bit | (1 << j)][j], dp[bit][i] + cost[i][c[j]]);
        }
      }
    }
    cout << dp[(1 << c.size()) - 1][c.size() - 2] << endl;
  }
  return 0;
}
