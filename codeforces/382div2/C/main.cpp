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
  lli n;
  while (scanf("%lld", &n) == 1) {
    const int N = 100;
    lli a[N];
    a[0] = a[1] = 0;
    a[2] = 1;
    a[3] = 2;
    for (int i = 4; i < N; ++i) {
      a[i] = a[i - 1] + a[i - 2];
    }
    for (int i = 0; i < 10; ++i) {
      // cout << a[i] << endl;
    }
    int j;
    for (int i = 0; i < N; ++i) {
      if (1000000000000000000 < a[i]) break;
      if (a[i] <= n) {
        j = i;
      }
    }
    printf("%d\n", j - 2);
  }
  return 0;
}
