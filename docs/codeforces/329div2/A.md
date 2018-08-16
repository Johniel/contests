# codeforces/329div2/A

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
  int n;
  while (scanf("%d\n", &n) == 1) {
    const int L = 1000 + 10;
    char buff[L];
    map<char, int> cnt[n];
    int len[n];
    for (int i = 0; i < n; ++i) {
      scanf("%s\n", buff);
      // puts(buff);
      len[i] = strlen(buff);      
      for (int j = 0; j < len[i]; ++j) {
        ++cnt[i][buff[j]];
      }
    }
    int mx = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      int sum = 0;
      for (int i = 0; i < n; ++i) {
        if (cnt[i][c] == len[i]) {
          sum += len[i];
        }
      }
      mx = max(mx, sum);
    }
    
    for (char c = 'a'; c <= 'z'; ++c) {
      for (char d = 'a'; d <= 'z'; ++d) {
        if (c == d) continue;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
          if (cnt[i][c] + cnt[i][d] == len[i]) {
            sum += len[i];
          }
        }
        mx = max(mx, sum);
      }
    }

    printf("%d\n", mx);
  }
  return 0;
}
```
