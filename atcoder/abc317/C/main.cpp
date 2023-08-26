// github.com/Johniel/contests
// atcoder/abc317/C/main.cpp

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
  int n, m;
  while (cin >> n >> m) {
    const int N = 10;
    const int BIT = (1 << N);

    vec<pair<int, lli>> g[n];
    for (int i = 0; i < m; ++i) {
      int a, b;
      lli c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back(make_pair(b, c));
      g[b].push_back(make_pair(a, c));
    }

    static lli dp[BIT][N];
    fill(&dp[0][0], &dp[BIT - 1][N - 1] + 1, -(1LL << 60));
    for (int i = 0; i < n; ++i) {
      dp[1 << i][i] = 0;
    }

    for (int bit = 0; bit < (1 << n); ++bit) {
      for (int i = 0; i < n; ++i) {
        unless (bit & (1 << i)) continue;
        each (e, g[i]) {
          auto [j, c] = e;
          if (bit & (1 << j)) continue;
          setmax(dp[bit | (1 << j)][j], dp[bit][i] + c);
        }
      }
    }

    cout << *max_element(&dp[0][0], &dp[BIT - 1][N - 1] + 1) << endl;
  }
  return 0;
}
