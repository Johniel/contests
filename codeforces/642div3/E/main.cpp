// codeforces/642div3/E/main.cpp
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
constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int n, k;
  str s;
  while (cin >> n >> k >> s) {
    int mn = count(s.begin(), s.end(), '1');

    const int o = count(s.begin(), s.end(), '1');

    const int N = 1e6 + 5;
    static int dp[N][3];
    static char t[N];

    for (int i = 0; i < k; ++i) {
      int y = 0;
      int x = o;
      const int inf = 1 << 29;
      for (int j = i; j < s.size(); j += k) {
        dp[y][0] = dp[y][1] = dp[y][2] = inf;
        t[y++] = s[j];
        x -= (s[j] == '1');
      }
      dp[y][0] = dp[y][1] = dp[y][2] = inf;

      dp[0][0] = 0;
      dp[0][1] = 0;
      for (int j = 0; j < y; ++j) {
        setmin(dp[j + 1][0], dp[j][0] + (t[j] == '1'));
        setmin(dp[j + 1][1], dp[j][1] + (t[j] == '0'));
        setmin(dp[j + 1][2], dp[j][2] + (t[j] == '1'));

        setmin(dp[j + 1][1], dp[j][0] + (t[j] == '0'));
        setmin(dp[j + 1][2], dp[j][1] + (t[j] == '1'));
      }
      x += min({dp[y][0], dp[y][1], dp[y][2]});
      t[y] = 0;
      setmin(mn, x);
    }

    cout << mn << endl;
  }

  return 0;
}
