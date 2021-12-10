// atcoder/abc230/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <array>
#include <complex>

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

  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;

    vec<lli> v({0});
    each (i, a) v.push_back(i + v.back());

    map<lli, lli> m;
    const int N = 2 * 1e5 + 3;
    static lli dp[N];
    fill(dp, dp + N, 0);
    dp[0] = 1;
    lli sum = 0;
    for (int i = 1; i < v.size(); ++i) {
      (sum += dp[i - 1]) %= mod;
      (dp[i] += (sum - m[v[i]] + mod) % mod) %= mod;
      (m[v[i]] += dp[i]) %= mod;
    }
    cout << sum << endl;
  }

  return 0;
}
