# codeforces/416div2/C

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
    vector<int> a(n);
    each (i, a) cin >> i;

    map<int, int> cnt;
    each (i, a) cnt[i] = count(a.begin(), a.end(), i);
    
    const int N = 5000 + 3;

    int mx[N];
    fill(mx, mx + N, 0);
    for (int i = 0; i < n; ++i) {
      mx[a[i]] = i;
    }
    int mn[N];
    fill(mn, mn + N, 1 << 29);
    for (int i = 0; i < n; ++i) {
      mn[a[i]] = min(mn[a[i]], i);
    }
    
    static int dp[N];
    fill(dp, dp + N, 0);

    for (int i = 0; i < n; ++i) {
      dp[i + 1] = max(dp[i + 1], dp[i]);
      int x = 0;
      if (mn[a[i]] == i) {
        bool vis[N];
        fill(vis, vis + N, false);
        int end = 0;
        for (int j = i; j < n; ++j) {
          if (!vis[a[j]]) {
            if (mn[a[j]] != j) break;
            end = max(end, mx[a[j]]);
            vis[a[j]] = true;
            x ^= a[j];
          }
          int& y = dp[j + 1];
          end = max(end, mx[a[j]]);
          if (end == j) y = max(y, dp[i] + x);
        }
      }
    }

    cout << *max_element(dp, dp + N) << endl;
  }
  
  return 0;
}
```
