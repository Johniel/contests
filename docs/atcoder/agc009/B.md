# atcoder/agc009/B

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

const int N = 100000 + 10;
int a[N];
vector<int> g[N];

int rec(int curr)
{
  vector<int> v;
  each (next, g[curr]) {
    // cout << curr+1 << " -> " << next+1 << endl;
    v.push_back(rec(next) + 1);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int mx = -1;
  for (int i = 0; i < v.size(); ++i) {
    mx = max(mx, v[i] + i);
  }
  // cout << curr+1 << ": " ; each (i, v) cout << i+1 << ' '; cout << endl;
  return v.size() ? mx : 0;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<int>());
    for (int i = 1; i < n; ++i) {
      int a;
      cin >> a;
      // cout << make_pair(a - 1 + 1, i + 1) << endl;
      g[a - 1].push_back(i);
    }
    cout << rec(0) << endl;
    // cout << endl;
  }
  
  return 0;
}
```
