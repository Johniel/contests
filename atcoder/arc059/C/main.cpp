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
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    lli mn = 1LL << 60;
    for (int target = -100; target <= 100; ++target) {
      lli sum = 0;
      for (int i = 0; i < n; ++i) {
        sum += (target - a[i]) * (target - a[i]);
      }
      mn = min(mn, sum);
    }
    cout << mn << endl;
  }
  return 0;
}
