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

  lli n, k;
  while (cin >> n >> k) {
    if (k == 1) {
      cout << n << endl;
    } else {
      lli x = n;
      for (lli i = 1; i <= n; i *= 2) {
        if ((n & i) == 0) {
          x |= i;
        }
      }
      cout << x << endl;
    }
  }
  
  return 0;
}

