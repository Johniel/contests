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

  string a, b;
  while (cin >> a >> b) {
    string s;
    s += a[0];
    for (int i = 1; i < a.size(); ++i) {
      if (a[i] < b[0]) {
        s += a[i];
      } else {
        break;
      }
    }
    s += b[0];
    cout << s << endl;
  }

  return 0;
}
