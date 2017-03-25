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

  lli a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    lli x = b;
    lli y = d;
    for (int i = 0; i < 100000000; ++i) {
      if (x == y) break;
      if (x < y) x += a;
      else y += c;
    }
    cout << (x == y ? x : -1) << endl;
  }
  
  return 0;
}
