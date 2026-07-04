// github.com/Johniel/contests
// atcoder/abc465/E/main.cpp

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
  str s;
  while (cin >> s) {
    const int N = 500 + 10;
    // 10^6 < log10(2^10 * 500 * 2)
    const int D = (1 << 11);
    static lli dp[N][3][D][2][2];
    // dp[何桁目][３で割ったあまり][どの数字を使った][3を使ったかどうか][Nより小さいかどうか]
    fill(&dp[0][0][0][0][0], &dp[N - 1][3 - 1][D - 1][2 - 1][2 - 1] + 1, 0);
    dp[0][0][0][false][false] = 1;
    for (int nth = 0; nth < s.size(); ++nth) {
      for (int mod3 = 0; mod3 < 3; ++mod3) {
        for (int bit = 0; bit < D; ++bit) {
          for (int use3 = 0; use3 < 2; ++use3) {
            for (int lower = 0; lower < 2; ++lower) {
              const int d = s[nth] - '0';
              for (int x = 0; x <= (lower ? 9 : d); ++x) {
                // if ((bit & (1 << nth)) == 0 && x == 0) continue;
                if (bit == 0 && x == 0) {
                  (dp[nth + 1][mod3][bit][use3][true] += dp[nth][mod3][bit][use3][lower]) %= mod;
                } else {
                  (dp[nth + 1][(mod3 * 10 + x) % 3][bit | (1 << x)][use3 || (x == 3)][lower || (x < d)] +=
                   dp[nth][mod3][bit][use3][lower]) %= mod;
                }
              }
            }
          }
        }
      }
    }
    lli z = 0;
    for (int bit = 1; bit < D; ++bit) {
      if (__builtin_popcountll(bit) != 3) {
        (z += dp[s.size()][0][bit][false][false]) %= mod;
        (z += dp[s.size()][0][bit][false][true]) %= mod;
      }
    }
    for (int bit = 1; bit < D; ++bit) {
      if (__builtin_popcountll(bit) != 3) {
        (z += dp[s.size()][1][bit][true][false]) %= mod;
        (z += dp[s.size()][1][bit][true][true]) %= mod;
        (z += dp[s.size()][2][bit][true][false]) %= mod;
        (z += dp[s.size()][2][bit][true][true]) %= mod;
      }
    }
    for (int bit = 1; bit < D; ++bit) {
      if (__builtin_popcountll(bit) == 3) {
        (z += dp[s.size()][1][bit][false][false]) %= mod;
        (z += dp[s.size()][1][bit][false][true]) %= mod;
        (z += dp[s.size()][2][bit][false][false]) %= mod;
        (z += dp[s.size()][2][bit][false][true]) %= mod;
      }
    }
    cout << z << endl;
  }
  return 0;
}
