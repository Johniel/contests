# codeforces/416div2/A

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
  lli a, b;
  while (cin >> a >> b) {
    int turn = 0;
    int c = 1;
    while (c <= a) {
      ++turn;
      a -= c++;
      swap(a, b);
    }
    cout << (turn % 2 ? "Valera" : "Vladik") << endl;
  }
  
  return 0;
}
```
