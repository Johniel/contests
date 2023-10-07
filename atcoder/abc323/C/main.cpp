// github.com/Johniel/contests
// atcoder/abc323/C/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vec<int> a(m);
    cin >> a;
    vec<str> g(n);
    cin >> g;

    each (i, a) i /= 100;

    int z = -1;
    pair<int, int> mx = make_pair(0, 0);
    for (int i = 0; i < n; ++i) {
      int s = 0;
      for (int j = 0; j < m; ++j) {
        if (g[i][j] == 'o') {
          s += a[j];
        }
      }
      pair<int, int> p = make_pair(s, i);
      if (mx < p) {
        mx = p;
        z = i;
      }
    }

    const int M = 100 + 3;
    const int A = 25 * M;
    static int dp[M][A];
    const int inf = 1 << 29;
    // cout << mx << endl;
    for (int i = 0; i < n; ++i) {
      fill(&dp[0][0], &dp[M - 1][A - 1] + 1, inf);
      dp[0][0] = 0;
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < A; ++k) {
          if (dp[j][k] == inf) continue;
          if (g[i][j] == 'o') {
            setmin(dp[j + 1][k + a[j]], dp[j][k] + 1);
          } else {
            setmin(dp[j + 1][k + a[j]], dp[j][k] + 1);
            setmin(dp[j + 1][k], dp[j][k]);
          }
        }
      }

      int mn = inf;
      for (int k = 0; k < A; ++k) {
        if (mx.first == k && mx.second < i) {
          setmin(mn, dp[m][k]);
        }
        if (mx.first < k) {
          setmin(mn, dp[m][k]);
        }
      }
      if (z == i) cout << 0 << endl;
      else cout << mn  - count(g[i].begin(), g[i].end(), 'o') << endl;
    }
  }
  return 0;
}
