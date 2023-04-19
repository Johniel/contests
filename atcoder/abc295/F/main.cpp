// github.com/Johniel/contests
// atcoder/abc295/F/main.cpp

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
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

lli fn(str s, str t)
{
  const int N = 20;
  static lli dp[N][N][2][2];
  fill(&dp[0][0][0][0], &dp[N - 1][N - 1][2 - 1][2 - 1] + 1, 0);
  dp[0][0][false][false] = 1;
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j <= t.size(); ++j) {
      for (int small = 0; small < 2; ++small) {
        for (int started = 0; started < 2; ++started) {
          for (int k = 0; k <= (small ? 9 : s[i] - '0'); ++k) {
            const bool f = small || (s[i] - '0' > k);
            if ((started || k) && j < t.size() && t[j] - '0' == k) {
              dp[i + 1][j + 1][f][started || k] += dp[i][j][small][started];
            }
            if (j == 0 || j == t.size()) {
              dp[i + 1][j][f][started || k] += dp[i][j][small][started];
            }
          }
        }
      }
    }
  }
  return dp[s.size()][t.size()][false][true] + dp[s.size()][t.size()][true][true];
}

int main(int argc, char *argv[])
{
  if (0) {
    cout << fn("122", "22") << endl; // 022, 122
    cout << fn("222", "22") << endl; // 022*1, 122*1, 220*1, 221*1, 222*2
    cout << fn("234", "22") << endl; // 022*1, 122*1, 22{0,1}*1, 222*2, 22{3,9}*1,
    cout << fn("22", "22") << endl; // 22*1
    cout << fn("23", "22") << endl; // 22*1
    cout << fn("1111", "11") << endl; // 22*1
    return 0;
  }

  int _;
  cin >> _;

  str s;
  lli L, R;
  while (cin >> s >> L >> R) {
    char buff1[20];
    char buff2[20];
    sprintf(buff1, "%lld", L - 1);
    sprintf(buff2, "%lld", R);
    cout << fn(str(buff2), s) - fn(str(buff1), s) << endl;
  }
  return 0;
}
