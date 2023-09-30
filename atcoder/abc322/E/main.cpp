// github.com/Johniel/contests
// atcoder/abc322/E/main.cpp

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
  const int N = 100 + 3;
  const int K = 5 + 2;
  const int P = 5 + 2;
  int n, k, p;
  while (cin >> n >> k >> p) {

    lli c[N];
    vec<lli> a[N];
    fill(a, a + n, vec<lli>(k));
    for (int i = 0; i < n; ++i) {
      cin >> c[i] >> a[i];
      while (a[i].size() < 5) a[i].push_back(0);
    }

    static lli dp[N][P][P][P][P][P];
    const lli inf = 1LL << 61;
    fill(&dp[0][0][0][0][0][0], &dp[N - 1][P - 1][P - 1][P - 1][P - 1][P - 1] + 1, inf);
    dp[0][0][0][0][0][0] = 0;

    for (int plan = 0; plan < n; ++plan) {
      for (int x = 0; x <= p; ++x) {
        for (int y = 0; y <= p; ++y) {
          for (int z = 0; z <= p; ++z) {
            for (int v = 0; v <= p; ++v) {
              for (int w = 0; w <= p; ++w) {
                setmin(dp[plan + 1][x][y][z][v][w], dp[plan][x][y][z][v][w]);

                int _x = x + a[plan][0]; setmin(_x, p);
                int _y = y + a[plan][1]; setmin(_y, p);
                int _z = z + a[plan][2]; setmin(_z, p);
                int _v = v + a[plan][3]; setmin(_v, p);
                int _w = w + a[plan][4]; setmin(_w, p);
                setmin(dp[plan + 1][_x][_y][_z][_v][_w], dp[plan][x][y][z][v][w] + c[plan]);
                // setmin(dp[plan + 1]
                //        [min(P - 1, x + a[plan][0])]
                //        [min(P - 1, y + a[plan][1])]
                //        [min(P - 1, z + a[plan][2])]
                //        [min(P - 1, v + a[plan][3])]
                //        [min(P - 1, w + a[plan][4])],
                //        dp[plan][x][y][z][v][w] + c[plan]);
              }
            }
          }
        }
      }
    }
    vec<int> b(k, p);
    while (b.size() < 5) b.push_back(0);
    lli z = dp[n][b[0]][b[1]][b[2]][b[3]][b[4]];
    if (z == inf) cout << -1 << endl;
    else cout << z << endl;
  }
  return 0;
}
