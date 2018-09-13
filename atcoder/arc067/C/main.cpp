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

const lli mod = 1e9 + 7;
const lli N = 1000 + 10;

map<int, int> f(int n, map<int, int>& cnt)
{
  for (int i = 2; i <= n; ++i) {
    while (n % i == 0) {
      n /= i;
      ++cnt[i];
    }
  }
  return cnt;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    map<int, int> m;
    for (int i = 2; i <= n; ++i) {
      f(i, m);
    }

    lli x = 1;
    each (i, m) {
      x = (x * (i.second + 1)) % mod;
    }
    cout << x << endl;
  }

  return 0;
}
