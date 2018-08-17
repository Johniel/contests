# codeforces/336div2/B

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

int main(int argc, char *argv[])
{
  const int M = 200000 + 100;
  char buff_a[M];
  char buff_b[M];
  while (scanf("%s%s", buff_a, buff_b) == 2) {
    string a(buff_a);
    string b(buff_b);
    lli sum = 0;
    int o = 0;
    int z = 0;
    int j = 0;
    for (int i = 0; i < b.size(); ++i) {
      if (i < a.size()) {
        z += (a[i] == '0');
        o += (a[i] == '1');
      }
      if (b.size() - i < a.size()) {
        z -= (a[j] == '0');
        o -= (a[j] == '1');
        // cout << "j : " << j << endl;
        ++j;
      }
      sum += (b[i] == '1') ? z : o;
      // cout << z << ' ' << o << " : " << sum << endl;
    }
    printf("%lld\n", sum);
  }
  return 0;
}
```
