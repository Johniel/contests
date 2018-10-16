# atcoder/agc002/A

## Codes
main.cpp
{% raw %}{{
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
  int a, b;
  while (cin >> a >> b) {
    if (0 < a) {
      cout << "Positive" << endl;
    } else if (a <= 0 && 0 <= b) {
      cout << "Zero" << endl;
    } else {
      if (a < 0 && (b - a) % 2 == 0) {
        cout << "Negative" << endl;
      } else {
        cout << "Positive" << endl;
      }
    }
  }
  return 0;
}
}}{% endraw %}
```
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/agc002/A)
{% endraw %}
