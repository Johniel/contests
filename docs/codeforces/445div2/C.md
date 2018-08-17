# codeforces/445div2/C

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

  int n;
  while (cin >> n) {
    vector<int> v(n);
    each (i, v) cin >> i;
    
    int mx = 0;
    int cnt = 0;
    map<int, int> m;
    int time = 0;

    auto show = [&] () {
      cout << "(";
      each (i, m) cout << i << " ";
      cout << ")" << endl;
      return ;
    };
    
    each (i, v) {
      if (m.count(i)) {
        if (--m[i] == 0) {
          m.erase(i);
        }
      } else {
        ++cnt;
      }
      ++time;
      ++m[time];
      // show();
      mx = max<int>(mx, cnt);
    }
    cout << mx << endl;
  }
  
  return 0;
}
```
