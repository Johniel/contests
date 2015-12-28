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
  const lli m = 600851475143LL;
  const int N = 10000000;
  static bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for (lli i = 2; i * i < N; ++i) {
    for (lli j = 2; i * j < N; ++j) {
      prime[i * j] = false;
    }
  }
  lli mx = 1;
  for (int i = 0; i < N; ++i) {
    if (prime[i] && m % i == 0) mx = i;
  }
  cout << mx << endl;
  return 0;
}
