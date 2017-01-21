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

  int n;
  while (cin >> n) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int mx = *max_element(a, a + n);
    lli sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += mx - a[i];
    }
    cout << sum << endl;
  }
  
  return 0;
}
