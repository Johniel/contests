# atcoder/arc072/C

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

lli f(int a[], const int N, int mod)
{
  lli sum = 0;
  lli cost = 0;

  for (int i = 0; i < N; ++i) {
    sum += a[i];
    if (i % 2 == mod) {
      if (sum < 1) {
        cost += abs(sum) + 1;
        sum = 1;
      }
    } else {
      if (-1 < sum) {
        cost += abs(sum) + 1;
        sum = -1;
      }
    }
  }
  
  return cost;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (cin >> n) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << min(f(a, n, 0), f(a, n, 1)) << endl;
  }
  return 0;
}
```
