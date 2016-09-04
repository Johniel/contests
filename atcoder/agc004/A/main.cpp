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

lli f(lli a, lli b, lli c)
{
  lli n = a / 2;

  lli x = n * b * c;
  lli y = (a - n) * b * c;
  return labs(x - y);
}

int main(int argc, char *argv[])
{
  lli a, b, c;
  while (cin >> a >> b >> c) {
    lli mn = 1LL << 60;
    vector<lli> v = {a, b, c};
    sort(v.begin(), v.end());
    do {
      mn = min(mn, f(v[0], v[1], v[2]));
    } while (next_permutation(v.begin(), v.end()));
    cout << mn << endl;
  }
  return 0;
}
