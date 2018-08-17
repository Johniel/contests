# codeforces/444div2/A

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

  string s;
  while (cin >> s) {
    reverse(s.begin(), s.end());
    bool f = false;
    int z = 0;
    each (c, s) {
      z += (c == '0');
      f = f || (6 <= z && c == '1');
    }
    cout << (f ? "yes" : "no") << endl;
  }
  
  return 0;
}
```
