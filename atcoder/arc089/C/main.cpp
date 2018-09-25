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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    const int m = n + 1;
    int t[m];
    int x[m];
    int y[m];
    t[0] = x[0] = y[0] = 0;
    for (int i = 0; i < n; ++i) {
      cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
    }
    bool f = true;
    for (int i = 0; i + 1 < n + 1; ++i) {
      int md = abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);
      int z = abs(t[i] - t[i + 1]);
      if (z < md) f = false;
      else {
        f = f && ((z - md) % 2 == 0);
      }
    }
    cout << (f ? "Yes" : "No") << endl;
  }
  
  return 0;
}
