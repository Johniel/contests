# codeforces/429div2/A

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

  int n, k;
  while (cin >> n >> k) {
    string s;
    cin >> s;
    map<char, int> m;
    int mx = 0;
    each (c, s) mx = max(mx, ++m[c]);
    cout << (mx <= k ? "YES" : "NO") << endl;
  }
  
  return 0;
}
```
