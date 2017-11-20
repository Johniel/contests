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
    
const lli mod = 1000000007;

lli fn(lli x, lli p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  lli y = fn(x, p / 2);
  y = (y * y) % mod;
  if (p % 2) {
    y = (y * x) % mod;
  }
  return y;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, m;
  int k;
  while (cin >> n >> m >> k) {
    lli y = fn(fn(2, n - 1), m - 1);
    if (k == 1) {
      cout << y << endl;
    } else {
      cout << ((n + m) % 2 ? 0 : y) << endl;
    }
  }
  
  return 0;
}
