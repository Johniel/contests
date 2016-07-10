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

const int N = 1000 + 10;
int dp[N][N];



int main(int argc, char *argv[])
{
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    int b[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", b + i);
    }

    int c = 0;

    while (true) {
      for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
          k -= abs(b[i] - a[i]);
          b[i] = a[i];
        }
      }
      if (k < 0) break;
      ++c;
      for (int i = 0; i < n; ++i) {
        b[i] -= a[i];
      }
    }
    
    printf("%d\n", c);
  }
  return 0;
}
