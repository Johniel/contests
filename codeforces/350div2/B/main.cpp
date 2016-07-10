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
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      int m;
      scanf("%d", &m);
      v.push_back(m);
    }

    lli sum = 0;
    for (int i = 0; i < n; ++i) {
      lli s = sum + i + 1;
      if (k <= s) {
        printf("%d\n", v[k - sum - 1]);
        break;
      }
      sum = s;
    }
  }
  return 0;
}
