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
    vector<int> a(n);
    each (i, a) cin >> i;

    int bit = 0;

    int begin = 0;
    int end = 0;

    lli sum = 0;
    while (begin <= end) {
      while (end < n) {
        if (bit & a[end]) break;
        bit |= a[end];
        ++end;
      }

      sum += end - begin;
      bit ^= a[begin];
      ++begin;
    }

    cout << sum << endl;
  }

  return 0;
}
