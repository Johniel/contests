# codeforces/340div2/D

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
  pair<int, int> a, b, c;
  while (scanf("%d%d%d%d%d%d", &a.first, &a.second, &b.first, &b.second, &c.first, &c.second) == 6) {

    if (a.first == b.first && a.first == c.first) {
      puts("1");
    } else if (a.second == b.second && a.second == c.second) {
      puts("1");
    } else {
      vector<pair<int,int>> v = {a, b ,c};
      sort(v.begin(), v.end());
      bool f = false;
      do {
        f = f || ((v[0].first  == v[1].first)  && !(min(v[0].second,  v[1].second)  < v[2].second && v[2].second   < max(v[0].second, v[1].second)));
        f = f || ((v[0].second == v[1].second) && !(min(v[0].first, v[1].first) < v[2].first && v[2].first < max(v[0].first,v[1].first)));
      } while (next_permutation(v.begin(), v.end()));
      puts(f ? "2" : "3");
    }
  }
  
  return 0;
}
```
