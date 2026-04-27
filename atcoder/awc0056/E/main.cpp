// github.com/Johniel/contests
// atcoder/awc0056/E/main.cpp

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
  int n, m;
  while (cin >> n >> m) {
    vec<pair<int, lli>> g[n];
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back(make_pair(b, c));
      g[b].push_back(make_pair(a, c));
    }
    const int K = 15 + 2;
    int s, k;
    cin >> s >> k;
    --s;
    vec<int> d(k);
    cin >> d;
    each (i, d) --i;
    d.insert(d.begin(), s);
    lli h[K][K];
    for (int i = 0; i < d.size(); ++i) {
      priority_queue<pair<lli, int>> q;
      q.push(make_pair(0, d[i]));
      vec<lli> w(n, (1LL << 60));
      w[d[i]] = 0;
      while (q.size()) {
        auto [cost, curr] = q.top();
        q.pop();
        cost = abs(cost);
        if (w[curr] != cost) continue;
        each (e, g[curr]) {
          auto [next, c] = e;
          if (w[next] > w[curr] + c) {
            w[next] = w[curr] + c;
            q.push(make_pair(-w[next], next));
          }
        }
      }
      for (int j = 0; j < d.size(); ++j) {
        h[i][j] = w[d[j]];
      }
    }
    const int B = (1 << K) + 1;
    static lli dp[B][K];
    const lli inf = (1LL << 58);
    fill(&dp[0][0], &dp[B - 1][K - 1] + 1, inf);
    dp[(1 << 0)][0] = 0;
    for (int bit = 0; bit < (1 << d.size()); ++bit) {
      for (int i = 0; i < d.size(); ++i) {
        if (inf <= dp[bit][i]) continue;
        for (int j = 0; j < d.size(); ++j) {
          setmin(dp[bit | (1 << j)][j], dp[bit][i] + h[i][j]);
        }
      }
    }
    lli z = inf;
    for (int i = 0; i < d.size(); ++i) {
      setmin(z, dp[(1 << d.size()) - 1][i] + h[i][0]);
    }
    cout << z << endl;
  }
  return 0;
}
