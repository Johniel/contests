# codeforces/GoodBye2017/B

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

  int h, w;
  while (cin >> h >> w) {
    pair<int, int> src, dst;
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
        if (g[i][j] == 'S') src = make_pair(i, j);
        if (g[i][j] == 'E') dst = make_pair(i, j);
      }
    }

    string s;
    cin >> s;

    int cnt = 0;
    
    string D = "UDLR";
    sort(D.begin(), D.end());
    do {
      pair<int, int> p = src;
      bool succ = false;
      each (c, s) {
        const int d = c - '0';
        if (D[d] == 'U') --p.first;
        if (D[d] == 'D') ++p.first;
        if (D[d] == 'L') --p.second;
        if (D[d] == 'R') ++p.second;
        unless (0 <= p.first && p.first < h) break;
        unless (0 <= p.second && p.second < w) break;
        if (g[p.first][p.second] == '#') break;
        if (p == dst) succ = true;
      }
      cnt += succ;
    } while (next_permutation(D.begin(), D.end()));
    cout << cnt << endl;
    
  }
  
  return 0;
}
```
