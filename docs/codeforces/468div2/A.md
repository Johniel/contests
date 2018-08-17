# codeforces/468div2/A

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

  int a, b;
  while (cin >> a >> b) {
    unless (a < b) swap(a, b);

    const int N = 1000 + 10;
    lli sum[N];
    sum[0] = 0;
    for (int i = 1; i < N; ++i) {
      sum[i] = sum[i - 1] + i;
    }

    lli mn = 1LL << 62;
    for (int i = a; i <= b; ++i) {
      int x = abs(a - i);
      int y = abs(b - i);
      mn = min(mn, sum[x] + sum[y]);
    }
    cout << mn << endl;
  }
  
  return 0;
}
```
