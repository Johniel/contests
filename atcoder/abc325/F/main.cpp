// github.com/Johniel/contests
// atcoder/abc325/F/main.cpp

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
  int n;
  while (cin >> n) {
    vec<int> d(n);
    cin >> d;
    sort(d.begin(), d.end());
    lli len[2], cost[2], lim[2];
    for (int i = 0; i < 2; ++i) {
      cin >> len[i] >> cost[i] >> lim[i];
    }
    const lli inf = 1LL << 60;
    const int N = 100 + 3;
    const int K = 1000 + 3;
    // dp[k][j]:=type0のセンサーをk個使用して長さjの範囲をカバーするのに必要なセンサー1の個数
    // type0のセンサーの個数を決め打てばdpする必要無くない？
    // dp[i番目のまで見た][type0の個数]:=type1の個数
    static lli dp[N][K];
    fill(&dp[0][0], &dp[N - 1][K - 1] + 1, inf);
    dp[0][0] = 0;
    for (int i = 0; i < d.size(); ++i) {
      for (int j = 0; j <= lim[0]; ++j) {
        for (int x = 0; j + x <= lim[0]; ++x) {
          int y = (max(0LL, d[i] - (x * len[0])) + len[1] - 1) / len[1];
          setmin(dp[i + 1][j + x], dp[i][j] + y);
        }
      }
    }
    lli mn = inf;
    for (int x = 0; x <= lim[0]; ++x) {
      if (dp[n][x] <= lim[1]) {
        setmin(mn, dp[n][x] * cost[1] + x * cost[0]);
      }
    }
    cout << (mn == inf ? -1 : mn) << endl;
  }
  return 0;
}
