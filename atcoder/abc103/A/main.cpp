#include <bits/stdc++.h>
 
#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
 
using namespace std;
 
typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;
 
template <typename P, typename Q>
ostream& operator<<(ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
 
template <typename T>
ostream& operator<<(ostream& os, vector<T> v)
{
  os << "(";
  each (i, v)
    os << i << ",";
  os << ")";
  return os;
}
 
int main(int argc, char* argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  vector<int> a(3);
  while (cin >> a[0] >> a[1] >> a[2]) {
    sort(a.begin(), a.end());
    cout << (a[2] - a[1]) + (a[1] - a[0]) << endl;
  }
 
  return 0;
}
