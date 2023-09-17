// github.com/Johniel/contests
// atcoder/abc320/F/main.cpp

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
  int n, h;
  while (cin >> n >> h) {
    vec<int> x(n);
    cin >> x;
    vec<pair<int, int>> v(n - 1);
    cin >> v;

    if (n == 1) {
      if (x[0] * 2 <= h) cout << 0 << endl;
      else cout << -1 << endl;
      continue;
    }
    x.insert(x.begin(), 0);
    v.insert(v.begin(), make_pair(0, 0));

    const int N = 300 + 3;
    const int H = 300 + 3;
    static lli dp[N][H][H]; // dp[どこ][往路の燃料][復路の燃料]:=費用
    const lli inf = 1LL << 62;
    fill(&dp[0][0][0], &dp[N - 1][H - 1][H - 1] + 1, inf);
    for (int i = 0; i <= h; ++i) {
      dp[0][h][i] = 0;
      // dp[0][20][14] = 0;
    }
    for (int i = 0; i + 2 < x.size(); ++i) {
      for (int a = 0; a <= h; ++a) {
        for (int b = 0; b <= h; ++b) {
          // if (dp[i][a][b] == inf) continue;
          auto [cost, fuel] = v.at(i);
          const int dist = x[i + 1] - x[i];
          {
            // 利用しない
            const int na = a - dist;
            const int nb = b + dist;
            if (0 <= na && 0 <= nb && nb <= h) {
              setmin(dp[i + 1][na][nb], dp[i][a][b]);
            }
          }
          {
            // 往路で利用
            const int na = min(a + fuel, h) - dist;
            const int nb = b + dist;
            if (0 <= na && 0 <= nb && nb <= h) {
              setmin(dp[i + 1][na][nb], dp[i][a][b] + cost);
            }
          }
          {
            // 復路で利用
            const int na = a - dist;
            const int pb = min(b - dist + fuel, h);
            if (0 <= na && 0 <= b - dist) {
              setmin(dp[i + 1][na][b], dp[i][a][pb] + cost);
            }
          }
        }
      }
    }

    // for (int i = 0; i <= x.size(); ++i) {
    //   cout << i << ":";
    //   for (int a = 0; a <= h; ++a) {
    //     for (int b = 0; b <= h; ++b) {
    //       if (dp[i][a][b] < inf) {
    //         cout << make_pair(make_pair(a, b), dp[i][a][b]);
    //       }
    //     }
    //   }
    //   cout << endl;
    // }

    lli mn = inf;
    for (int a = 0; a <= h; ++a) {
      const int i = x.size() - 2;
      auto [cost, fuel] = v.at(i);
      const int dist = x[i + 1] - x[i];
      // 利用しない
      {
        int b = a - dist - dist;
        if (dist + dist <= a && 0 <= b) setmin(mn, dp[n - 1][a][b]);
      }
      // 往路で利用
      {
        int b = min(a + fuel, h) - dist - dist;
        if (dist + dist <= min(a + fuel, h) && 0 <= b) setmin(mn, dp[n - 1][a][b] + cost);
      }
      // 復路で利用
      {
        int b = min(a - dist - dist + fuel, h);
        if (dist + dist <= a && 0 <= a - dist - dist) setmin(mn, dp[n - 1][a][b] + cost);
      }
    }
    if (mn != inf) cout << mn << endl;
    else cout << -1 << endl;

    // break;
  }
  return 0;
}
