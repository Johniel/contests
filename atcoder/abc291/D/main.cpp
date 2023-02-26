// github.com/Johniel/contests
// atcoder/abc291/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<pair<int, int>> v(n);
    cin >> v;

    const int FIRST = 0;
    const int SECOND = 1;
    const int N = 2 * 1e5 + 3;
    static lli dp[N][2];
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, 0);
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 0; i + 1 < v.size(); ++i) {
      int j = i + 1;
      if (v[j].first != v[i].first) {
        (dp[j][FIRST] += dp[i][FIRST]) %= mod;;
      }
      if (v[j].second != v[i].first) {
        (dp[j][SECOND] += dp[i][FIRST]) %= mod;;
      }
      if (v[j].first != v[i].second) {
        (dp[j][FIRST] += dp[i][SECOND]) %= mod;;
      }
      if (v[j].second != v[i].second) {
        (dp[j][SECOND] += dp[i][SECOND]) %= mod;;
      }
    }
    cout << (dp[n - 1][FIRST] + dp[n - 1][SECOND]) % mod << endl;
  }
  return 0;
}
