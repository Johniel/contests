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
    vector<int> v(n);
    each (i, v) cin >> i;
    int mn = 360;
    for (int i = 0; i < v.size(); ++i) {
      int sum = 0;
      for (int j = 0; j < v.size(); ++j) {
        int k = (i + j) % v.size();
        sum += v[k];
        int a = sum;
        int b = 360 - sum;
        mn = min(mn, abs(a - b));
      }
    }
    cout << mn << endl;
  }
  
  return 0;
}
