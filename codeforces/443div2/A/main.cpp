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
    lli x = 0;
    for (int i = 0; i < n; ++i) {
      if (i) ++x;
      lli s, d;
      cin >> s >> d;
      if (x <= s) {
        x = s;
      } else {
        lli m = ((x - s) / d) + (bool)((x - s) % d);
        x = s + m * d;
      }
    }
    cout << x << endl;
  }
  
  return 0;
}
