# codeforces/568div2/C

## Codes
main.cpp
{% raw %}
```cpp
// codeforces/568div2/C/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<int> v(n);
    cin >> v;

    const int N = 100 + 5;
    const int M = 100 + 5;
    int dp[N][M];
    fill(&dp[0][0], &dp[N - 1][M - 1], 1 << 28);
    dp[0][0] = 0;
    vector<int> u;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j <= m; ++j) {
        if (j + v[i] <= m) {
          setmin(dp[i + 1][j + v[i]], dp[i][j]);
        }
        setmin(dp[i + 2][j], dp[i][j] + 1);
      }

      int mn = 1 << 28;
      for (int j = 0; j <= m; ++j) {
        setmin(mn, dp[i + 1][j]);
        setmin(dp[i + 1][j], dp[i + 2][j]);
        dp[i + 2][j] = 1 << 28;
      }
      u.push_back(mn);
    }

    each (i, u) cout << i << ' ' ; cout << endl;
  }

  return 0;
}
```
{% endraw %}
main2.cpp
{% raw %}
```cpp
// codeforces/568div2/C/main2.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<int> v(n);
    cin >> v;

    const int N = 101;
    int cnt[N];
    fill(cnt, cnt + N, 0);

    vector<int> u;
    for (int i = 0; i < v.size(); ++i) {
      lli sum = v[i];
      int x = 0;
      for (int j = 0; j < N; ++j) {
        if (sum + cnt[j] * j <= m) {
          x += cnt[j];
          sum += cnt[j] * j;
        } else {
          int y = (m - sum) / j;
          x += y;
          break;
        }
      }
      ++cnt[v[i]];
      u.push_back(i - x);
    }

    each (i, u) cout << i << ' '; cout << endl;
  }

  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/codeforces)
+ [repository](https://github.com/Johniel/contests/tree/master/codeforces/568div2/C)
