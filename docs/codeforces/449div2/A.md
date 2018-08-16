# codeforces/449div2/A

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
  string s;
  while (cin >> n >> m >> s) {
    while (m--) {
      int a, b;
      char c, d;
      cin >> a >> b >> c >> d;
      for (int i = a; i <= b; ++i) {
        if (s[i - 1] == c) {
          s[i - 1] = d;
        }
      }
    }
    cout << s << endl;
  }
  
  return 0;
}
```
