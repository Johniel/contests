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

const int N = 1e4 + 10;
vector<int> g[N];

int req[N];
int curr[N];
const int UNDEFINED = -1;

int rec(int curr, int color)
{
  int sum = (color != req[curr]);
  each (next, g[curr]) {
    sum += rec(next, req[curr]);
  }
  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
      int p;
      cin >> p;
      --p;
      g[p].push_back(i + 1);
    }
    for (int i = 0; i < n; ++i) {
      cin >> req[i];
    }
    fill(curr, curr + N, UNDEFINED);
    int cost = rec(0, -2);
    cout << cost << endl;
  }
  
  return 0;
}
