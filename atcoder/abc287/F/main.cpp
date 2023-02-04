// github.com/Johniel/contests
// atcoder/abc287/F/main.cpp

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

const int N = 5000 + 3;
vec<int> g[N];

using T = array<vec<lli>, 2>;

T rec(int curr, int prev)
{
  T t;
  t[0] = t[1] = vec<lli>(2, 0);
  t[0][0] = t[1][1] = 1;
  each (next, g[curr]) {
    if (next == prev) continue;
    T u = rec(next, curr);

    T dp;
    dp[0] = dp[1] = vec<lli>(t[0].size() + u[0].size() - 1, 0);
    for (int i = 0; i < t[0].size(); ++i) {
      for (int j = 0; j < u[0].size(); ++j) {
        dp[0][i + j] += t[0][i] * (u[0][j] + u[1][j]) % mod;
        dp[1][i + j] += t[1][i] * u[0][j] % mod;
        dp[0][i + j] %= mod;
        dp[1][i + j] %= mod;
        if (i + j) (dp[1][i + j - 1] += t[1][i] * u[1][j] % mod) %= mod;
      }
    }
    t = dp;
  }
  return t;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    auto t = rec(0, 0);
    for (int i = 1; i <= n; ++i) {
      cout << (t[0].at(i) + t[1].at(i)) % mod << endl;
    }
  }
  return 0;
}
