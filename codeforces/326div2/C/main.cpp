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
  const int N = 50000000 + 10;
  int w[N];
  int n;
  while (scanf("%d", &n) == 1 && n) {
    fill(w, w + N, 0);
    for (int i = 0; i < n; ++i) {
      int m;
      scanf("%d", &m);
      ++w[m];
    }
    int carry = 0;
    for (int i = 0; i < N; ++i) {
      w[i] += carry;
      carry = w[i] / 2;
      w[i] %= 2;
    }
    printf("%d\n", accumulate(w, w + N, 0));
  }
  return 0;
}
