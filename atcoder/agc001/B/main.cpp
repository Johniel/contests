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

lli f(lli n, lli x)
{
  lli sum = 0;
  sum += 3 * x * ((n - x) / x);
  lli y = ((n - x) % x);
  if (y) sum += f(x + y, y);
  return sum;
}

int main(int argc, char *argv[])
{
  lli n, x;
  while (cin >> n >> x) {
    cout << f(n, x) << endl;
  }
  return 0;
}
