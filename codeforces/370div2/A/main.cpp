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
  while (scanf("%d", &n) == 1) {
    lli a[n];
    for (lli i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<lli> v;
    for (lli i = 0; i + 1 < n; ++i) {
      v.push_back(a[i] + a[i + 1]);
    }
    each (i, v) cout << i << ' ';
    cout << a[n - 1] << endl;
  }
  return 0;
}
