# codeforces/419div2/A

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

  int h, m;
  char c;
  while (cin >> h >> c >> m) {
    int cnt = 0;
    while (true) {
      char buff[100];
      sprintf(buff, "%02d:%02d", h, m);
      string s(buff);
      string t = s;
      reverse(t.begin(), t.end());
      if (s == t) break;
      ++m;
      h = (h + m / 60) % 24;
      m %= 60;
      ++cnt;
    }
    cout << cnt << endl;
  }
  
  return 0;
}
```
