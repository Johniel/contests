# codeforces/468div2/B

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

  int n, a, b;
  while (cin >> n >> a >> b) {
    unless (a < b) swap(a, b);
    
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(i + 1);
    }
    int x = 0;
    bool flg = true;
    while (flg) {
      // each (i, v) cout << i << ' ' ; cout << endl;
      
      ++x;
      vector<int> u;
      for (int i = 0; i < v.size(); i += 2) {
        if (v[i] == a && v[i + 1] == b) {
          flg = false;
        }
        if (0) ;
        else if (v[i] == a || v[i + 1] == a) u.push_back(a);
        else if (v[i] == b || v[i + 1] == b) u.push_back(b);
        else u.push_back(v[i]);
      }
      v = u;
    }
    if (v.size() < 2) cout << "Final!" << endl;
    else cout << x << endl;
  }
  
  return 0;
}
```
