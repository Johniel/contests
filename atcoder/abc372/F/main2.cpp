// github.com/Johniel/contests
// atcoder/abc372/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

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

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int n, m, k;
  while (cin >> n >> m >> k) {
    vec<pair<int, int>> v(m);
    cin >> v;
    each (i, v) --i.first, --i.second;
    sort(v.begin(), v.end());
    vec<int> u;
    u.push_back(0);
    each (i, v) u.push_back(i.first), u.push_back(i.second);
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());

    map<int, vec<int>> es;
    const int M = 50 + 2;
    const int A = 2 * M;
    static bool vis[A][A];
    for (int i = 0; i < u.size(); ++i) {
      for (int j = 0; j < u.size(); ++j) {
        int x = u[i];
        int y = u[j];
        if (binary_search(v.begin(), v.end(), make_pair(x, y))) es[i].push_back(j);
      }
    }

    const int K = 2 * 1e5 + 3;
    static lli dp[K][A][2]; // [移動回数][今どこ][最後に追加の辺を使った]:=パターン数
    fill(&dp[0][0][0], &dp[K - 1][A - 1][2 - 1] + 1, 0);
    dp[0][0][1] = 1;
    for (int i = 0; i < k; ++i) {
      for (int src = 0; src < u.size(); ++src) {
        each (dst, es[src]) {
          (dp[i + 1][dst][1] += dp[i][src][0]) %= mod;
          (dp[i + 1][dst][1] += dp[i][src][1]) %= mod;
        }
        if (const int dst = (src + 1) % u.size(); true) {
          int x = u[src];
          int y = u[dst];
          int j;
          if (x == y) j = n;
          else if (x < y) j = y - x;
          else j = (n - x) + y;
          if (i + j <= k) {
            (dp[i + j][dst][0] += dp[i][src][1]) %= mod;
            (dp[i + j][dst][0] += dp[i][src][0]) %= mod;
          }
        }
      }
    }

    lli z = 0;
    for (int len = 0; len <= k; ++len) {
      for (int i = 0; i < u.size(); ++i) {
        (z += dp[len][i][1]) %= mod;
      }
    }
    cout << z << endl;
  }
  return 0;
}
