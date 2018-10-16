# codeforces/457div2/A

## Codes
main.cpp
{% raw %}
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

  int x, h, m;
  while (cin >> x >> h >> m) {
    int cnt = 0;
    auto fn = [&] () {
      return (h % 10 == 7) || (m % 10 == 7);
    };
    // printf("%02d:%02d\n", h, m);
    while (!fn()) {
      ++cnt;
      m -= x;
      if (m < 0) --h;
      m = (m + 60) % 60;
      h = (h + 24) % 24;
      // printf("%02d:%02d\n", h, m);
    }
    cout << cnt << endl;
  }
  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/codeforces)
+ [repository](https://github.com/Johniel/contests/tree/master/codeforces/457div2/A)
