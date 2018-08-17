# codeforces/332div2/B

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
  int size_b;
  int size_f;
  while (scanf("%d%d", &size_f, &size_b) == 2) {
    int f[size_f];
    int b[size_b];
    for (int i = 0; i < size_f; ++i) scanf("%d", f + i);
    for (int i = 0; i < size_b; ++i) scanf("%d", b + i);

    map<int, int> cnt_f;
    map<int, int> cnt_b;
    for (int i = 0; i < size_f; ++i) ++cnt_f[f[i]];
    for (int i = 0; i < size_b; ++i) ++cnt_b[b[i]];

    bool pos = true;
    bool one = true;
    for (int i = 0; i < size_b; ++i) {
      pos = pos && cnt_f.count(b[i]);
      one = one && (cnt_f[b[i]] == 1);
    }
    
    if (!pos) { puts("Impossible"); continue; }
    if (!one) { puts("Ambiguity");  continue; }
    
    map<int, int> fi;
    for (int i = 0; i < size_f; ++i) {
      fi[f[i] - 1] = i;
    }
    puts("Possible");
    for (int i = 0; i < size_b; ++i) {
      if (i) printf(" ");
      printf("%d", fi[b[i] - 1] + 1);
    }
    puts("");
  }
  return 0;
}
```
