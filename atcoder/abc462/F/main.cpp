// github.com/Johniel/contests
// atcoder/abc462/F/main.cpp

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
  { int _; cin >> _; }
  str s;
  int k;
  while (cin >> s >> k) {
    const int N = 3 * 1e5 + 3;
    const int K = 30 + 2;
    static int dp[N][K];
    const int inf = (1 << 28);
    for (int i = 0; i <= s.size(); ++i) {
      for (int j = 0; j < K; ++j) {
        dp[i][j] = inf;
      }
    }
    static bool existing[N];
    fill(existing, existing + s.size() + 1, false);
    for (int i = 0; i + 2 < s.size(); ++i) {
      if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
        existing[i + 0] = true;
        // existing[i + 1] = true;
        // existing[i + 2] = true;
      }
    }
    // for (int i = 0; i < s.size(); ++i) cout << existing[i] << ' '; cout << endl;

    // XABCABCX
    // 1
    // XXABCX
    // 1

    dp[0][K / 2] = 0;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < K; ++j) {
        if (dp[i][j] == inf) continue;
        if (existing[i] && s[i] == 'A') {
          setmin(dp[i + 3][j], dp[i][j]);
          if (j) setmin(dp[i + 1][j - 1], dp[i][j]);
        } else {
          setmin(dp[i + 1][j], dp[i][j]);
          if (i + 2 < s.size()) {
            const int nj = j + 1 - (existing[i + 1] || existing[i + 2]);
            const int cost = (s[i] != 'A') + (s[i + 1] != 'B') + (s[i + 2] != 'C');
            setmin(dp[i + 3][nj], dp[i][j] + cost);
            // cout << make_pair(i, j-K/2) << ' ' << make_pair(i + 3, nj - K/2)  << " +" << cost << ' ' << s[i] << s[i + 1] << s[i + 2] << endl;
          }
        }
      }
    }
    // cout << (K / 2) + k << endl;
    int z = dp[s.size()][K / 2 + k];
    if (z == inf) cout << -1 << endl;
    else cout << z << endl;
  }
  return 0;
}
