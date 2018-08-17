# atcoder/agc021/A

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

int fn(string s)
{
  int sum = 0;
  each (c, s) sum += c - '0';
  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    int mx = fn(s);
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '0') continue;
      string t = s;
      t[i] = t[i] - 1;
      fill(t.begin() + i + 1, t.end(), '9');
      mx = max(mx, fn(t));
    }
    cout << mx << endl;
  }
  
  return 0;
}
```
