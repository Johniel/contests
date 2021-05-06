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
  string s;
  int a, b,c ,d;
  while (cin >> s >> a >> b >> c >> d) {
    for (int i = 0; i < s.size(); ++i) {
      if (set<int>({a, b, c, d}).count(i)) cout << "\"";
      cout << s[i];
    }
    if (s.size() == max({a, b, c, d})) cout << "\"";
    cout << endl;
  }
  return 0;
}
