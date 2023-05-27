// github.com/Johniel/contests
// atcoder/abc303/D/main.cpp

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

int main(int argc, char *argv[])
{
  lli akey, sa, caps;
  str s;
  while (cin >> akey >> sa >> caps >> s) {
    const int N = 3 * 1e5 + 3;
    static lli dp[N][2];
    const lli inf = 1LL << 60;
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, inf);
    dp[0][false] = 0;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < 2; ++j) {
        int x = j;
        for (int caps1 = 0; caps1 < 2; ++caps1) {
          x = (x ^ caps1);
          for (int caps2 = 0; caps2 < 2; ++caps2) {
            for (int shift = 0; shift < 2; ++shift) {
              x = (x ^ shift);
              char c = (x ? 'A' : 'a');
              if (s[i] == c) {
                lli w = 0;
                if (caps1) w += caps;
                if (shift) w += sa;
                else w += akey;
                if (caps2) w += caps;
                setmin(dp[i + 1][j ^ caps1 ^ caps2], dp[i][j] + w);
              }
            }
          }
        }
      }
    }
    cout << min(dp[s.size()][false], dp[s.size()][true]) << endl;
  }
  return 0;
}
