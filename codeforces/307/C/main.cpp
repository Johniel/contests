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

const int N = 100000 + 100;
lli p[N];
lli q[N];

bool f(lli turn)
{
  
}

int main(int argc, char *argv[])
{
  lli n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    lli small = 1;
    lli large = 1LL << 60;
    while (small < large) {
      lli mid = (small + large) / 2;
      if (f(mid)) small = mid;
      else large = mid;
    }
    cout << (f(large) ? large : small) << endl;
  }
  return 0;
}
