# [Odds and Ends](http://codeforces.com/contest/849/problem/A)

DP\[どこまで見た\]\[偶奇\] = 到達可能か

## Code
```cpp
#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> a(n);
    each (i, a) cin >> i;
    const int N = 100 + 5;
    const int ODD = 0;
    const int EVEN = ODD ^ 1;
    bool dp[N][2];
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, false);
    if (a[0] % 2) {
      dp[0][EVEN] = true;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (dp[i][j]) {
          int len = 0;
          for (int k = i; k < n; ++k) {
            ++len;
            if (len % 2 && a[k] % 2) {
              dp[k + 1][j ^ 1] = true;
            }
          }
        }
      }
    }
    cout << (dp[n][ODD] ? "Yes" : "No") << endl;
  }

  return 0;
}
```
