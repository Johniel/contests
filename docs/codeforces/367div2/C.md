# codeforces/367div2/C

## Codes
```cpp
#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define MIN(A,B) (A=std::min(A,B))

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
  int n;
  while (scanf("%d", &n) == 1) {
    int c[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", c + i);
    }

    string s[n];
    string t[n];
    char buff[100000 + 10];
    for (int i = 0; i < n; ++i) {
      scanf("%s", buff);
      t[i] = s[i] = string(buff);
      reverse(t[i].begin(), t[i].end());
    }

    const lli inf = (1LL << 60);
    const int N = 100000 + 10;

    lli dp[N][2];
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, inf);
    dp[0][0] = 0;
    dp[0][1] = c[0];

    for (int i = 0; i + 1 < n; ++i) {
      const int j = i + 1;
      auto f = [&] (bool i_reversed, bool j_reversed) {
        string a = i_reversed ? t[i] : s[i];
        string b = j_reversed ? t[j] : s[j];
        if (a <= b) {
          MIN(dp[j][j_reversed], dp[i][i_reversed] + j_reversed * c[j]);
        }
        return ;
      };
      f(0, 0);
      f(0, 1);
      f(1, 0);
      f(1, 1);
    }

    lli mn = min(dp[n - 1][0], dp[n - 1][1]);
    printf("%lld\n", (mn < inf) ? mn : -1);
  }
  return 0;
}
```
