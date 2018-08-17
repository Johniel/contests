# codeforces/336div2/D

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

const int N = 500 + 10;
int m[N];

int memo[N][N];
int rec(int begin, int end)
{
  unless (begin < end) return 1 << 28;
  int& ret = memo[begin][end];
  if (ret != -1) return ret;
  if (begin + 1 == end) return 1;
  if (begin + 2 == end) return 1 + (m[begin] != m[begin + 1]);

  int mn = end - begin;
  if (m[begin]  == m[end - 1]) {
    mn = min(mn, rec(begin + 1, end - 1));
  }

  for (int i = begin + 1; i < end; ++i) {
    mn = min(mn, rec(begin, i) + rec(i, end));
  }
  return ret = mn;
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", m + i);
    }
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    printf("%d\n", rec(0, n));
  }
  return 0;
}
```
