// github.com/Johniel/contests
// atcoder/arc058/E/main.cpp

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
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
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
constexpr lli mod = 1e9 + 7;

template<int B>
struct ARC058ECoding {
  bool contains(const lli b, int x, int y, int z) {
    assert(0 < x);
    assert(0 < y);
    assert(0 < z);
    unless (b & (1LL << (z - 1))) return false;
    unless (b & (1LL << (y + z - 1))) return false;
    unless (b & (1LL << (z + y + x - 1))) return false;
    return true;
  }

  lli add(const lli b, const int x) {
    assert(0 < x);
    return ((b * 2 + 1) << (x - 1));
  }

  lli remove(lli b) {
    assert(b);
    unless ((1LL << B) <= b) return b;
    for (int i = 60; 0 <= i; --i) {
      if (b & (1LL << i)) b -= (1LL << i);
      unless ((1LL << B) <= b) return b;
    }
    return -1;
  }
};

int main(int argc, char *argv[])
{
  int n, x, y, z;
  while (cin >> n >> x >> y >> z) {
    const int N = 40 + 2;
    const int M = (1 << (5 + 7 + 5)) + 2;
    static lli dp[N][M];
    fill(&dp[0][0], &dp[N - 1][M - 1] + 1, 0);
    dp[0][0] = 1;

    ARC058ECoding<5+7+5> coding;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < M; ++j) {
        unless (dp[i][j]) continue;
        for (int k = 1; k <= 10; ++k) {
          lli b = coding.add(j, k);
          unless (coding.contains(b, x, y, z)) {
            b = coding.remove(b);
            (dp[i + 1][b] += dp[i][j]) %= mod;
          }
        }
      }
    }
    lli z = 1;
    for (int i = 0; i < n; ++i) {
      (z *= 10) %= mod;
    }
    for (int j = 0; j < M; ++j) {
      (z = z - dp[n][j] + mod) %= mod;
    }
    cout << z << endl;
  }
  return 0;
}
