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
    int o = 0;
    int e = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (a % 2 == 0) ++e;
      else ++o;
    }
    cout <<  ((o % 2 == 0) ? "YES" : "NO") << endl;
  }
  return 0;
}
