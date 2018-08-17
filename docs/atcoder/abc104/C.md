# atcoder/abc104/C

## Codes
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

  lli d, g;
  while (cin >> d >> g) {
    g /= 100;

    vector<pair<int, lli>> v(d);
    each (i, v) {
      cin >> i.first >> i.second;
      i.second /= 100;
    }

    const int D = 10 + 5;
    const int N = 10 * 100 * 3;
    const lli inf = 1LL << 60;
    static lli dp[D][N];
    fill(&dp[0][0], &dp[D - 1][N - 1] + 1, -inf);
    dp[0][0] = 0;

    for (int i = 0; i < v.size(); ++i) {
      for (int solved = 0; solved <= 10*100; ++solved) {
        for (int added = 0; added <= v[i].first; ++added) {
          int x = added * (i + 1);
          int y = v[i].second * (added == v[i].first);
          dp[i + 1][solved + added] = max(dp[i + 1][solved + added], dp[i][solved] + x + y);
        }
      }
    }

    int mn = 1 << 29;
    for (int i = 0; i < N; ++i) {
      if (g <= dp[d][i]) mn = min(mn, i);
    }
    cout << mn << endl;
  }

  return 0;
}
```
