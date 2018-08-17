# atcoder/arc086/C

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

  int n, k;
  while (cin >> n >> k) {
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      ++cnt[x];
    }
    vector<pair<int, int>> v;
    each (i, cnt) v.push_back(make_pair(i.second, i.first));
    sort(v.begin(), v.end());
    lli sum = 0;
    for (int i = 0; i + k < v.size(); ++i) {
      sum += v[i].first;
    }
    cout << sum << endl;
  }
  
  return 0;
}
```
