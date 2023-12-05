// github.com/Johniel/contests
// codeforces/913div3/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }

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
  { int _; cin >> _; }

  map<str, lli> memo;
  str s;
  while (cin >> s) {
    sort(s.begin(), s.end());
    if (memo.count(s)) {
      cout << memo[s] << endl;
      continue;
    }
    const int M = 1;
    const int S = 7 * 9 + 2;
    static lli dp[2][M][S][S][S];
    const int w = accumulate(s.begin(), s.end(), 0) - s.size() * '0';
    for (int carry = 0; carry < M; ++carry) {
      for (int a = 0; a <= w; ++a) {
        for (int b = 0; a + b <= w; ++b) {
          for (int c = 0; a + b + c <= w; ++c) {
            dp[0][carry][a][b][c] = 0;
            // dp[1][carry][a][b][c] = 0;
          }
        }
      }
    }
    dp[0][0][0][0][0] = 1;
    each_with_index (idx, c, s) {
      const int curr = idx % 2;
      const int next = (curr + 1) % 2;

      const int P = min(idx * 9, w);
      const int Q = min((idx + 1) * 9 + 1, w);

      for (int carry = 0; carry < M; ++carry) {
        for (int a = 0; (a <= Q); ++a) {
          for (int b = 0; (a + b <= Q); ++b) {
            for (int c = 0; (a + b + c <= Q); ++c) {
              dp[next][carry][a][b][c] = 0;
            }
          }
        }
      }

      for (int carry = 0; carry < M; ++carry) {
        const int x = (c - '0') + (carry * 10);
        for (int a = 0; a <= P; ++a) {
          for (int b = 0; a + b <= P; ++b) {
            for (int c = 0; a + b + c <= P; ++c) {
              unless (dp[curr][carry][a][b][c]) continue;
              for (int i = 0; i <= 9 && (a + i) <= Q; ++i) {
                for (int j = 0; j <= 9 && (b + j) <= Q && (i + j <= x); ++j) {
                  for (int k = 0; k <= 9 && (c + k) <= Q && (i + j + k <= x); ++k) {
                    const int y = x - (i + j + k);
                    if (0 <= y && y < M) {
                      dp[next][y][a + i][b + j][c + k] += dp[curr][carry][a][b][c];
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    lli z = 0;
    for (int a = 0; a <= w; ++a) {
      for (int b = 0; a + b <= w; ++b) {
        for (int c = 0; a + b + c <= w; ++c) {
          if (a + b + c == w) {
            z += dp[s.size() % 2][0][a][b][c];
          }
        }
      }
    }
    cout << (memo[s] = z) << endl;
  }

  return 0;
}
