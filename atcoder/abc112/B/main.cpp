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

  int n, t;
  while (cin >> n >> t) {
    vector<pair<int, int>> v(n);
    each (i, v) {
      cin >> i.first >> i.second;
    }
    const int inf = 1 << 29;
    int mn = inf;
    each (i, v) {
      if (i.second <= t) {
        mn = min(mn, i.first);
      }
    }
    if (mn == inf) {
      cout << "TLE" << endl;
    } else {
      cout << mn << endl;
    }
  }
  
  return 0;
}
