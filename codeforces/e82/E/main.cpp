// codeforces/e82/E/main.cpp
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

  int tc;
  cin >> tc;

  string s, t;
  while (cin >> s >> t) {

    const int inf = 1 << 29;

    map<char, vector<int>> idx;
    for (int i = 0; i < s.size(); ++i) {
      idx[s[i]].push_back(i);
    }

    bool f = false;

    const int N = 400 + 5;
    static int dp[N][N];

    for (int x = 0; x < t.size(); ++x) {
      fill(&dp[0][0], &dp[N - 1][N - 1], inf);
      dp[0][x] = 0;
      for (int i = 0; i <= x; ++i) {
        for (int j = x; j <= t.size(); ++j) {
          if (dp[i][j] == inf) continue;
          if (i < x) {
            const vector<int>& v = idx[t[i]];
            auto itr = lower_bound(v.begin(), v.end(), dp[i][j]);
            if (itr != v.end()) {
              setmin(dp[i + 1][j], *itr + 1);
            }
          }
          if (j < t.size()) {
            const vector<int>& v = idx[t[j]];
            auto itr = lower_bound(v.begin(), v.end(), dp[i][j]);
            if (itr != v.end()) {
              setmin(dp[i][j + 1], *itr + 1);
            }
          }
        }
      }
      if (dp[x][t.size()] != inf) {
        f = true;
        break;
      }
    }
    cout << (f ? "YES" : "NO") << endl;
  }

  return 0;
}
