# codeforces/382div2/B

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
  int n, n1, n2;
  while (scanf("%d%d%d", &n, &n1, &n2) == 3) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    if (n1 > n2) swap(n1, n2);
    double x = 0;
    double y = 0;
    for (int i = 0; i < n1; ++i) {
      x += v[i];
    }
    for (int i = n1; i < n1 + n2; ++i) {
      y += v[i];
    }
    // cout << x << ' ' << y << endl;
    printf("%.10lf\n", x / n1 + y / n2);
  }
  return 0;
}
```
