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
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

const int N = 1000 + 10;

vector<int> g[N];
vector<int> x;

int rec(int curr)
{
  if (g[curr].empty()) return 0;

  const int M = 5000 + 10;
  static bool dp[2][M];

  int sum = 0;
  vector<pair<int, int>> v;
  each (next, g[curr]) {
    int y = rec(next);
    sum += x[next] + y;
    v.push_back(make_pair(x[next], y));
  }

  fill(&dp[0][0], &dp[2 - 1][M - 1] + 1, false);
  int a = 0;
  int b = 1;
  dp[a][0] = true;
  each (i, v) {
    for (int j = 0; j < M; ++j) {
      dp[b][j] = false;
    }
    for (int j = 0; j < M; ++j) {
      if (j + i.first < M) dp[b][j + i.first] |= dp[a][j];
      if (j + i.second < M) dp[b][j + i.second] |= dp[a][j];
    }
    a = (a +  1) % 2;
    b = (b +  1) % 2;
  }

  int y = -1;
  for (int i = 0; i <= x[curr]; ++i) {
    if (dp[a][i]) {
      y = sum - i;
    }
  }
  if (y == -1) throw "";
  
  return y;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    x.resize(n);
    vector<int> p(n - 1);
    each (i, p) cin >> i;
    each (i, x) cin >> i;

    fill(g, g + N, vector<int>());
    each (i, p) --i;
    for (int i = 0; i < p.size(); ++i) {
      g[p[i]].push_back(i + 1);
    }

    try {
      rec(0);
      cout << "POSSIBLE" << endl;
    } catch (const char* e) {
      cout << "IMPOSSIBLE" << endl;
    }
  }

  return 0;
}
