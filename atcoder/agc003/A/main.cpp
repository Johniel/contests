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
  while (cin >> s) {
    int n = 0;
    n += (bool)count(s.begin(), s.end(), 'N');
    n -= (bool)count(s.begin(), s.end(), 'S');
    int m = 0;
    m += (bool)count(s.begin(), s.end(), 'E');
    m -= (bool)count(s.begin(), s.end(), 'W');
    cout << (n == 0 && m == 0 ? "Yes" : "No") << endl;
  }
  return 0;
}
