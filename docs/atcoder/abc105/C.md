# atcoder/abc105/C

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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ", ";
  os << ")";
  return os;
}

void fn(lli n, int x) {
    vector<int> v(60, 0);
    for (int i = 0; i < v.size(); ++i) {
      if (n & (1LL << i)) v[i] = 1;
    }

    for (int i = 0; i < v.size(); ++i) {
      if (1 < v[i]) {
        v[i + 1] += v[i] / 2;
        v[i] %= 2;
      }
      if (i % 2 == x && v[i]) {
        v[i + 1] += v[i];
      }
    }

    while (1 < v.size() && v.back() == 0) v.pop_back();
    reverse(v.begin(), v.end());
    each (i, v) cout << i; cout << endl;

    return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n;
  while (cin >> n) {
    if (0 <= n) fn(n, 1);
    else fn(abs(n), 0);    
  }
  
  return 0;
}
```
