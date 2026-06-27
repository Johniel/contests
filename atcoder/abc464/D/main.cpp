// github.com/Johniel/contests
// atcoder/abc464/D/main.cpp

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
  int n;
  str s;
  while (cin >> n >> s) {
    vec<lli> x(n), y(n - 1);
    cin >> x >> y;

    const int N = 2 * 1e5 + 3;
    const lli inf = (1LL << 60);
    static lli dp[N][2];
    for (int i = 0; i < n; ++i) {
      dp[i][0] = dp[i][1] = -inf;
    }
    const int S = 0;
    const int R = 1;
    if (s[0] == 'S') {
      dp[0][S] = 0;
      dp[0][R] = -x[0];
    } else {
      dp[0][S] = -x[0];
      dp[0][R] = 0;
    }
    for (int i = 1; i < n; ++i) {
      if (s[i] == 'S') {
        setmax(dp[i][S], dp[i - 1][R] + y[i - 1]);
        setmax(dp[i][S], dp[i - 1][S]);
        setmax(dp[i][R], dp[i - 1][R] - x[i]);
        setmax(dp[i][R], dp[i - 1][S] - x[i]);
      } else {
        setmax(dp[i][S], dp[i - 1][R] + y[i - 1] - x[i]);
        setmax(dp[i][S], dp[i - 1][S] - x[i]);
        setmax(dp[i][R], dp[i - 1][R]);
        setmax(dp[i][R], dp[i - 1][S]);
      }
    }
    cout << max(dp[n - 1][S], dp[n - 1][R]) << endl;
  }
  return 0;
}
