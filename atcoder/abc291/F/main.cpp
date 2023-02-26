// github.com/Johniel/contests
// atcoder/abc291/F/main.cpp

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
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vec<str> g(n);
    cin >> g;
    const int N = 1e5 + 3;
    const int M = 11;
    const lli inf = 1LL << 60;

    static lli dp1[N];
    fill(dp1, dp1 + N, inf);
    dp1[0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (g[i][j] == '1' && i + (j + 1) < n) {
          setmin(dp1[i + (j + 1)], dp1[i] + 1);
        }
      }
    }

    static lli dpN[N];
    fill(dpN, dpN + N, inf);
    dpN[n - 1] = 0;
    for (int i = n - 1; 0 <= i; --i) {
      for (int j = 0; j < m; ++j) {
        int k = i - (j + 1);
        if (0 <= k && g[k][j] == '1') {
          setmin(dpN[k], dpN[i] + 1);
        }
      }
    }

    // for (int i = 0; i < n; ++i) cout << dp1[i] << ' '; cout << endl;
    // for (int i = 0; i < n; ++i) cout << dpN[i] << ' '; cout << endl;

    for (int k = 1; k < n - 1; ++k) {
      lli mn = inf;
      for (int i = max(0, k - m); i < k; ++i) {
        for (int a = 0; a < m; ++a) {
          if (g[i][a] == '1') {
            int j = i + a + 1;
            // cout << make_pair(i, j) << endl;
            if (i < k && k < j) setmin(mn, dp1[i] + dpN[j] + 1);
          }
        }
      }
      if (mn == inf) cout << -1 << ' ';
      else cout << mn << ' ';
    }
    cout << endl;
  }
  return 0;
}
