# codeforces/GoodBye2016/A

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
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  while (cin >> n >> k) {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
      v.push_back((i + 1) * 5);
    }
    int mx = 0;
    for (int bit = 0; bit < (1 << n); ++bit) {
      int sum = 0;
      for (int i = 0; i < n; ++i) {
        if (bit & (1 << i)) {
          sum += v[i];
        }
      }
      
      if (sum + k <= 4 * 60) {
        mx = max(mx, __builtin_popcount(bit));
      }
    }
    cout << mx << endl;
  }
  
  return 0;
}
```
