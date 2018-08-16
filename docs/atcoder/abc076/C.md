# atcoder/abc076/C

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
  const string X = "UNRESTORABLE";
  string s, t;
  while (cin >> s >> t) {
    string x = "~";
    for (int i = 0; i < s.size(); ++i) {
      int matched = 0;
      string u = s;
      replace(u.begin(), u.end(), '?', 'a');
      for (int j = 0; j < t.size() && i + j < s.size(); ++j) {
        matched += (s[i + j] == '?' || s[i + j] == t[j]);
        u[i + j] = t[j];
      }
      if (matched == t.size()) {
        x = min(x, u);
      }
    }
    cout << (x == "~" ? X : x) << endl;
  }
  
  return 0;
}
```
