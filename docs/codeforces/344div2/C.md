# codeforces/344div2/C

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
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    int a[n];
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < m; ++i) {
      int t, r;
      scanf("%d%d", &t, &r);
      while (v.size() && v.back().second < r) v.pop_back();
      v.push_back(make_pair(t, r));
    }
    int r = 0;
    each (i, v) r = max(r, i.second);
    sort(a, a + r);
    deque<int> q;
    for (int i = 0; i < r; ++i) {
      q.push_back(a[i]);
    }

    for (size_t i = 0; i + 1 < v.size(); ++i) {
      for (int loop = v[i].second - v[i + 1].second; loop--; ) {
        if (v[i].first == 2) {
          a[--r] = q.front();
          q.pop_front();
        } else {
          a[--r] = q.back();
          q.pop_back();
        }
      }
    }
    while (q.size()) {
      if (v.back().first == 2) {
        a[--r] = q.front();
        q.pop_front();
      } else {
        a[--r] = q.back();
        q.pop_back();
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i) printf(" ");
      printf("%d", a[i]);
    }
    puts("");
  }
  return 0;
}
```
