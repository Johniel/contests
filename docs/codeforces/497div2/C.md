# codeforces/497div2/C

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
    sort(v.begin(), v.end());

    queue<int> a;
    queue<int> b;
    each (i, v) a.push(i);
    each (i, v) b.push(i);

    int cnt = 0;
    while (a.size() && b.size()) {
      if (a.front() < b.front()) {
        ++cnt;
        a.pop();
        b.pop();
      } else {
        b.pop();
      }
    }
    cout << cnt << endl;
  }
  
  return 0;
}
```
