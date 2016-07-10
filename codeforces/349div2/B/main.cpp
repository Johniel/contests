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
  int n;
  while (scanf("%d", &n) == 1) {
    vector<lli> v;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      v.push_back(x);
    }
    const lli sum = accumulate(v.begin(), v.end(), 0);
    const lli mx = *max_element(v.begin(), v.end());
    printf("%lld\n", labs((sum - mx) - mx) + 1LL);
  }
  return 0;
}
