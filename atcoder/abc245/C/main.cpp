// atcoder/abc245/C/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, k;
  while (cin >> n >> k) {
    vec<int> a(n), b(n);
    cin >> a >> b;

    const int N = 2 * 1e5 + 3;
    static bool dp[N][2];
    fill(&dp[0][0], &dp[N - 2][2 - 1] + 1, false);
    const int A = 0;
    const int B = 1;
    dp[0][A] = dp[0][B] = true;
    for (int i = 0; i + 1 < n; ++i) {
      if (dp[i][A] && abs(a[i + 1] - a[i]) <= k) dp[i + 1][A] = true;
      if (dp[i][B] && abs(a[i + 1] - b[i]) <= k) dp[i + 1][A] = true;
      if (dp[i][A] && abs(b[i + 1] - a[i]) <= k) dp[i + 1][B] = true;
      if (dp[i][B] && abs(b[i + 1] - b[i]) <= k) dp[i + 1][B] = true;
    }
    cout << ((dp[n - 1][A] || dp[n - 1][B]) ? "Yes" : "No") << endl;
  }

  return 0;
}
