// github.com/Johniel/contests
// atcoder/awc0043/E/main.cpp

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

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  str s;
  while (cin >> s) {
    lli cnt[20][10][2][2][2];
    fill(&cnt[0][0][0][0][0], &cnt[20 - 1][10 - 1][2 - 1][2 - 1][2 - 1] + 1, 0);
    lli dp[20][10][2][2][2]; // [何桁][直近][これまでsに等しいか][休憩][leading 0]
    fill(&dp[0][0][0][0][0], &dp[20 - 1][10 - 1][2 - 1][2 - 1][2 - 1] + 1, 0);
    cnt[0][0][true][false][true] = 1;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j <= 9; ++j) {
        for (int k = 0; k < 2; ++k) {
          for (int r = 0; r < 2; ++r) {
            for (int z = 0; z < 2; ++z) {
              if (cnt[i][j][k][r][z] == 0) continue;
              for (int y = 0; y <= (k ? (s[i] - '0') : 9); ++y) {
                lli& x = dp[i + 1][y][k && (s[i] - '0' == y)][r || (!z && y == 0)][z && (y == 0)];
                cnt[i + 1][y][k && (s[i] - '0' == y)][r || (!z && y == 0)][z && (y == 0)] += cnt[i][j][k][r][z];
                (x += dp[i][j][k][r][z] + cnt[i][j][k][r][z] * (z ? 0 : abs(j - y))) %= mod;
              }
            }
          }
        }
      }
    }
    lli z = 0;
    for (int i = 0; i < 10; ++i) {
      z += max(dp[s.size()][i][0][0][0], 0LL);
      z %= mod;
      z += max(dp[s.size()][i][0][1][0], 0LL) * 2;
      z %= mod;
      z += max(dp[s.size()][i][1][0][0], 0LL);
      z %= mod;
      z += max(dp[s.size()][i][1][1][0], 0LL) * 2;
      z %= mod;
    }
    cout << z << endl;
  }

  return 0;
}
