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
    map<lli, int> m;
    for (int i = 0; i < n; ++i) {
      lli a;
      cin >> a;
      ++m[a];
    }
    vector<lli> v;
    lli mx = 0;
    each (i, m) {
      if (2 <= i.second) v.push_back(i.first);
      if (4 <= i.second) mx = max(mx, i.first * i.first);
    }
    if (2 <= v.size()) {
      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());
      mx = max(mx, v[0] * v[1]);
    }
    cout << mx << endl;
  }
  
  return 0;
}
