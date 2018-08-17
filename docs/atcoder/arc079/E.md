# atcoder/arc079/E

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

  int n;
  while (cin >> n) {
    vector<lli> a(n);
    each (i, a) cin >> i;
    lli sum = 0;
    while (true) {
      sort(a.begin(), a.end());
      reverse(a.begin(), a.end());
      lli x = a[0] / a.size();
      if (x == 0) break;
      sum += x;
      a[0] %= a.size();
      for (int i = 1; i < a.size(); ++i) {
        a[i] += x;
      }
    }
    cout << sum << endl;
  }
  
  return 0;
}
```
