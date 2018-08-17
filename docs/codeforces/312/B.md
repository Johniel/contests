# codeforces/312/B

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
  int n;
  while (cin >> n) {
    const int N = 1000000 + 10;
    static int cnt[N];
    static int mn[N];
    static int mx[N];
    const int inf = 1 << 29;
    fill(cnt, cnt + N, 0);
    fill(mn, mn + N, inf);
    fill(mx, mx + N, -inf);
    int best = -1;
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;
      mn[m] = min(mn[m], i);
      mx[m] = max(mx[m], i);
      ++cnt[m];
      if (i == 0) best = m;
    }
    for (int i = 0; i < N; ++i) {
      if (cnt[i] == 0) continue;
      if (cnt[best] < cnt[i])  {
        best = i;
      }
      if (cnt[best] == cnt[i] && (mx[best] - mn[best]) > (mx[i] - mn[i])) {
        best = i;
      }
    }
    cout << mn[best] + 1 << ' ' << mx[best] + 1 << endl;
  }
  return 0;
}
```
