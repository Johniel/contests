// github.com/Johniel/contests
// atcoder/abc336/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  str s;
  while (cin >> s) {
    const int L = 20;
    const int M = 9;
    const int A = L * M;
    static lli dp[L][A][2];
    fill(&dp[0][0][0], &dp[L - 1][A - 1][2 - 1] + 1, 0);
    dp[0][0][false] = 1;
    for (int i = 0; i < s.size(); ++i) {
      const int x = s[i] - '0';
      for (int j = 0; j < A; ++j) {
        for (int small = 0; small < 2; ++small) {
          unless (dp[i][j][small]) continue;
          for (int k = 0; k <= (small ? 9 : x); ++k) {
            dp[i + 1][j + k][small || (k < x)] += dp[i][j][small];
          }
        }
      }
    }

    // for (int i = 0; i <= 2; ++i) {
    //   for (int j = 0; j < 20; ++j) {
    //     if (dp[i][j][false] || dp[i][j][true]) cout << make_pair(i, j) << ' ' << dp[i][j][false] << ' ' << dp[i][j][true] << endl;
    //   }
    // }

    lli z = 0;
    static lli dp2[L][A][A][2]; // [今何桁目][桁和][あまり][samll or large]
    for (int sum = 1; sum < A; ++sum) {
      const lli y = dp[s.size()][sum][false] + dp[s.size()][sum][true];
      if (y == 0) continue;
      fill(&dp2[0][0][0][0], &dp2[L - 1][A - 1][A - 1][2 - 1] + 1, 0);
      dp2[0][0][0][false] = 1;
      for (int i = 0; i < s.size(); ++i) {
        const int x = s[i] - '0';
        for (int j = 0; j < A; ++j) {
          for (int k = 0; k < A; ++k) {
            for (int small = 0; small < 2; ++small) {
              unless (dp2[i][j][k][small]) continue;
              for (int append = 0; append <= (small ? 9 : x); ++append) {
                dp2[i + 1][j + append][(k * 10 + append) % sum][small || (append < x)] += dp2[i][j][k][small];
              }
            }
          }
        }
      }
      z += dp2[s.size()][sum][0][false];
      z += dp2[s.size()][sum][0][true];
      // z += dp2[s.size()][sum][0][false] * y;
      // z += dp2[s.size()][sum][0][true] * y;
    }
    cout << z << endl;
    // break;
  }
  return 0;
}
