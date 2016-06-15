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
  const lli A = 1234567;
  const lli B = 123456;
  const lli C = 1234;
  lli n;
  while (scanf("%lld", &n) == 1) {
    bool f = false;
    for (int a = 0; (a * A) <= n; ++a) {
      for (int b = 0; (a * A) + (b * B) <= n; ++b) {
        lli m = n - (a * A) - (b * B);
        if (m % C == 0) {
          f = true;
        }
      }
    }
    puts(f ? "YES" : "NO");
  }
  return 0;
}
