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

const int N = 1e5 + 5;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    map<pair<int, int>, vector<pair<int, int>>> g;
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[make_pair(a, c)].push_back(make_pair(b, c));
      g[make_pair(b, c)].push_back(make_pair(a, c));

      g[make_pair(b, -1)].push_back(make_pair(a, c));
      g[make_pair(a, -1)].push_back(make_pair(b, c));
      g[make_pair(a, c)].push_back(make_pair(b, -1));
      g[make_pair(b, c)].push_back(make_pair(a, -1));
    }

    set<pair<int, int>> vis;
    vis.insert(make_pair(0, -1));

    map<pair<int, int>, int> cost;
    cost[make_pair(0, -1)] = 0;

    deque<pair<int, int>> q;
    for (q.push_back(make_pair(0, -1)); q.size(); ) {
      pair<int, int> p = q.front();
      q.pop_front();
      each (i, g[p]) {
        if (vis.count(i)) continue;
        vis.insert(i);
        if (i.second != -1) {
          cost[i] = cost[p];
          q.push_front(i);
        } else {
          cost[i] = cost[p] + 1;
          q.push_back(i);
        }
      }
    }

    pair<int, int> p = make_pair(n - 1, -1);
    cout << (cost.count(p) ? cost[p] : -1) << endl;
  }

  return 0;
}
