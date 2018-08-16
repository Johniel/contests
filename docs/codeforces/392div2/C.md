# codeforces/392div2/C

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

  int h, w, x, y;
  lli k;
  while (cin >> h >> w >> k >> x >> y) {
    vector<pair<int, int>> v;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        v.push_back(make_pair(i, j));
      }
    }
    for (int i = h - 2; 0 < i; --i) {
      for (int j = 0; j < w; ++j) {
        v.push_back(make_pair(i, j));
      }
    }

    lli cnt[h][w];
    fill(&cnt[0][0], &cnt[h - 1][w - 1] + 1, k / v.size());
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (i == 0 || i == h - 1) continue;
        cnt[i][j] *= 2;
      }
    }
    
    for (int i = 0; i < k % (lli)v.size(); ++i) {
      int j = i % v.size();
      ++cnt[v[j].first][v[j].second];
    }
    lli mn = *min_element(&cnt[0][0], &cnt[h - 1][w - 1] + 1);
    lli mx = *max_element(&cnt[0][0], &cnt[h - 1][w - 1] + 1);
    cout << mx << ' ' << mn << ' ' << cnt[x - 1][y - 1] << endl;
  }
  
  return 0;
}
```
