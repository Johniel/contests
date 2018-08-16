# codeforces/355div2/C

## Codes
```cpp
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

int char2int(char c)
{
  if ('0' <= c && c <= '9') return c - '0';
  if ('A' <= c && c <= 'Z') return c - 'A' + 10;
  if ('a' <= c && c <= 'z') return c - 'a' + 36;
  if (c == '-') return 62;
  return 63;
}

string int2bit(int n)
{
  string s;
  while (s.size() < 6) {
    s += '0' + (n & 1);
    n /= 2;
  }
  return s;
}

int main(int argc, char *argv[])
{
  const int N = 100000 + 10;
  char buff[N];
  while (scanf("%s", buff) == 1) {
    string s(buff);
    string t;
    each (c, s) t += int2bit(char2int(c));
    const int z = count(t.begin(), t.end(), '0');
    // cout << t << endl;
    const lli mod = 1000000000 + 7;
    lli n = 1;
    for (int i = 0; i < z; ++i) {
      n = n * 3 % mod;
    }
    // n = (n * 2  - 1 + mod) % mod;
    printf("%lld\n", n);
  }
  return 0;
}
```
