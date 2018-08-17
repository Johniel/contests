# codeforces/441div2/A

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

  int n, a, b, c;
  while (cin >> n >> a >> b >> c) {
    // Rabbit's and Owl's houses is a meters
    // Rabbit's and Eeyore's house is b meters
    // Owl's and Eeyore's house is c meters.

    const int N = 3;
    int g[N][N];
    g[0][1] = g[1][0] = a;
    g[0][2] = g[2][0] = b;
    g[1][2] = g[2][1] = c;

    lli sum = 0;
    int i = 0;
    --n;
    while (n--) {
      int j = (i + 1) % N;
      int k = (i - 1 + N) % N;
      if (g[i][j] < g[i][k]) {
        sum += g[i][j];
        i = j;
      } else {
        sum += g[i][k];
        i = k;
      }
    }
    cout << sum << endl;
  }
  
  return 0;
}
```
