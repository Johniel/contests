# codeforces/370div2/B

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
  string s;
  while (cin >> s) {
    if (s.size() % 2) {
      cout << -1 << endl;
      continue;
    }
    int U = count(s.begin(), s.end(), 'U');
    int D = count(s.begin(), s.end(), 'D');
    int R = count(s.begin(), s.end(), 'R');
    int L = count(s.begin(), s.end(), 'L');

    int x = abs(U - D);
    int y = abs(L - R);

    cout << min(x, y) + (max(x, y) - min(x, y)) / 2 << endl;
    
  }
  return 0;
}
```
