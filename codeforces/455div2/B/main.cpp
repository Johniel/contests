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
    if (n == 1) cout << 1 << endl;
    else {
      lli sum = 0;
      for (int i = n; 1 <= i; i -= 2) {
        sum += i;
      }
      cout << sum << endl;
    }
   
  }
  
  return 0;
}
