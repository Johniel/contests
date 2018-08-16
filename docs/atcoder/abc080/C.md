# atcoder/abc080/C

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

  int n;
  while (cin >> n) {
    int f[n][5][2];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
        for (int k = 0; k < 2; ++k) {
          cin >> f[i][j][k];
        }
      }
    }
    int p[n][10];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= 10; ++j) {
        cin >> p[i][j];
      }
    }
    
    lli mx = -(1LL << 60);
    for (int bit = 1; bit < (1 << 10); ++bit) {
      lli sum = 0;
      for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < 10; ++j) {
          cnt += (bool)((bit & (1 << j)) && f[i][j / 2][j % 2]);
        }
        sum += p[i][cnt];
      }
      mx = max(mx, sum);
    }
    cout << mx << endl;
  }
  
  return 0;
}
```
