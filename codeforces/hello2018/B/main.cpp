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

const int N = 1000 + 10;
vector<int> g[N];

bool is_leaf(int x)
{
  return g[x].size() == 0;
}

bool rec(int curr)
{
  if (g[curr].size() == 0) return true;
  int sum = 0;
  each (next, g[curr]) sum += is_leaf(next);
  if (sum < 3) return false;
  each (next, g[curr]) if (!rec(next)) return false;
  return true;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<int>());

    for (int i = 1; i < n; ++i) {
      int j;
      cin >> j;
      --j;
      g[j].push_back(i);
    }

    cout << (rec(0) ? "Yes" : "No") << endl;
  }
  
  return 0;
}
