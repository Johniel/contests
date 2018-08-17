# codeforces/418div2/B

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

bool valid(vector<int> a, vector<int> b, vector<int> c)
{
  int x = 0;
  int y = 0;
  for (int i = 0; i < c.size(); ++i) {
    x += (a[i] != c[i]);
    y += (b[i] != c[i]);
  }
  return x == 1 && y == 1 && set<int>(c.begin(), c.end()).size() == c.size();
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> a(n);
    vector<int> b(n);
    each (i, a) cin >> i;
    each (i, b) cin >> i;

    vector<int> c = a;

    map<int, int> cnt_a;
    map<int, int> cnt_b;

    each (i, a) ++cnt_a[i];
    each (i, b) ++cnt_b[i];

    for (int i = 0; i < n; ++i) {
      if (cnt_a[a[i]] == 2) {
        for (int j = 1; j <= n; ++j) {
          c[i] = j;
          if (valid(a, b, c)) {
            i = 1 << 28;
            break;
          }
          c[i] = a[i];
        }
      }
    }

    each (i, c) cout << i << ' ' ; cout << endl;
    assert(valid(a, b, c));
  }
  
  return 0;
}
```
