// atcoder/abc197/E/main.cpp
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

  int n;
  while (cin >> n) {
    vec<pair<int, int>> v(n);
    cin >> v;
    v.push_back(make_pair(0, 0));
    {
      int mx = -1;
      each (i, v) setmax(mx, i.second);
      v.push_back(make_pair(0, mx + 1));
    }

    vec<int> c;
    each (i, v) c.push_back(i.second);
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    map<int, int> m;
    for (int i = 0; i < c.size(); ++i) {
      m[c[i]] = i;
    }
    each (i, v) i.second = m[i.second];

    const int N = 2 * 1e5 + 3;
    vec<int> u[N];
    each (i, v) {
      u[i.second].push_back(i.first);
    }

    for (int i = 0; i < N; ++i) {
      sort(u[i].begin(), u[i].end());
    }

    const lli inf = 1LL << 60;
    const int MN = 0;
    const int MX = 1;
    static lli dp[N][2];
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, inf);
    dp[0][MN] = dp[0][MX] = 0;
    for (int i = 0; i + 1 < c.size(); ++i) {
      // cout << u[i] << endl;
      const lli mn = u[i + 1].front();
      const lli mx = u[i + 1].back();
      const lli prev_mn = u[i].front();
      const lli prev_mx = u[i].back();

      { // prev_mn -> mn
        setmin(dp[i + 1][MN], dp[i][MN] + abs(prev_mn - mx) + abs(mn - mx));
      }
      { // prev_mn -> mx
        setmin(dp[i + 1][MX], dp[i][MN] + abs(prev_mn - mn) + abs(mn - mx));
      }
      { // prev_mx -> mn
        setmin(dp[i + 1][MN], dp[i][MX] + abs(prev_mx - mx) + abs(mn - mx));
      }
      { // prev_mx -> mx
        setmin(dp[i + 1][MX], dp[i][MX] + abs(prev_mx - mn) + abs(mn - mx));
      }
    }
    cout << min(dp[c.size() - 1][MN], dp[c.size() - 1][MX]) << endl;
  }

  return 0;
}
