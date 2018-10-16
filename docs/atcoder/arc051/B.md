# atcoder/arc051/B

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

int counter;
int gcd(int a, int b) {
  if (b == 0) return a;
  counter++;
  return gcd(b, a%b);
}
void f(int a, int b)
{
  counter = 0;
  gcd(a, b);
  printf("%d\n", counter);
  return ;
}

int main(int argc, char *argv[])
{
  int k;
  while (cin >> k) {
    if (k == 0) cout << "0 1" << endl;
    else {
      pair<int, int> p = make_pair(2, 1);
      while (--k) {
        p = make_pair(p.first + p.second, p.first);
      }
      cout << p.first << ' ' << p.second << endl;
    }
  }
  return 0;
}
}}{% endraw %}
```
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/arc051/B)
{% endraw %}
