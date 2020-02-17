// atcoder/abc155/E/main.cpp
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
template<typename P, typename Q> inline pair<Q, P> reverse(pair<P, Q> p) { return make_pair(p.second, p.first); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  str s;
  while (cin >> s) {
    vector<int> v(s.begin(), s.end());
    each (i, v) i -= '0';
    reverse(v.begin(), v.end());

    const int N = 1e6 + 5;
    const int M = 2;
    static lli dp[N][M];
    const lli inf = 1LL << 60;
    fill(&dp[0][0], &dp[N - 1][M - 1] + 1, inf);
    dp[0][false] = 0;

    for (int i = 0; i < v.size(); ++i) {
      {
        setmin(dp[i + 1][true],  dp[i][false] + (10 - v[i]));
        setmin(dp[i + 1][false], dp[i][false] + v[i]);
      }
      {
        setmin(dp[i + 1][true],  dp[i][true] + (10 - v[i] - 1));
        setmin(dp[i + 1][false], dp[i][true] + v[i] + 1);
      }
    }

    cout << min(dp[s.size()][0], dp[s.size()][1] + 1) << endl;
  }

  return 0;
}
