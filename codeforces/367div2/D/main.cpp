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


string f(lli n)
{
  if (n == 0) return "0";
  string s;
  while (n) {
    s += '0' + (n & 1);
    n /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}


int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d\n", &n) == 1) {
    map<lli, int> cnt;
    cnt[0] = 1;
    while (n--) {
      char c;
      lli x;
      scanf("%c %lld\n", &c, &x);
      if (c == '+') {
        ++cnt[x];
      }
      if (c == '-') {
        --cnt[x];
        if (cnt[x] == 0) cnt.erase(x);
      }
      if (c == '?') {
        auto fn = [&] (lli bit, lli mask) {
          auto itr = cnt.lower_bound(bit);
          return itr != cnt.end() && (itr->first & mask) == bit;
        };

        lli mask = 0;
        lli y = 0;
        for (int i = 40; i >= 0; --i) {
          const lli b = (1LL << i);
          mask |= b;
          const lli z = y | b;          
          if (fn(y, mask) && fn(z, mask)) {
            y = (x ^ y) < (x ^ z) ? z : y;
          } else if (fn(z, mask)) {
            y = z;
          } else {
          }
        }
        printf("%lld\n", max(x ^ y, x));
      }
    }
  }
  return 0;
}
