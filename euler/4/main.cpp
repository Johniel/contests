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
  int mx = 0;
  for (int i = 100; i < 1000; ++i) {
    for (int j = 100; j < 1000; ++j) {
      char buff[100];
      sprintf(buff, "%d", i * j);
      string s(buff);
      string t = s;
      reverse(t.begin(), t.end());
      if (t == s) mx = max(mx, i * j);
    }
  }
  cout << mx << endl;
  return 0;
}
