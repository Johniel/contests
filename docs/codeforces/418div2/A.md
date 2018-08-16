# codeforces/418div2/A

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

  int n, m;
  while (cin >> n >> m) {
    vector<int> x(n);
    vector<int> y(m);
    each (i, x) cin >> i;
    each (i, y) cin >> i;

    sort(y.begin(), y.end());
    reverse(y.begin(), y.end());

    for (int i = 0, j = 0; i < x.size(); ++i) {
      if (x[i] == 0) {
        x[i] = y[j++];
      }
    }
    vector<int> z = x;
    sort(z.begin(), z.end());
    cout << (x != z ? "Yes" : "No") << endl;
  }
  
  return 0;
}
```
