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
  while (cin >> n) {
    lli sum = 0;
    lli best = 1 << 29;
    for (int i = 0; i < n; ++i) {
      lli a, p;
      cin >> a >> p;
      best = min(best, p);
      sum += best * a;
    }
    cout << sum << endl;
  }
  return 0;
}
