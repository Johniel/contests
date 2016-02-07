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
  const int N = 500 + 5;
  lli g[N][N];
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    lli cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < k - 1; ++j) {
        g[i][j] = ++cnt;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = k - 1; j < n; ++j) {
        g[i][j] = ++cnt;
      }
    }

    lli sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += g[i][k - 1];
    }

    printf("%lld\n", sum);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j) printf(" ");
        printf("%lld", g[i][j]);
      }
      puts("");
    }
  }
  return 0;
}
