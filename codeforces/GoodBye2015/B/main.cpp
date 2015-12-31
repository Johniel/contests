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

string b2s(lli n)
{
  string s;
  while (n) {
    s += '0' + (n % 2);
    n /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}

int main(int argc, char *argv[])
{
  lli a, b;
  while (scanf("%lld%lld", &a, &b) == 2) {
    int cnt = 0;
    for (int len = 0; len < 62; ++len) {
      const lli mask = (1LL << (len - 1)) - 1;
      for (int nth = 0; nth < len - 2; ++nth) {
        const lli x = mask ^ (1LL << nth);
        const bool f = x && (a <= x) && (x <= b) && (mask & (1LL << nth));
        cnt += f;
        if (f) {
          // cout << "> " << b2s(mask) << endl;
          // cout << "> " << b2s((1LL << nth)) << endl;
          // cout << "> " << b2s(x) << endl;          
          // cout << endl;
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
