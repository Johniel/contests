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
  int n, x;
  while (cin >> n >> x) {
    vector<pair<int, int>> g[n];
    for (int i = 0; i < n - 1; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back(make_pair(b, c));
      g[b].push_back(make_pair(a, c));
    }

    int cost[n];
    fill(cost, cost + n, -1);
    function<void(int, int)> rec = [&] (int curr, int acc) {
      cost[curr] = acc;
      each (e, g[curr]) {
        if (cost[e.first] == -1) rec(e.first, acc ^ e.second);
      }
      return ;
    };
    rec(0, 0);

    map<int, int> m;
    for (int i = 0; i < n; ++i) {
      ++m[cost[i]];
    }

    lli sum = 0;
    for (int i = 0; i < n; ++i) {
      const int y = (cost[i] ^ x);
      if (m.count(y)) sum += m[y] - (cost[i] == y);
    }
    cout << sum / 2 << endl;
  }
  return 0;
}
