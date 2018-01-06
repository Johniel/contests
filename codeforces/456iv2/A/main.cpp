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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli a, b;
  while (cin >> a >> b) {
    lli x, y, z;
    cin >> x >> y >> z;

    a -= x * 2;

    a -= y;
    b -= y;

    b -= z * 3;

    cout << abs(min<lli>(0, a) + min<lli>(0, b)) << endl;
  }
  
  
  return 0;
}
