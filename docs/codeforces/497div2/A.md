# codeforces/497div2/A

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
    bool flg = true;
    set<char> v({'a', 'i', 'u', 'e', 'o'});
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'n') continue;
      if (v.count(s[i]) == 0) {
        // cout << s[i] << ' ' << s[i + 1] << ' ' << flg << endl;
        flg = flg && (i + 1 < s.size()) && v.count(s[i + 1]);
      }
    }
    cout << (flg ? "YES" : "NO") << endl;
  }
  
  return 0;
}
```
