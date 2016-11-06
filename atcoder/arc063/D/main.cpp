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
  int n, t;
  while (cin >> n >> t) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int mx[n];
    mx[n - 1] = a[n - 1];
    for (int i = n - 2; 0 <= i; --i) {
      mx[i] = max(mx[i + 1], a[i]);
    }

    // for (int i = 0; i < n; ++i) cout << mx[i] << ' ';cout << endl;
    
    int cnt = 0;
    int m = 0;
    for (int i = 0; i + 1 < n; ++i) {
      int x = mx[i + 1] - a[i];
      if (m < x) {
        cnt = 0;
        m = x;
      }
      if (m == x) {
        ++cnt;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
