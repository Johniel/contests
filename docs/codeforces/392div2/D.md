# codeforces/392div2/D

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

#define MX(a, b) (a) = max((a), (b))
#define MN(a, b) (a) = min((a), (b))

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ull n;
  string s;
  while (cin >> n >> s) {
    const int N = s.size() + 1;
    ull dp[N];
    const ull inf = ULLONG_MAX;
    fill(dp, dp + N, inf);
    dp[0] = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      unless (dp[i] < inf) continue;
      ull x = 0;
      for (size_t j = i; j < s.size(); ++j) {
        x = (x * 10LL) + (s[j] - '0');
        if (n <= x) break;
        MN(dp[j + 1], dp[i] * n + x);
        if (s[i] == '0') break;
      }
    }
    cout << dp[s.size()] << endl;
  }

  return 0;
}
```
