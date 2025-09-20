// github.com/Johniel/contests
// atcoder/abc424/D/main.cpp

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

constexpr lli mod = 998244353; // 1e9 + 7;

const int H = 7 + 1;
const int W = 7 + 1;
const int M = (1 << W);
int dp[H][M];
char g[H][W];

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int h, w;
  while (cin >> h >> w) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    const int inf = (1 << 29);
    for (int i = 0; i <= h; ++i) {
      for (int j = 0; j < (1 << w); ++j) {
        dp[i][j] = inf;
      }
    }
    // dp[0][(1 << w) - 1] = 0;
    dp[0][0] = 0;
    for (int i = 0; i < h; ++i) {
      int curr = 0;
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '#') curr += (1 << j);
      }
      for (int prev = 0; prev < (1 << w); ++prev) {
        if (dp[i][prev] == inf) continue;
        for (int repaint = 0; repaint < (1 << w); ++repaint) {
          const int cost = __builtin_popcountll(repaint);
          int b = curr;
          for (int j = 0; j < w; ++j) {
            if ((repaint & (1 << j)) && (b & (1 << j))) b -= (1 << j);
          }
          bool valid = true;
          for (int j = 0; j + 1 < w; ++j) {
            int k = j + 1;
            unless ((prev & (1 << j)) && (prev & (1 << k))) continue;
            unless ((b    & (1 << j)) && (b    & (1 << k))) continue;
            valid = false;
          }
          if (valid) {
            setmin(dp[i + 1][b], dp[i][prev] + cost);
          }
        }
      }
    }
    int mn = inf;
    for (int j = 0; j < (1 << w); ++j) {
      setmin(mn, dp[h][j]);
    }
    cout << mn << endl;
  }
  return 0;
}
