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

  int n, t;
  while (cin >> n >> t) {
    lli x[n];
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
    }
    lli sum = 0;
    for (int i = 0; i + 1 < n; ++i) {
      int j = i + 1;
      if (x[j] <= (x[i] + t)) sum += x[j] - x[i];
      else sum += t;
    }
    cout << sum + t << endl;
  }

  return 0;
}
