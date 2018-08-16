# codeforces/350div2/C

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
  int n;
  while (scanf("%d", &n) == 1) {
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      int m;
      scanf("%d", &m);
      ++cnt[m];
    }

    vector<pair<int, int>> v;
    int m;
    scanf("%d", &m);
    v.resize(m);
    
    for (int i = 0; i < m; ++i) {
      int a;
      scanf("%d", &a);
      v[i].first = a;
    }
    
    for (int i = 0; i < m; ++i) {
      int a;
      scanf("%d", &a);
      v[i].second = a;
    }    
    
    int j = 0;
    for (int i = 0; i < m; ++i) {
      if (cnt[v[j].first] < cnt[v[i].first]) j = i;
      if (cnt[v[j].first] == cnt[v[i].first] && cnt[v[j].second] < cnt[v[i].second]) j = i;
    }
    printf("%d\n", j + 1);
  }
  return 0;
}
```
