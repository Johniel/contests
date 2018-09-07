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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

lli gcd(lli a, lli b)
{
  unless (a > b) swap(a, b);
  return b ? gcd(b, a % b) : a;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n;
  while (cin >> n) {
    lli x = 0;
    lli sum = n * (n + 1) / 2;

    for (int i = 1; i <= n; ++i) {
      if (gcd(sum, i) != 1) {
        x = i;
        break;
      }
    }
    
    if (x == 0) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
      cout << 1 << ' ' << x << endl;
      cout << n - 1 << flush;
      for (int i = 1; i <= n; ++i) {
        if (x != i) cout << ' ' << i;
      }
      cout << endl;
    }
  }
  
  return 0;
}
