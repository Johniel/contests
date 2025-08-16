// github.com/Johniel/contests
// atcoder/abc419/E/main.cpp

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

int main(int argc, char *argv[])
{
  int n, mod, l;
  while (cin >> n >> mod >> l) {
    vec<lli> a(n);
    cin >> a;

    vec<lli> sum;
    sum.push_back(0);
    for (int i = 0; i < a.size(); ++i) {
      sum.push_back((sum.back() + a[i]) % mod);
    }


    // cout << sum << endl;
    // for (int i = 0; i + l < sum.size(); ++i) cout << sum[i] << ' ' << sum[i + l] << endl;

    // mod<=500
    const int N = 500 + 3;
    const int M = 500 + 3;
    const int L = N;

    vec<vec<int>> v(l);
    for (int i = 0; i < a.size(); ++i) {
      v[i % l].push_back(a[i]);
    }
    lli cost[L][M];
    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < mod; ++j) {
        lli c = 0;
        each (k, v[i]) {
          if (j >= k) c += j - k;
          else c += (mod - k) + j;
        }
        // cout << make_pair(i, j) << v[i] << c << endl;
        cost[i][j] = c;
      }
    }
    // for (int i = 0; i < l; ++i) {
    //   for (int j = 0; j < mod; ++j) {
    //     cout << make_pair(i, j) << cost[i][j] << endl;
    //   }
    // }
    // cout << v << endl;

    static lli dp[N][M];
    const lli inf = 1LL << 60;
    fill(&dp[0][0], &dp[N - 1][M - 1]+ 1, inf);
    dp[0][0] = 0;
    for (int i = 0; i < l; ++i) {
      for (int x = 0; x < mod; ++x) {
        if (inf <= dp[i][x]) continue;
        for (int y = 0; y < mod; ++y) {
          setmin(dp[i + 1][(x + y) % mod], dp[i][x] + cost[i][y]);
        }
      }
    }
    cout << dp[l][0] << endl;
    // break;
  }
  return 0;
}
