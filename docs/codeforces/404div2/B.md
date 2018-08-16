# codeforces/404div2/B

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

  int n, m;
  while (cin >> n) {
    vector<pair<int, int>> a(n);
    each (i, a) cin >> i.first >> i.second;
    cin >> m;
    vector<pair<int, int>> b(m);
    each (i, b) cin >> i.first >> i.second;

    auto end = [] (pair<int, int> x, pair<int, int> y) {
      return x.first < y.first;
    };
    auto begin = [] (pair<int, int> x, pair<int, int> y) {
      return x.second < y.second;
    };
    sort(a.begin(), a.end(), begin);
    sort(b.begin(), b.end(), end);
    int y = b.back().first - a.front().second;

    // cout << "a: " << endl;
    // each (i, a) cout << i << endl;
    // cout << "b: "  << endl;
    // each (i, b) cout << i << endl;
    
    sort(a.begin(), a.end(), end);
    sort(b.begin(), b.end(), begin);
    int x = a.back().first - b.front().second;

    cout << max({0, x, y}) << endl;
  }
  
  return 0;
}
```
