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

  const lli mod = 1e9 + 7;
  
  const int N = 1000000 + 10;
  lli x[N];
  x[0] = 0;
  x[1] = 1;
  for (int i = 2; i < N; ++i) {
    x[i] = (x[i - 1] << 1) + 1;
    x[i] %= mod;
  }

  string s;
  while (cin >> s) {
    int cnt = 0;
    lli sum = 0;
    each (c, s) {
      if (c == 'a') ++cnt;
      if (c == 'b') (sum += x[cnt]) %= mod;
    }
    cout << sum << endl;
  }
  
  return 0;
}
