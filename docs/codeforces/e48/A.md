# codeforces/e48/A

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

  lli n, m;
  while (cin >> n >> m) {
    vector<lli> v(n);
    each (i, v) cin >> i;
    vector<lli> u;

    lli rem = m;
    each (i, v) {
      // cout << rem << endl;
      if (rem > i) {
        u.push_back(0);
        rem -= i;
      } else {
        lli x = i - rem;
        u.push_back(x / m + 1);
        rem = m - x % m;
      }
    }
    each (i, u) cout << i << ' '; cout << endl;
    // cout << endl;
  }
  
  return 0;
}
```
