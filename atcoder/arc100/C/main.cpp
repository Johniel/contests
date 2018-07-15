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

lli fn(vector<lli> a, lli b)
{
  lli sum = 0;
  for (int i = 0; i < a.size(); ++i) {
    sum += abs(a[i] - (b + i));
  }
  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<lli> a(n);
    each (i, a) cin >> i;


    lli large = 1e9 + 10;
    lli small = -large;
    lli right, left;
    for (int loop = 1000; loop--; ) {
      left = (large - small) / 3.0 + small;
      right = (large - small) * 2.0 / 3.0 + small;
      
      lli dl = fn(a, left);
      lli dr = fn(a, right);
      
      if (dr < dl) small = left;
      else large = right;      
    }

    lli x = fn(a, small);
    lli y = fn(a, small + 1);
    lli z = fn(a, large);
    cout << min({x, y, z}) << endl;
  }
  
  return 0;
}
