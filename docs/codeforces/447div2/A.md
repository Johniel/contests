# codeforces/447div2/A

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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = i + 1; j < s.size(); ++j) {
        for (int k = j + 1; k < s.size(); ++k) {
          cnt += (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q');
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
```
