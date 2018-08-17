# codeforces/323div2/C

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
  while (cin >> n) {
    const int m = n * n;
    multiset<int, greater<int>> s;
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      s.insert(x);
    }

    vector<int> v;
    while (s.size()) {
      const int x = *s.begin();
      s.erase(s.begin());
      each (y, v) {
        auto itr1 = s.find(__gcd(x, y));
        if (itr1 == s.end()) continue;
        auto itr2 = itr1;
        advance(itr2, 1);
        s.erase(itr2);
        s.erase(itr1);
      }
      v.push_back(x);
    }

    for (int i = 0; i < v.size(); ++i) {
      if (i) cout << ' ';
      cout << v[i];
    }
    cout << endl;
  }
  
  return 0;
}
```
