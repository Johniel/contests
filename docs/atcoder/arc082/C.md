# atcoder/arc082/C

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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int n;
  while (cin >> n) {
    vector<int> a(n);
    each (i, a) cin >> i;
    map<int, int> cnt;
    each (i, a) {
      ++cnt[i - 1];
      ++cnt[i + 1];
      ++cnt[i];
    }
    int x = -2;
    each (i, cnt) {
      if (cnt[x] < i.second) {
        x = i.first;
      }
    }
    cout << cnt[x] << endl;
  }
  
  return 0;
}
}}{% endraw %}
```
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/arc082/C)
