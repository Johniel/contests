// atcoder/abc224/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

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
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  const int N = 2 * 1e5 + 3;
  static lli w[N];
  // 続ける,足す,の2択。
  w[0] = 1;
  for (int i = 1; i < N; ++i) {
    w[i] = (w[i - 1] * 2) % mod;
  }
  static lli z[N];
  for (int i = 1; i < N; ++i) {
    z[i] = (z[i - 1] + w[i]) % mod;
  }

  str s;
  while (cin >> s) {
    vec<lli> v;
    each (c, s) v.push_back(c - '0');
    static pair<lli, lli> dp[N];
    fill(dp, dp + N, make_pair(0, 0));
    for (int i = 0; i < s.size(); ++i) {
      dp[i + 1].first += (dp[i].first * 10) % mod;
      dp[i + 1].first %= mod;

      dp[i + 1].first += (w[i] * v[i]) % mod;
      dp[i + 1].first %= mod;

      dp[i + 1].second += (dp[i].first * w[v.size() - i - 1]) % mod;
      dp[i + 1].second %= mod;
      dp[i + 1].second += dp[i].second;
      dp[i + 1].second %= mod;
    }
    // for (int i = 0; i <= v.size(); ++i) cout << v[i] << ' ' << dp[i] << endl; cout << endl;
    cout << (dp[v.size()].first + dp[v.size()].second) % mod << endl;
    // break;
  }

  return 0;
}
