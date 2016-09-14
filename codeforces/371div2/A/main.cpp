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
  lli a, b, c, d, k;
  while (cin >> a >> b >> c >> d >> k) {
    lli x = max(a, c);
    lli y = min(b, d);
    lli z = y - x + 1;
    if (x <= k && k <= y) --z;
    cout << max(z, 0LL) << endl;
  }
  return 0;
}
