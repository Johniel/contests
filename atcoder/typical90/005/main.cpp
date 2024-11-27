// github.com/Johniel/contests
// atcoder/typical90/005/main.cpp

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

lli mod_pow(lli n, lli p, lli M)
{
  if (p == 0) return 1;
  if (p == 1) return n % M;
  lli m = mod_pow(n, p / 2, M);
  m *= m;
  m %= M;
  if (p % 2) m = (m * n) % M;
  return m;
}

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  lli n;
  lli b;
  int k;
  while (cin >> n >> b >> k) {
    vec<int> v(k);
    cin >> v;
    const int D = 63;
    const int B = 1000 + 3;
    vec<lli> p10;
    for (int i = 0; i <= D; ++i) {
      p10.push_back(mod_pow(10, 1LL << i, b));
    }
    static lli dp[D][B];
    fill(&dp[0][0], &dp[D - 1][B - 1] + 1, 0);
    each (i, v) ++dp[0][i % b];
    for (int i = 0; i + 1 < D; ++i) {
      for (int x = 0; x < b; ++x) {
        for (int y = 0; y < b; ++y) {
          (dp[i + 1][(x * p10[i] + y) % b] += dp[i][x] * dp[i][y]) %= mod;
        }
      }
    }
    static lli dp2[D][B];
    fill(&dp2[0][0], &dp2[D - 1][B - 1] + 1, 0);
    dp2[0][0] = 1;
    for (int i = 0; i + 1 < D; ++i) {
      if (n & (1LL << i)) {
        for (int x = 0; x < b; ++x) {
          for (int y = 0; y < b; ++y) {
            (dp2[i + 1][(x * p10[i] + y) % b] += dp2[i][x] * dp[i][y]) %= mod;
          }
        }
      } else {
        for (int x = 0; x < b; ++x) {
          dp2[i + 1][x] = dp2[i][x];
        }
      }
    }
    cout << dp2[62][0] << endl;
  }
  return 0;
}
