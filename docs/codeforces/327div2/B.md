# codeforces/327div2/B

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
  int n, m;
  const int C = 'z' + 1;
  char conv[C];
  while (scanf("%d %d\n", &n, &m) == 2) {
    for (char c = 'a'; c <= 'z'; ++c) {
      conv[c] = c;
    }
    const int L = 200000 + 10;
    static char str[L];
    scanf("%s\n", str);
    while (m--) {
      char a, b;
      scanf("%c %c\n", &a, &b);
      int x, y;
      for (char c = 'a'; c <= 'z'; ++c) {
        if (conv[c] == a) x = c;
        if (conv[c] == b) y = c;
      }
      swap(conv[x], conv[y]);
    }
    for (int i = 0; i < n; ++i) {
      printf("%c", conv[(int)str[i]]);
    }
    puts("");
  }
  return 0;
}
```
