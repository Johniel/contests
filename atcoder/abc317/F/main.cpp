// github.com/Johniel/contests
// atcoder/abc317/F/main.cpp

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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  lli n;
  vec<lli> a(3);
  while (cin >> n >> a) {

    const int N = 70;
    const int M = 11;
    const int K = 2;
    const int L = 2;

    vec<int> b;
    for (int _ = 0; n; ++_) {
      b.push_back(n % 2);
      n /= 2;
    }
    while (b.back() == 0) b.pop_back();
    reverse(b.begin(), b.end());

    // cout << b << endl;

    static lli dp[N][M][K][M][K][M][K][L][L][L];
    fill(
      &dp[0][0][0][0][0][0][0][0][0][0],
      &dp[N - 1][M - 1][K - 1][M - 1][K - 1][M - 1][K - 1][L - 1][L - 1][L - 1] + 1,
      0);
    dp[0][0][false][0][false][0][false][false][false][false] = 1;
    for (int nth = 0; nth < b.size(); ++nth) {

      for (int i = 0; i < a[0]; ++i) {
        for (int l1 = 0; l1 < 2; ++l1) {

          for (int j = 0; j < a[1]; ++j) {
            for (int l2 = 0; l2 < 2; ++l2) {

              for (int k = 0; k < a[2]; ++k) {
                for (int l3 = 0; l3 < 2; ++l3) {

                  for (int p1 = 0; p1 < 2; ++p1) {
                    for (int p2 = 0; p2 < 2; ++p2) {
                      for (int p3 = 0; p3 < 2; ++p3) {

                        unless (dp[nth][i][l1][j][l2][k][l3][p1][p2][p3]) continue;

                        for (int s = 0; s <= (l1 || b[nth]); ++s) {
                          for (int t = 0; t <= (l2 || b[nth]); ++t) {
                            for (int u = 0; u <= (l3 || b[nth]); ++u) {

                              if (u != (s ^ t)) continue;

                              int ni = (i * 2 + s) % a[0];
                              int nj = (j * 2 + t) % a[1];
                              int nk = (k * 2 + u) % a[2];
                              bool nl1 = l1 || (b[nth] > s);
                              bool nl2 = l2 || (b[nth] > t);
                              bool nl3 = l3 || (b[nth] > u);

                              (dp[nth + 1][ni][nl1][nj][nl2][nk][nl3][p1 || s][p2 || t][p3 || u] +=
                               dp[nth][i][l1][j][l2][k][l3][p1][p2][p3]) %= mod;
                            }
                          }
                        }
                      }
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
    for (int l1 = 0; l1 <= 1; ++l1) {
      for (int l2 = 0; l2 <= 1; ++l2) {
        for (int l3 = 0; l3 <= 1; ++l3) {
          (z += dp[b.size()][0][l1][0][l2][0][l3][true][true][true]) %= mod;
        }
      }
    }
    cout << z << endl;
  }

  return 0;
}
