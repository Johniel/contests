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
    const int H = h;
    const int W = w + 2;
    bool g[H][W];
    for (int i = h - 1; 0 <= i; --i) {
      for (int j = 0; j < W; ++j) {
        char c;
        cin >> c;
        g[i][j] = c - '0';
      }
    }

    const int N = H + 1;
    const int inf = 1 << 28;
    pair<int, int> dp[N];
    fill(dp, dp + N, make_pair(inf, inf));
    dp[0].first = 0;

    vector<int> u[H];
    for (int i = 0; i < h; ++i) {
      { // >^
        int& x = dp[i + 1].second;
        x = min(x, dp[i].first + W);
      }
      { // <^
        int& x = dp[i + 1].first;
        x = min(x, dp[i].second + W);
      }
      vector<int> v;
      for (int j = 0; j < W; ++j) {
        if (g[i][j]) v.push_back(j);
      }
      if (v.size()) {
        // ><^
        int& x = dp[i + 1].first;
        x = min(x, dp[i].first + (v.back()) * 2 + 1);
        // <>^
        int& y = dp[i + 1].second;
        y = min(y, dp[i].second + (W - 1 - v.front()) * 2 + 1);
      } else {
        dp[i + 1].first  = dp[i].first + 1;
        dp[i + 1].second = dp[i].second + 1;
      }
      u[i] = v;
    }

    int mn = inf;
    for (int i = 0; i < h; ++i) {
      if (u[i].size()) {
        mn = inf;
        mn = min(mn, dp[i].first + u[i].back());
        mn = min(mn, dp[i].second + (W - 1 - u[i].front()));
      }
    }

    cout << (mn == inf ? 0 : mn) << endl;
  }
  
  return 0;
}
