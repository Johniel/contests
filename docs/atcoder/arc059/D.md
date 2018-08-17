# atcoder/arc059/D

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
  string s;
  while (cin >> s) {
    pair<int, int> p = make_pair(-1, -1);
    if (s.size() == 2) {
      if (s[0] == s[1]) cout << 1 << ' ' << 2 << endl;
      else cout << -1 << ' ' << -1 << endl;
      continue;
    }
    for (int i = 0; i + 2 < s.size(); ++i) {
      set<char> t;
      t.insert(s[i]);
      t.insert(s[i + 1]);
      t.insert(s[i + 2]);
      if (t.size() <= 2) {
        p = make_pair(i + 1, i + 3);
      }
    }
    cout << p.first << ' ' << p.second << endl;
  }
  return 0;
}
```
