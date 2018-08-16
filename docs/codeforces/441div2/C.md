# codeforces/441div2/C

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

lli fn(lli x)
{
  if (x < 0) return x;
  lli sum = x;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n;
  while (cin >> n) {
    vector<lli> v;
    for (int i = 0; i <= 10000; ++i) {
      if (fn(n - i) == n) {
        v.push_back(n - i);
      }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    each (i, v) cout << i << endl;
  }
  return 0;
}
```
