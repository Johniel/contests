# codeforces/422div2/B

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

  int x, y;
  string s, t;
  while (cin >> x >> y >> s >> t) {
    vector<int> v(t.size() + 1);

    for (int i = 0; i + s.size() <= t.size(); ++i) {
      vector<int> u;
      for (int j = 0; j < s.size(); ++j) {
        if (t[i + j] != s[j]) {
          u.push_back(j);
        }
      }
      if (u.size() < v.size()) {
        v = u;
      }
    }
    cout << v.size() << endl;
    each (i, v) cout << i + 1 << ' '; cout << endl;
  }

  return 0;
}
```
